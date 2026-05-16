#include <stdlib.h>

#include "common/common.h"
#include "backend/backend.h"
#include "vars.h"
#include "funcs.h"

#include "dungeon.h"
#include "intro.h"
#include "mainout.h"
#include "outsubs.h"
#include "town.h"

#if !defined(TARGET_DOS16)
extern int g_enableDebugOverlay;
#endif

void FAR ULTIMA_2322_DiskSwapMessage(void);

// OK P1
// 0000
int CDECL main(int argc, char** argv, char** envp)
{
    u16 local_8;
    u8 local_6; // hard drive letter (0xff for floppy)
    u8 local_4;
    u16 local_2;

    local_4 = 0x20;

#if !defined(TARGET_DOS16)
    BACKEND_Initialize();
    atexit(BACKEND_Cleanup);
#endif

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
    D_5394_fn = ULTIMA_2322_DiskSwapMessage;

    D_a9bd[0] = 0;
    D_a9bd[1] = 0;
    D_a9c2 = 1;

    if ((D_a9c8[0] = ULTIMA_16a6_GetDefaultDrive()) >= 'C')
        local_6 = D_a9c8[0];
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
            while (!ULTIMA_1674_TestOpenFile(/*0x1393*/ "BRIT.DAT")) {}
            ULTIMA_256e_ReadFileFromDisk(OUTSUBS_0368_GetWorldSavefile(), D_5c5a, 0x100, 0);

            if (D_5893_map_id == 0 && D_5895_map_level != 0)
            {
                ULTIMA_251e_SwitchDisks(5);

                // 0154
                while (!ULTIMA_1674_TestOpenFile(/*0x139c*/ "UNDER.DAT")) {}
                ULTIMA_25d8_WriteFileToDisk(OUTSUBS_0368_GetWorldSavefile(), D_5c5a, 0x100);
            }
        }
        // 016e
    } while (local_2 == 0);

    ULTIMA_0878_RestoreVideoMode();
}
