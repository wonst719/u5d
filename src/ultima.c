#include "common/common.h"
#include "vars.h"
#include "funcs.h"

#include "outsubs.h"

#if !defined(TARGET_DOS16)
extern int g_enableDebugOverlay;
#endif

#define TEXT_1393 "BRIT.DAT"
#define TEXT_139C "UNDER.DAT"

void ULTIMA_2322_DiskSwapMessage(void);

// OK P1
int CDECL ULTIMA_0000_main(int argc, char** argv, char** envp)
{
    u16 local_8;
    u8 local_6; // hard drive letter (0xff for floppy)
    u8 local_4;
    u16 local_2;

    local_4 = 0x20;

    if (argc > 1)
    {
        local_4 = ULTIMA_2032_ToUpper((unsigned char)argv[1][0]);
    }

    // 0021
    D_52ba_vdp._52ba_forceCga = local_4 == 'C';
    D_52f3_forceHerc = local_4 == 'H';
    D_52f1_forceTandy = local_4 == 'T';
    D_52ef_forceEga = local_4 == 'E';

    // 0061
    D_5394_fn = &ULTIMA_2322_DiskSwapMessage;
    //D_5394 = 0x2322;
    //D_5396 = 0x1000;

    D_a9bd = 0;
    D_a9be = 0;
    D_a9c2 = 1;

    if ((D_a9c8 = ULTIMA_16a6_GetDefaultDrive()) >= 'C')
        local_6 = D_a9c8;
    else
        local_6 = 0xff;

    // 0090
    D_a9cd = local_6;
    D_a9ca = local_6;
    D_a9c9 = local_6;

    D_a9cb = 0xff;
    D_b11c = D_b21e;
    D_538c = 1;

    INTRO_0986_Main(); // 00ad
    ULTIMA_2900_UpdateVitalsDisplay();

#if !defined(TARGET_DOS16)
    g_enableDebugOverlay = 1;
#endif

    local_8 = 0;

    // 00b8
    do
    {
        local_2 = 0;

        if (D_5893_map_id == 0)
        {
            MAINOUT_0d22();
            local_2 = 1;
            local_8 = 0;
        }
        
        // 00d1
        if (D_5893_map_id != 0)
        {
            // 00db
            if (D_5893_map_id < 0x21)
            {
                TOWN_11f0_Entry(local_2 != 0 || local_8 != 0);
                TOWN_141e_MainLoop();
                local_8 = 0;
            }
            else
            {
                // 0104
                ULTIMA_251e_SwitchDisks(2);
                DUNGEON_0e2e_MainLoop(local_2);
                local_8 = 1;
            }

            // 0116
            local_2 = 0;
            ULTIMA_251e_SwitchDisks(1);

            // 0122
            while (!ULTIMA_1674_TestOpenFile(TEXT_1393)) {}
            ULTIMA_256e_ReadFile(OUTSUBS_0368_GetWorldSavefile(), D_5c5a, 0x100, 0);

            if (D_5893_map_id == 0 && D_5895_map_level != 0)
            {
                ULTIMA_251e_SwitchDisks(5);

                // 0154
                while (!ULTIMA_1674_TestOpenFile(TEXT_139C)) {}
                ULTIMA_25d8_WriteFile(OUTSUBS_0368_GetWorldSavefile(), D_5c5a, 0x100);
            }
        }
        // 016e
    } while (local_2 == 0);

    ULTIMA_0878_RestoreVideoMode();
}

// assembly code from here

// STUB
void ULTIMA_017e_EntryPoint(void)
{
    /*
        get dos version (int 20,30)
        if dos version < 02:
            exit to dos (int 20)

        ...
    */

    // original code does not clean up the stack
    ULTIMA_02f4_exit(ULTIMA_0000_main(D_52a2, D_52a4, D_52a6));
}

// STUB
void ULTIMA_0230(void) { debug("ULTIMA_0230"); }

// STUB
int CDECL main(int argc, char** argv, char** envp)
{
    D_52a6 = envp;
    D_52a4 = argv;
    D_52a2 = argc;

    ULTIMA_017e_EntryPoint();
}
