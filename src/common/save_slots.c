#include "save_slots.h"
#include "mod/contents.h"
#include "mod/runtime.h"
#include "mod/types.h"
#if defined(TARGET_SDL)
#include "engine_settings.h"
#include "file.h"
#include "savegame.h"
#include "npc.h"
#include "talk.h"
#include "mod/maps.h"
#include "graphics/grap_sdl.h"
#include "graphics/grap_buf.h"
#include "key/mouse.h"
#include "vars.h"
#include "funcs.h"
#include "audio/audio.h"
#include <SDL3/SDL.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static char s_saveDir[FILE_PATH_SIZE],s_root[FILE_PATH_SIZE];
#define ROOT s_root
static bool storage(void)
{
    if(FILE_ResolvePath("SAVEGAME",s_saveDir,sizeof(s_saveDir),0)!=0) return false;
    if(SDL_snprintf(s_root,sizeof(s_root),"%s/slots",s_saveDir)>=(int)sizeof(s_root)) return false;
    char resolved[FILE_PATH_SIZE];
    if(FILE_ResolvePath(s_root,resolved,sizeof(resolved),0)==0) SDL_strlcpy(s_root,resolved,sizeof(s_root));
    if(strlen(s_root)>400) return false; /* Leave room for slot and staging suffixes. */
    return SDL_CreateDirectory(s_root);
}
#define NAME_LENGTH 26
static uint64_t s_accumulated,s_started;
static bool s_running, s_legacyEnabled;
void SLOTS_SetLegacyEnabled(bool enabled) { s_legacyEnabled=enabled; }
static const char* files[]={"SAVED.GAM","SAVED.OOL","meta.txt","thumbnail.bmp"};
static uint64_t legacyTime(void)
{
    unsigned long long value=0;FILE* f=FILE_Open("SAVEGAME/PLAYTIME","r");
    if(f) { if(fscanf(f,"%llu",&value)!=1) value=0;fclose(f); }
    return value;
}
uint64_t SLOTS_PlayMilliseconds(void)
{ return s_accumulated+(s_running?SDL_GetTicks()-s_started:0); }
void SLOTS_ResetTime(void)
{
    s_accumulated=0;s_running=false;
    FILE* f=FILE_Open("SAVEGAME/PLAYTIME","w");if(f) { fputs("0\n",f);fclose(f); }
}
void SLOTS_StartTime(void)
{ s_accumulated=legacyTime();s_started=SDL_GetTicks();s_running=true; }
static bool validId(const char* id)
{
    if(!id || !*id || strlen(id)>40) return false;
    for(;*id;id++) if(*id<'0' || *id>'9') return false;
    return true;
}
static void path(char* out,size_t size,const char* dir,const char* file)
{ SDL_snprintf(out,size,"%s/%s",dir,file); }
static bool copy(const char* from,const char* to,size_t expected)
{
    FILE* a=FILE_Open(from,"rb");if(!a) return false;
    FILE* b=FILE_Open(to,"wb");if(!b) { fclose(a);return false; }
    char buffer[4096];size_t n,total=0;bool ok=true;
    while((n=fread(buffer,1,sizeof(buffer),a))) {
        total+=n;if(fwrite(buffer,1,n,b)!=n) { ok=false;break; }
    }
    if(ferror(a) || (expected && total!=expected)) ok=false;
    fclose(a);if(fclose(b)!=0) ok=false;return ok;
}
static void removeDir(const char* dir)
{
    char p[512];for(int i=0;i<4;i++) { path(p,sizeof(p),dir,files[i]);SDL_RemovePath(p); }
    SDL_RemovePath(dir);
}
static bool SLOTS_Delete_Impl(const char* id)
{
    if(!validId(id) || !storage()) return false;
    char dir[512],p[512];SDL_snprintf(dir,sizeof(dir),"%s/%s",ROOT,id);
    SDL_PathInfo info;if(!SDL_GetPathInfo(dir,&info)) return false;
    for(int i=0;i<4;i++) {
        path(p,sizeof(p),dir,files[i]);
        if(SDL_GetPathInfo(p,&info) && !SDL_RemovePath(p)) return false;
    }
    return SDL_RemovePath(dir);
}
void SLOTS_LocationName(unsigned int map,unsigned int level,char* out,size_t capacity)
{
    const char* raw="Unknown Location";
    if(map==0) raw=level==0?"Britannia":"Underworld";
    else if(map==0x11) raw="Lord British's Castle";
    else if(map==0x12) raw="Blackthorn's Palace";
    else if(map>=1 && map<=40 && D_1e3a[map-1]) raw=D_1e3a[map-1];
    const char *custom = MOD_LocationName(map == 0 && level != 0 ? 41 : map, NULL);
    if (custom) {
        SDL_snprintf(out, capacity, map >= 33 && map <= 40 ? "Dungeon %s" : "%s", custom);
        return;
    }
    char name[64];SDL_strlcpy(name,raw,sizeof(name));
    bool word=true;
    for(char* p=name;*p;p++) {
        if(*p>='A' && *p<='Z' && !word) *p+=32;
        word=*p==' ' || *p=='-';
    }
    SDL_snprintf(out,capacity,map>=33 && map<=40?"Dungeon %s":"%s",name);
}
static bool metadata(const char* dir,char* name,uint64_t* ms,char* location,size_t locationSize)
{
    char p[512];path(p,sizeof(p),dir,"meta.txt");FILE* f=FILE_Open(p,"r");if(!f) return false;
    unsigned long long value;bool ok=fgets(name,NAME_LENGTH+2,f)!=NULL;
    if(ok) name[strcspn(name,"\r\n")]=0;
    ok=ok && *name && fscanf(f,"%llu",&value)==1;
    if(location) {
        unsigned int map,level,x,y;
        SDL_strlcpy(location,"Unknown Location",locationSize);
        if(ok && fscanf(f," location %u %u %u %u",&map,&level,&x,&y)==4 && map<=255 && level<=255 && x<=255 && y<=255)
            SLOTS_LocationName(map,level,location,locationSize);
    }
    fclose(f);
    if(ok) *ms=value;return ok;
}
static bool writeSlot(const char* id,const char* name,const char* thumbnail,const byte* initialWorlds)
{
    if(!name || !*name || strlen(name)>NAME_LENGTH) return false;
    for(const char* p=name;*p;p++) if((unsigned char)*p<32 || (unsigned char)*p>126) return false;
    if(id && !validId(id)) return false;
    if(!storage()) return false;
    char generated[40];
    if(!id) { SDL_Time now;
        if(!SDL_GetCurrentTime(&now)) return false;
        char candidate[512];SDL_PathInfo info;
        do {
            SDL_snprintf(generated,sizeof(generated),"%020llu",(unsigned long long)now++);
            SDL_snprintf(candidate,sizeof(candidate),"%s/%s",ROOT,generated);
        } while(SDL_GetPathInfo(candidate,&info));
        id=generated; }
    char dir[512],stage[512],backup[512],p[512];
    SDL_snprintf(dir,sizeof(dir),"%s/%s",ROOT,id);
    SDL_snprintf(stage,sizeof(stage),"%s/.%s.pending",ROOT,id);
    SDL_snprintf(backup,sizeof(backup),"%s/.%s.previous",ROOT,id);
    if(!SDL_CreateDirectory(stage)) return false;
    path(p,sizeof(p),stage,"SAVED.GAM");
    bool ok=FILE_WriteSavegameFile(p)==0;
    path(p,sizeof(p),stage,"SAVED.OOL");FILE* objects=FILE_Open(p,"wb");
    if(!objects) ok=false;
    else {
        const char* worlds[]={"SAVEGAME/BRIT.OOL","SAVEGAME/UNDER.OOL"};
        for(int i=0;i<2;i++) {
            byte data[256];
            if(initialWorlds) memcpy(data,initialWorlds+i*256,256);
            else {
                FILE* f=FILE_Open(worlds[i],"rb");if(!f) { ok=false;break; }
                bool read=fread(data,1,256,f)==256;fclose(f);
                if(!read) { ok=false;break; }
            }
            if(fwrite(data,1,256,objects)!=256) { ok=false;break; }
        }
        if(fclose(objects)!=0) ok=false;
    }
    uint64_t ms=SLOTS_PlayMilliseconds();
    path(p,sizeof(p),stage,"meta.txt");FILE* f=FILE_Open(p,"w");
    if(!f) ok=false;
    else { if(fprintf(f,"%s\n%llu\nlocation %u %u %u %u\n",name,(unsigned long long)ms,(unsigned int)D_5893_map_id,(unsigned int)D_5895_map_level,(unsigned int)D_5896_map_x,(unsigned int)D_5897_map_y)<0) ok=false;if(fclose(f)!=0) ok=false; }
    path(p,sizeof(p),stage,"thumbnail.bmp");
    if(thumbnail && !copy(thumbnail,p,0)) ok=false;
    if(!ok) { removeDir(stage);return false; }
    SDL_PathInfo info;bool exists=SDL_GetPathInfo(dir,&info);
    if(exists && !SDL_RenamePath(dir,backup)) { removeDir(stage);return false; }
    if(!SDL_RenamePath(stage,dir)) {
        if(exists) SDL_RenamePath(backup,dir);
        removeDir(stage);return false;
    }
    if(exists) removeDir(backup);
    return true;
}
bool SLOTS_Write(const char* id,const char* name,const char* thumbnail)
{
    debug("Save write requested slot=%s map=%u level=%u position=%u,%u thumbnail=%d",id?id:"new",D_5893_map_id,D_5895_map_level,D_5896_map_x,D_5897_map_y,thumbnail!=NULL);
    bool ok=writeSlot(id,name,thumbnail,NULL);
    if(ok) debug("Save write committed");else DEBUG_Error("Save write failed; last SDL error: %s",SDL_GetError());
    return ok;
}
bool SLOTS_CreateInitial(void)
{
    /* Always resolve new-game templates afresh; never seed from old saves. */
    if(!storage() || !MOD_InitializeWorldObjects(D_b21e)) return false;
    /* A world start must serialize the same objects in SAVED.GAM's resident
     * list and SAVED.OOL's world list. */
    if(D_5893_map_id == 0)
        memcpy(D_5c5a, D_b21e + (D_5895_map_level ? 256 : 0), 256);
    TYPES_Reset();
    if(!NPC_InitializeNewGame()) return false;
    SLOTS_ResetTime();
    char name[sizeof(D_55a8_party[0].name)+1];
    memcpy(name,D_55a8_party[0].name,sizeof(D_55a8_party[0].name));name[sizeof(name)-1]=0;
    bool ok=writeSlot(NULL,*name?name:"Avatar",NULL,D_b21e);
    debug("Initial character slot created=%d",ok);return ok;
}
static bool SLOTS_Load_Impl(const char* id)
{
    if(!validId(id) || !storage()) return false;
    char dir[512],p[512],name[NAME_LENGTH+2];uint64_t ms;
    SDL_snprintf(dir,sizeof(dir),"%s/%s",ROOT,id);
    if(!metadata(dir,name,&ms,NULL,0)) return false;
    /* Validate both files before replacing the working save. */
    for(int i=0;i<2;i++) {
        path(p,sizeof(p),dir,files[i]);FILE* f=FILE_Open(p,"rb");if(!f) return false;
        bool ok = fseek(f, 0, SEEK_END) == 0 &&
                  (i ? ftell(f) == 512
                     : (ftell(f) >= 0x1060 && fseek(f, 0x1060, SEEK_SET) == 0 &&
                        MAPS_ReadState(f, 0) && NPC_ReadExtraState(f, 0) &&
                        TALK_ReadKnowledge(f, 0) && CONTENTS_ReadState(f, 0)));
        fclose(f);
        if (!ok)
            return false;
    }
    /* Stage the complete working save, including its clock, before installation. */
    const char* working[]={"SAVED.GAM","SAVED.OOL","PLAYTIME"};
    char targets[3][FILE_PATH_SIZE],stages[3][FILE_PATH_SIZE],backups[3][FILE_PATH_SIZE];
    bool existed[3]={0};
    for(int i=0;i<3;i++) {
        char target[FILE_PATH_SIZE];path(target,sizeof(target),s_saveDir,working[i]);
        if(FILE_ResolvePath(target,targets[i],sizeof(targets[i]),1)!=0) return false;
        SDL_snprintf(stages[i],sizeof(stages[i]),"%s.pending",targets[i]);
        SDL_snprintf(backups[i],sizeof(backups[i]),"%s.previous",targets[i]);
        if(i<2) {
            path(p,sizeof(p),dir,working[i]);
            if (!copy(p, stages[i], i ? 512 : 0))
                return false;
        } else {
            FILE* f=FILE_Open(stages[i],"w");if(!f) return false;
            bool ok=fprintf(f,"%llu\n",(unsigned long long)ms)>=0;
            if(fclose(f)!=0) ok=false;if(!ok) return false;
        }
    }
    int installed=0;
    for(int i=0;i<3;i++) {
        SDL_PathInfo info;existed[i]=SDL_GetPathInfo(targets[i],&info);
        SDL_RemovePath(backups[i]);
        if(existed[i] && !SDL_RenamePath(targets[i],backups[i])) break;
        if(!SDL_RenamePath(stages[i],targets[i])) {
            if(existed[i]) SDL_RenamePath(backups[i],targets[i]);break;
        }
        installed++;
    }
    if(installed!=3) {
        for(int i=0;i<installed;i++) {
            SDL_RemovePath(targets[i]);if(existed[i]) SDL_RenamePath(backups[i],targets[i]);
        }
        for(int i=0;i<3;i++) SDL_RemovePath(stages[i]);
        return false;
    }
    for(int i=0;i<3;i++) SDL_RemovePath(backups[i]);
    return true;
}

typedef struct { char id[41],name[NAME_LENGTH+2],location[40];uint64_t ms; } Slot;
static Slot* s_slots;static int s_count;static bool s_scanFailed;
static SDL_EnumerationResult enumerate(void* unused,const char* dir,const char* filename)
{
    (void)unused;
    if(!validId(filename)) return SDL_ENUM_CONTINUE;
    char full[512];path(full,sizeof(full),dir,filename);Slot slot={0};
    if(!metadata(full,slot.name,&slot.ms,slot.location,sizeof(slot.location))) { debug("Skipping save slot=%s: missing or invalid metadata",filename);return SDL_ENUM_CONTINUE; }
    SDL_strlcpy(slot.id,filename,sizeof(slot.id));
    Slot* next=realloc(s_slots,(size_t)(s_count+1)*sizeof(Slot));
    if(!next) { DEBUG_Error("Cannot allocate save list for %d slots",s_count+1);s_scanFailed=true;return SDL_ENUM_FAILURE; }
    s_slots=next;s_slots[s_count++]=slot;return SDL_ENUM_CONTINUE;
}
static int compare(const void* a,const void* b)
{ return strcmp(((const Slot*)b)->id,((const Slot*)a)->id); }
static void timeText(char* out,size_t n,uint64_t ms)
{ SDL_snprintf(out,n,"%lluh %02llum %02llus",(unsigned long long)(ms/3600000),(unsigned long long)(ms/60000%60),(unsigned long long)(ms/1000%60)); }
static bool s_inGame, s_hasFirstRow;
static int listY(void) { return s_hasFirstRow?56:39; }
static void draw(bool saving,int selected,int top,const char* status)
{
    memset(g_linearEgaBuffer0,0,320*200);ENGINE_UIFrame();
    ENGINE_UIText(124,12,saving?"Save Game":"Load Game",15);
    ENGINE_UIText(16,26,status?status:"Esc: Back    Del: Delete",7);
    if(s_hasFirstRow) {
        ENGINE_UIRect(16,39,280,12,selected==0?15:0);
        ENGINE_UIText(24,41,saving?"New Save":"Legacy Save",selected==0?0:15);
    }
    GRAP_SDL_ClearUIThumbnails();
    for(int row=0;row<4 && top+row<s_count;row++) {
        int index=top+row,y=listY()+row*30;Slot* slot=&s_slots[index];
        bool active=selected==index+1;
        if(active) ENGINE_UIRect(16,y,280,28,15);
        ENGINE_UIText(20,y+1,slot->name,active?0:15);
        ENGINE_UIText(20,y+10,slot->location,active?0:7);
        char duration[40];timeText(duration,sizeof(duration),slot->ms);
        ENGINE_UIText(20,y+19,duration,active?0:7);
        char image[512];SDL_snprintf(image,sizeof(image),"%s/%s/thumbnail.bmp",ROOT,slot->id);
        GRAP_SDL_UIThumbnail(row,image,248,y+2,44,24);
    }
    if(s_count>4) {
        ENGINE_UIRect(300,listY(),4,118,7);
        int height=SDL_max(8,118*4/s_count),y=listY()+(118-height)*top/(s_count-4);
        ENGINE_UIRect(299,y,6,height,15);
    }
    if(selected==s_count+1) ENGINE_UIRect(16,179,280,10,15);
    ENGINE_UIText(24,180,s_inGame?"Return to Game":"Return to Menu",selected==s_count+1?0:15);
    GRAP_BUF_MarkDirty();GRAP_BUF_Present();
}
static bool prompt(char* name,bool overwrite)
{
    SDL_Window* window=SDL_GetKeyboardFocus();
    SDL_Window** windows=NULL;int count=0;
    if(!window) { windows=SDL_GetWindows(&count);if(count) window=windows[0]; }
    SDL_free(windows);
    if(window) SDL_StartTextInput(window);
    bool done=false,accepted=false;
    while(!done) {
        /* Replace the whole list area, including partial rows and scrollbar. */
        ENGINE_UIRect(16,39,290,137,0);
        ENGINE_UIRect(16,68,288,60,1);
        ENGINE_UIRect(19,71,282,54,15);
        ENGINE_UIRect(20,72,280,52,0);
        ENGINE_UIText(24,76,overwrite?"Overwrite this save?":"Name your save:",15);
        ENGINE_UIText(24,92,name,15);ENGINE_UIText(24,112,"Enter: Save   Esc: Cancel",7);
        GRAP_BUF_MarkDirty();GRAP_BUF_Present();
        SDL_Event e;
        while(SDL_PollEvent(&e)) {
            if(e.type==SDL_EVENT_QUIT || (e.type==SDL_EVENT_KEY_DOWN && e.key.key==SDLK_E && (e.key.mod&SDL_KMOD_CTRL))) exit(0);
            if(e.type==SDL_EVENT_TEXT_INPUT && !overwrite)
                for(const unsigned char* p=(const unsigned char*)e.text.text;*p;p++)
                    if(*p>=32 && *p<=126 && strlen(name)<NAME_LENGTH) {
                        size_t n=strlen(name);name[n]=*p;name[n+1]=0;
                    }
            if(e.type==SDL_EVENT_KEY_DOWN) {
                if(e.key.key==SDLK_ESCAPE) done=true;
                if(e.key.key==SDLK_BACKSPACE && *name && !overwrite) name[strlen(name)-1]=0;
                if(e.key.key==SDLK_RETURN && *name && strspn(name," ")!=strlen(name)) { accepted=true;done=true; }
            }
        }
        SDL_Delay(16);
    }
    if(window) SDL_StopTextInput(window);return accepted;
}
static bool confirmDelete(const char* name)
{
    GRAP_SDL_ClearUIThumbnails();
    while(true) {
        ENGINE_UIRect(16,39,290,137,0);
        ENGINE_UIRect(16,68,288,68,1);ENGINE_UIRect(19,71,282,62,15);
        ENGINE_UIRect(20,72,280,60,0);
        ENGINE_UIText(24,76,"Are you sure?",15);
        ENGINE_UIText(24,92,name,15);
        ENGINE_UIText(24,116,"Y: Delete    N/Esc: Cancel",7);
        GRAP_BUF_MarkDirty();GRAP_BUF_Present();
        SDL_Event e;
        while(SDL_PollEvent(&e)) {
            if(e.type==SDL_EVENT_QUIT || (e.type==SDL_EVENT_KEY_DOWN && e.key.key==SDLK_E && (e.key.mod&SDL_KMOD_CTRL))) exit(0);
            if(e.type==SDL_EVENT_KEY_DOWN && !e.key.repeat) {
                if(e.key.key==SDLK_Y) return true;
                if(e.key.key==SDLK_N || e.key.key==SDLK_ESCAPE) return false;
            }
            if(e.type==SDL_EVENT_MOUSE_BUTTON_DOWN && e.button.button==SDL_BUTTON_LEFT) {
                float x,y;
                if(GRAP_SDL_MouseUIPoint(e.button.x,e.button.y,&x,&y) && y>=112 && y<128) {
                    if(x>=24 && x<96) return true;
                    if(x>=128 && x<224) return false;
                }
            }
        }
        MOUSE_UpdateCursor();SDL_Delay(16);
    }
}
static bool validLegacy(void)
{
    for(int i=0;i<2;i++) {
        char filename[FILE_PATH_SIZE];path(filename,sizeof(filename),s_saveDir,files[i]);
        FILE* f=FILE_Open(filename,"rb");if(!f) return false;
        bool ok = fseek(f, 0, SEEK_END) == 0 &&
                  (i ? ftell(f) == 512
                     : (ftell(f) >= 0x1060 && fseek(f, 0x1060, SEEK_SET) == 0 &&
                        MAPS_ReadState(f, 0) && NPC_ReadExtraState(f, 0) &&
                        TALK_ReadKnowledge(f, 0) && CONTENTS_ReadState(f, 0)));
        fclose(f);if(!ok) return false;
    }
    return true;
}
static bool show(bool saving,bool inGame)
{
    debug("Save browser open mode=%s inGame=%d legacy=%d",saving?"save":"load",inGame,s_legacyEnabled);
    s_inGame=inGame;
    extern void KEY_SDL_ClearInput(void);
    free(s_slots);s_slots=NULL;s_count=0;s_scanFailed=false;
    if(!storage()) return false;
    if(!SDL_EnumerateDirectory(ROOT,enumerate,NULL)) s_scanFailed=true;
    if(s_count>1) qsort(s_slots,s_count,sizeof(Slot),compare);
    byte backup[320*200];memcpy(backup,g_linearEgaBuffer0,sizeof(backup));
    SDL_Surface* shot=saving?GRAP_SDL_CaptureFrame():NULL;
    char capture[FILE_PATH_SIZE];path(capture,sizeof(capture),s_saveDir,".slot-thumbnail.bmp");
    SDL_Surface* thumbnail=shot?SDL_ScaleSurface(shot,160,SDL_max(1,160*shot->h/shot->w),SDL_SCALEMODE_LINEAR):NULL;
    bool captured=thumbnail && SDL_SaveBMP(thumbnail,capture);
    debug("Save browser slots=%d scanFailed=%d thumbnail=%d",s_count,s_scanFailed,captured);
    SDL_DestroySurface(thumbnail);SDL_DestroySurface(shot);
    KEY_SDL_ClearInput();MOUSE_Cancel();GRAP_SDL_SetPixelUI(true);MOUSE_SetPointerMode(true);
    s_hasFirstRow=saving || (s_legacyEnabled && validLegacy());
    int first=s_hasFirstRow?0:1;
    int selected=first,top=0;float wheelRemainder=0,dragOffset=0;bool done=false,result=false,drag=false;
    const char* status=s_scanFailed?"Unable to list all saves":NULL;
    draw(saving,selected,top,status);
    while(!done) {
        SDL_Event e;
        while(SDL_PollEvent(&e)) {
            bool activate=false;
            if(e.type==SDL_EVENT_QUIT || (e.type==SDL_EVENT_KEY_DOWN && e.key.key==SDLK_E && (e.key.mod&SDL_KMOD_CTRL))) exit(0);
            if(e.type==SDL_EVENT_KEY_DOWN) {
                switch(e.key.key) {
                case SDLK_DELETE:
                    if(!e.key.repeat && selected>0 && selected<=s_count) {
                        drag=false;SDL_CaptureMouse(false);
                        if(confirmDelete(s_slots[selected-1].name)) {
                            if(SLOTS_Delete(s_slots[selected-1].id)) {
                                memmove(&s_slots[selected-1],&s_slots[selected],(size_t)(s_count-selected)*sizeof(Slot));
                                s_count--;selected=SDL_min(selected,s_count+1);
                                top=SDL_min(top,SDL_max(0,s_count-4));status=NULL;
                            } else status="Could not delete save.";
                        }
                    }
                    break;
                case SDLK_ESCAPE:done=true;break;
                case SDLK_UP:selected=SDL_max(first,selected-1);break;
                case SDLK_DOWN:selected=SDL_min(s_count+1,selected+1);break;
                case SDLK_PAGEUP:selected=SDL_max(first,selected-4);break;
                case SDLK_PAGEDOWN:selected=SDL_min(s_count+1,selected+4);break;
                case SDLK_HOME:selected=first;break;
                case SDLK_END:selected=SDL_max(first,s_count);break;
                case SDLK_RETURN:case SDLK_SPACE:activate=!e.key.repeat;break;
                }
                if(selected>0 && selected<=s_count && selected-1<top) top=selected-1;
                if(selected>0 && selected<=s_count && selected-1>=top+4) top=selected-4;
            }
            if(e.type==SDL_EVENT_MOUSE_WHEEL) {
                float steps=e.wheel.y;if(e.wheel.direction==SDL_MOUSEWHEEL_FLIPPED) steps=-steps;
                wheelRemainder+=steps;int whole=(int)wheelRemainder;wheelRemainder-=whole;
                top=SDL_clamp(top-whole,0,SDL_max(0,s_count-4));
            }
            if(e.type==SDL_EVENT_MOUSE_BUTTON_UP || e.type==SDL_EVENT_WINDOW_FOCUS_LOST) {
                drag=false;SDL_CaptureMouse(false);
            }
            if(e.type==SDL_EVENT_MOUSE_MOTION || (e.type==SDL_EVENT_MOUSE_BUTTON_DOWN && e.button.button==SDL_BUTTON_LEFT)) {
                float x=0,y=0;bool click=e.type==SDL_EVENT_MOUSE_BUTTON_DOWN;
                bool inside=GRAP_SDL_MouseUIPoint(click?e.button.x:e.motion.x,click?e.button.y:e.motion.y,&x,&y);
                if(inside || drag) {
                    if(click && x>=296 && x<310 && y>=listY() && y<listY()+118 && s_count>4) {
                        int height=SDL_max(8,118*4/s_count);
                        float thumbY=listY()+(118-height)*top/(s_count-4);
                        dragOffset=(y>=thumbY && y<thumbY+height)?y-thumbY:height/2.0f;
                        drag=true;SDL_CaptureMouse(true);
                    }
                    if(drag && s_count>4) {
                        int height=SDL_max(8,118*4/s_count);
                        top=SDL_clamp((int)SDL_roundf((y-listY()-dragOffset)/(118-height)*(s_count-4)),0,s_count-4);
                    }
                    else if(x>=16 && x<296) {
                        if(y>=179 && y<189) { selected=s_count+1;activate=click; }
                        else if(s_hasFirstRow && y>=39 && y<51) { selected=0;activate=click; }
                        else if(y>=listY() && y<listY()+120) {
                            int index=top+(int)((y-listY())/30);
                            if(index<s_count) { selected=index+1;activate=click; }
                        }
                    }
                }
            }
            if(activate && selected==s_count+1) { done=true;activate=false; }
            if(activate) {
                if(saving) {
                    char name[NAME_LENGTH+2]={0};if(selected) SDL_strlcpy(name,s_slots[selected-1].name,sizeof(name));
                    GRAP_SDL_ClearUIThumbnails();
                    if(!captured) status="Could not capture screenshot.";
                    else if(prompt(name,selected!=0)) {
                        result=SLOTS_Write(selected?s_slots[selected-1].id:NULL,name,captured?capture:NULL);
                        if(result) done=true;else status="Save failed. Try again.";
                    }
                } else {
                    result=selected?SLOTS_Load(s_slots[selected-1].id):validLegacy();
                    if(result) done=true;else status="Load failed. Save unchanged.";
                }
            }
            if(!done) draw(saving,selected,top,status);
        }
        MOUSE_UpdateCursor();SDL_Delay(16);
    }
    SDL_CaptureMouse(false);
    GRAP_SDL_ClearUIThumbnails();GRAP_SDL_SetPixelUI(false);MOUSE_SetPointerMode(false);
    KEY_SDL_ClearInput();MOUSE_Cancel();
    memcpy(g_linearEgaBuffer0,backup,sizeof(backup));GRAP_BUF_MarkDirty();GRAP_BUF_Present();
    if(captured) SDL_RemovePath(capture);
    free(s_slots);s_slots=NULL;s_count=0;return result;
}
bool SLOTS_ShowSave(void) { return show(true,true); }
bool SLOTS_ShowLoad(void) { return show(false,false); }
bool SLOTS_ShowLoadInGame(void) { return show(false,true); }
static void (*s_reloadCallback)(void);
void SLOTS_SetReloadCallback(void (*callback)(void)) { s_reloadCallback=callback; }
void SLOTS_RequestReload(void) { if(s_reloadCallback) s_reloadCallback(); }
void SLOTS_ReloadActiveGame(void)
{
    /* Mirror Journey Onward's initialization, then reenter the top-level map loop. */
    AUDIO_StopBgm();
    /* The abandoned cursor poll temporarily disables character advancement. */
    D_538e=1;
    ULTIMA_1c22_SetTextWindowSize(0,0,0,39,24);
    ULTIMA_1c22_SetTextWindowSize(1,24,1,39,9);
    ULTIMA_1c22_SetTextWindowSize(2,24,11,39,23);
    ULTIMA_1b94_SelectTextWindow(0);
    ULTIMA_1c9e_SelectCharset(0);
    ULTIMA_102e_UnloadTileset();
    while(!ULTIMA_0ff4_LoadTileset(D_25f0[0])) {}
    ULTIMA_0c22_GRAP_0f_SelectPage(0);
    ULTIMA_637e_DrawFrame();
    ULTIMA_2e96_SetWindDirection(0);
    ULTIMA_1b94_SelectTextWindow(2);
    ULTIMA_1bf2_SetTextPosition(0,12);
    ULTIMA_251e_SwitchDisks(3);
    if(FILE_ReadSavegameFile("SAVED.GAM")!=0) {
        DEBUG_Error("Cannot restore selected save");exit(1);
    }
    debug("Restoring saved world objects");
    ULTIMA_256e_ReadFileFromDisk("SAVED.OOL",D_b21e,512,0);
    ULTIMA_25d8_WriteFileToDisk("BRIT.OOL",D_b21e,256);
    ULTIMA_25d8_WriteFileToDisk("UNDER.OOL",D_b21e+256,256);
    ULTIMA_251e_SwitchDisks(1);
    D_b11c=D_b21e;D_a9cb=0xff;D_a9fa=1;
    D_52ba_vdp._52be_tileYOffset=8;
    debug("Restoring saved wind display");
    ULTIMA_2e96_SetWindDirection(-1);
    debug("Restoring saved vitals display");
    ULTIMA_2900_UpdateVitalsDisplay();
    debug("Save restored; restarting map loop");
    SLOTS_StartTime();
}
#endif

bool SLOTS_Delete(const char* id)
{
    debug("Save delete requested slot=%s",id?id:"(null)");
    bool ok=SLOTS_Delete_Impl(id);
    if(ok) debug("Save delete completed slot=%s",id);
    else DEBUG_Error("Save delete failed slot=%s; last SDL error: %s",id?id:"(null)",SDL_GetError());
    return ok;
}

bool SLOTS_Load(const char* id)
{
    debug("Save load requested slot=%s",id?id:"(null)");
    bool ok=SLOTS_Load_Impl(id);
    if(ok) debug("Save load completed slot=%s",id);
    else DEBUG_Error("Save load failed slot=%s; last SDL error: %s",id?id:"(null)",SDL_GetError());
    return ok;
}
