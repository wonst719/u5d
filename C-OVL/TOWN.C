#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

F_TOWN_0000() { }
F_TOWN_00b0() { }
F_TOWN_0170() { }
F_TOWN_02ae() { }
F_TOWN_0408() { }
F_TOWN_0600() { }
F_TOWN_0958() { }
F_TOWN_0c78() { }

// OK P1
uint F_TOWN_0dc4(int param_1)
{
    uint local_4;

    if (param_1 != 0)
    {
        FUN_1000_5910();
        if (D_a9fa != 0)
        {
            FUN_1000_2900();
            D_a9fa = 0;
        }
        FUN_1000_16ba_print_char(10);
        FUN_1000_4c2a();
    }

    local_4 = FUN_1000_266c_get_ch();

    if (D_5957 != 0)
    {
        if (FUN_1000_2092(0, 1) != 0)
        {
            F_TOWN_0958();
            D_5957--;
            FUN_1000_1850_print_string("Hic!\n");
            local_4 = D_2742[FUN_1000_2092(0, 3)];
        }
    }

    return local_4;
}

F_TOWN_0e34() { }
F_TOWN_0f02() { }
F_TOWN_1156() { }
F_TOWN_11b8() { }
F_TOWN_1352() { }

// OK P1 (complete)
void F_TOWN_11f0_Entry(int param_1)
{
    int local_4;

    D_a9bc = D_24e6 = 1;
    if (param_1 != 0)
    {
        for (local_4 = 1; local_4 < 0x20; local_4++)
        {
            D_5c5a[local_4 * 8] = 0;
        }
        D_5957 = 0;
        D_58a4 = 1;
        F_NPC_0000();
        F_NPC_00d6(D_587f);
    }
    D_5958 = 0xff;
    F_TOWN_0408(param_1);
    F_TOWN_02ae();

    for (local_4 = 0; local_4 < 0x20; local_4++)
    {
        if (F_TOWN_0000(local_4) != 0)
            F_TOWN_00b0(local_4);
    }

    if ((D_5893_map_id == 29) && (D_57b5 != 0))
        F_TOWN_00b0(9);

    FUN_1000_2900();

    if (0 <= FUN_1000_39fc())
    {
        FUN_1000_5910();
        if (D_5893_map_id == 29)
        {
            for (local_4 = 2; local_4 >= 0; local_4--)
            {
                if (D_58c8[local_4] < 0x80)
                {
                    F_TOWN_11b8(local_4);
                }
            }
        }
        else if (D_5958 != (byte)-1)
        {
            F_TOWN_11b8(D_5958);
            F_TOWN_1156();
        }
    }
}

// OK P1
void F_TOWN_141e_MainLoop()
{
    int local_4;
    int local_6;
    uint local_8;
    int local_a;
    uint local_c;
    int local_e;
    int local_10;
    int local_12;

    local_10 = 0;
    local_6 = 0;
    do
    {
        local_e = 0;
        local_c = 1;
        local_a = FUN_1000_39fc();
        // 1456
        if (local_a == 1)
        {
            FUN_1000_16ba_print_char(10);
            FUN_1000_4c2a();
            FUN_1000_1850_print_string("Zzzzzz...\n");
        }
        else if (local_a == -1)
        {
            F_BLCKTHRN_0910_death();
            local_c = 0;
        }
        else
        {
            if (D_a9bc != 0)
            {
                D_a9bc = 0;
            }
            else
            {
                if (FUN_1000_48a8() != 0) // FMT: F_LOOKOBJ_UNK();
                {
                    F_CAST2_0e76(); // thunk f89a
                }
            }
            if (D_5893_map_id == 0)
            {
                return;
            }

            local_4 = 1;

            do {
                // 148f
                local_8 = F_TOWN_0dc4(local_4);
                local_4 = 0;

                if (local_8 < 0x20)
                {
                    // 14a5
                    switch (local_8)
                    {
                    case 0xb: // 14b8 (9688)
                        FUN_1000_1a3e(D_5888, 1, 0x20);
                        // 14ff
                        FUN_1000_16ba_print_char(10);   // 94ea
                        // 154b
                        local_c = 0;
                        break;

                    case 5: // 14cc (969c)
                        FUN_1000_1850_print_string("Exit to DOS? ");
                        local_8 = FUN_1000_266c_get_ch();
                        if (local_8 == 0x59)
                        {
                            FUN_1000_0878_set_old_video_mode();
                            FUN_1000_02f4_exit_to_dos(0); // cdecl
                        }
                        else
                        {
                            FUN_1000_1850_print_string("N\n");
                        }
                        break;

                    case 0x16: // 14f8 (96c8)
                        FUN_1000_1850_print_string("1.16");
                        FUN_1000_16ba_print_char(10);
                        local_c = 0;
                        break;

                    case 0x13: // 1508 (96d8)
                        FUN_1000_1850_print_string("Sound "); // TODO                            
                        if (D_a9ce != 0)
                        {
                            FUN_1000_1850_print_string("Off\n");
                        }
                        else
                        {
                            FUN_1000_1850_print_string("On\n");
                        }

                        D_a9ce = !D_a9ce;
                        // 154b
                        local_c = 0;
                        break;

                    case 1:
                    case 2:
                    case 3:
                    case 4: // 1532 (9702)
                        local_e = F_TOWN_0600(local_8); // bp-06
                        local_c = (uint)(local_e == 0); // -> 159a
                        break;

                    default: // 1544 (9714)
                        FUN_1000_1850_print_string("What?\n");
                        local_c = 0;
                        break;
                    }
                }
                else if ((local_8 < 0x30) || (0x39 < local_8))
                {
                    local_c = FUN_1000_3178_process_command(local_8);
                }
                else
                {
                    local_c = F_TOWN_0e34(local_8);
                }
                // 159d
            } while (local_c == 3);
        }
        // 15a6
        if (D_5893_map_id == 0)
        {
            local_e = 1;
        }
        else if ((local_c != 0) && (FUN_1000_39fc() != -1))
        {
            local_12 = D_587f;
            FUN_1000_4f7c(1);
            if ((D_587f != local_12) && (D_587f == 20 || D_587f == 5))
            {
                F_TOWN_0170();
            }
            // 15ec
            F_TOWN_0f02();
            if ((D_594f != 0) && (D_5952--, D_5952 == 0))
            {
                FUN_1000_39cc(D_594f, D_5950, D_5951);
            }
            // 160d
            D_5c5a[2] = D_5896_map_x;
            D_5c5a[3] = D_5897_map_y;
            D_5c5a[4] = D_5895_map_level;
            if (((((D_587c < 0x12) || (0x16 <= D_587c)) || (local_8 == 0x20)) ||
                (local_6 = !local_6, !local_6)) &&
                ((D_587a != 'T' && ((D_587a != 'Q' || (local_10 = !local_10, !local_10))))))
            {
                // 165f
                F_TOWN_0c78();
                if ((int)local_c < 2)
                {
                    F_NPC_0db4(D_587f);
                }
                // 1671
                if ((D_65bf != 0) || (local_c == 2))
                {
                    // 167e
                    F_TOWN_1352(local_c - 1);
                }
            }
        }
        // 1686
    } while (local_e == 0);

    // 168f
}
