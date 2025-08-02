#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#define TEXT_1393 "BRIT.DAT"
#define TEXT_139C "UNDER.DAT"

// OK P1
int cdecl F_1000_0000_main(int argc, char** argv, char** envp)
{
    u16 local_8;
    u8 local_6; // hard drive letter (0xff for floppy)
    u8 local_4;
    u16 local_2;

    local_4 = 0x20;

    if (argc > 1)
    {
        local_4 = FUN_1000_2032_to_upper((unsigned char)argv[1][0]);
    }

    // 0021
    D_52ba = local_4 == 'C';
    D_52f3 = local_4 == 'H';
    D_52f1 = local_4 == 'T';
    D_52ef = local_4 == 'E';

    // 0061
    D_5394 = 0x2322;
    D_5396 = 0x1000;

    D_a9bd = 0;
    D_a9be = 0;
    D_a9c2 = 1;

    if ((D_a9c8 = FUN_1000_16a6_get_default_drive()) >= 'C')
        local_6 = D_a9c8;
    else
        local_6 = 0xff;

    // 0090
    D_a9cd = local_6;
    D_a9ca = local_6;
    D_a9c9 = local_6;

    D_a9cb = 0xff;
    D_b11c = 0xb21e;
    D_538c = 1;

    INTRO_intro_main(); // 00ad
    FUN_1000_2900();

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
                TOWN_main1_11f0(local_2 != 0 || local_8 != 0);
                TOWN_main2_141e();
                local_8 = 0;
            }
            else
            {
                // 0104
                FUN_1000_251e_switch_disks(2);
                DUNGEON_0e2e(local_2);
                local_8 = 1;
            }

            // 0116
            local_2 = 0;
            FUN_1000_251e_switch_disks(1);

            // 0122
            while (!FUN_1000_1674_test_open_file(TEXT_1393)) {}
            FUN_1000_256e_read_file_from_disk(OUTSUBS_get_world_savefile_0348(), 0x5c5a, 0x100, 0);

            if (D_5893_map_id == 0 && D_5895 != 0)
            {
                FUN_1000_251e_switch_disks(5);

                // 0154
                while (!FUN_1000_1674_test_open_file(TEXT_139C)) {}
                FUN_1000_25d8_write_file_to_disk(OUTSUBS_get_world_savefile_0348(), 0x5c5a, 0x100);
            }
        }
        // 016e
    } while (local_2 == 0);

    FUN_1000_0878_set_old_video_mode();
}

// assembly code from here

// STUB
FUN_1000_017e_entry_point()
{
    /*
        get dos version (int 20,30)
        if dos version < 02:
            exit to dos (int 20)

        ...
    */

    // original code does not clean up the stack
    FUN_1000_02F4_exit_to_dos(F_1000_0000_main(D_52a2, D_52a4, D_52a6));
}

// STUB
FUN_1000_0230()
{}

// STUB
int cdecl main(int argc, char** argv, char** envp)
{
    D_52a6 = envp;
    D_52a4 = argv;
    D_52a2 = argc;

    FUN_1000_017e_entry_point();
}
