#include "COMMON.H"
#include "VARS.H"

#include <stdio.h>

// NOTE: 헤더 같은 게 있어서 주소가 0x10 밀려 있음.


F_INTRO_0010() {}
F_INTRO_0050(int a, int b) {}
F_INTRO_014e() {} // play_story
F_INTRO_043e(int a) {} // (some string)
F_INTRO_04e0() {} // draw_menu_borders
F_INTRO_05b0(int a) {} // display_title(0 for fast display)
F_INTRO_0676(int a, int b, int c, int d) {} // write_menu_option(string, x in window, y in window, highlighted option y)
F_INTRO_06bc(int a) {} // build_main_menu
F_INTRO_072e() {} // acknowledgements (88ee)
F_INTRO_094e(int a) {} // pause(wait time) (8b0e)

cdecl FUN_1000_02F4(int a);

void F_INTRO_0986() // intro_main (initialize video) (8b46)
{
    int local_4;
    char *local_6;
    int local_8;
    int local_a;
    int local_c;
    int local_e;
    byte local_10;
    int local_12;
    int local_14;

    // 098e
    D_a9ce = 1;
    local_e = 0;

    // 0995
    for (local_e = 0; local_e < 0x100; local_e++) {
        D_b11e[local_e] = (char)local_e;
    }

    FUN_1000_0DE0();
    FUN_1000_1158();
    local_8 = D_5356;

    // force cga if low memory
    if ((D_52c8 == 2) && (D_5358 < 0x170)) {
        D_52f1 = 0;
        D_52ba = 1;
        D_52c8 = 0;
    }

    // 09d2
    while (FUN_1000_0E94() == 0) {}

    FUN_1000_0892(1);

    if ((D_52c8 != 0) && (D_52c8 != 3))
    {
        D_13b2 = 1;
        D_13ae = 4;
        D_13b0 = 0xf;
        D_13b6 = 5;
        D_13b4 = 2;
        D_13b8 = 0xe;
        D_13ba = 7;
    } else {
        // 0a1a
        local_e = 0;
        while (*(local_6 = D_25ea[local_e++]) != 0) // 0a35
        {
            // 0a22
            while (*local_6++ != '.') {}

            if (*local_6 == '1') {
                *local_6++ = '4';
                *local_6 = '\0';
            }
        }
    }

    // 0a49
    if (FUN_1000_0F2A() == 0)
    {
        FUN_1000_0878();
        FUN_1000_02F4(1);
        // 	ADD        SP,2h <- cdecl
    }
    if (D_52c8 == 3)
    {
        // 0a64
#define TEXT_3182 "ibm.hcs"
        while (FUN_1000_1D02(TEXT_3182, 0) == 0) {}
#define TEXT_318a "runes.hcs"
        while (FUN_1000_1D02(TEXT_318a, 1) == 0) {}
    }
    else
    {
        // 0a84
#define TEXT_3194 "ibm.ch"
        while (FUN_1000_1D02(TEXT_3194, 0) == 0) {}
#define TEXT_319b "runes.ch"
        while (FUN_1000_1D02(TEXT_319b, 1) == 0) {}
    }

    // 0aa1
    FUN_1000_1C9E(0);
    FUN_1000_1C22(0, 0, 0, 0x27, 0x18);
    FUN_1000_1B94(0);
    local_a = FUN_1000_2032(FUN_1000_1D5E());
    if (local_a == 0x4a)
    {
        FUN_1000_16BA(0xff);
        FUN_1000_16BA(0xfc);
        FUN_1000_1BF2(0, 0xb);
#define TEXT_31a4 "Journey Onward\n\n"
        FUN_1000_1850(TEXT_31a4);
        FUN_1000_16BA(0xfb);
        // 0af2
        while (func_0x00008e34(D_25f0[0]) == 0) {}
        D_5893_map_id = 0x41;
        // -> 0cc9
    }
    else
    {
        // 0b06
        local_a = 1;

        do {
            local_12 = FUN_1000_0FAE_load_file(*D_25ee);
        } while (local_12 == 0);

        do {
            local_14 = FUN_1000_0FAE_load_file(*D_25ec);
        } while (local_14 == 0);

#define TEXT_31b5 "BRITISH.PTH"
        func_0x0000a3ae(TEXT_31b5, &D_55a6, ((int)&D_6606 - (int)&D_55a6)/*0x1060*/, 0);
        if (local_a != 0)
            local_a = func_0x00008bb2(local_12) == 0;

        // 0b56
        func_0x00008a62(1);
        func_0x000088e6(0, 0x8c, 0x13f, 199);
        func_0x00008e84(local_12, 7, 0x6c, 0x8c);
        func_0x0000890e(1, 0, 0, 0x8c, 0x13f, 199);
        if (local_a != 0)
        {
            func_0x00009f3a(0x12);
            local_a = FUN_0000_094e(0x14) == 0;
        }
        // 0bb6
        if (local_a != 0)
        {
            // 0bbf
            FUN_1000_16BA(0xff);
            func_0x00008e84(local_12, 0x8, 0x98, 0);
            func_0x00008dae(1, 0);
            local_a = F_INTRO_094e(0x14) == 0;
            if (local_a != 0)
            {
                func_0x00008a62(0);
                D_bb18 = 0;
                local_a = 0;
                if ((F_INTRO_0050(0x2c, 0x44) != 0) &&
                    (F_INTRO_0050(0x40, 0x5e) != 0) &&
                    (F_INTRO_0050(0x8f, 0x4e) != 0))
                {
                    local_a = F_INTRO_0050(0xa7, 0x69);
                }
                // 0c42
                func_0x00008a62(1);
            }
            // 0c49
            func_0x00008e84(local_14, 0, 0x18, 0x42);
            func_0x00008dae(1, 0);
            func_0x00008e84(local_e, 9, 0x68, 0xa0);
            func_0x00008dae(1, 0);
            if (local_a != 0) {
                local_a = FUN_0000_094e(0x14) == 0;
            }
        }
        // 0c97
        func_0x00008e1c(local_14);
        func_0x00008e1c(local_12);
        D_5893_map_id = 0x40;
        FUN_1000_16BA(0xff);
        func_0x00008a62(0);
        FUN_0000_05b0(local_a);
        if (local_a != 0) {
            func_0x0000fb1a(); // thunk
        }
        // 0cc4
        local_a = 1;
    }
    func_0x00009ebe(func_0x00009e96());

    // 0cd0
    do {
        FUN_1000_1C22(0, 1, 0x10, 0x26, 0x17);
        FUN_1000_1B94(0);
        FUN_1000_16BA(0xff);
        FUN_1000_1C22(0, 0, 0, 0x27, 0x18);
        FUN_1000_1C22(1, 0x18, 1, 0x27, 9);
        FUN_1000_1C22(2, 0x18, 0xb, 0x27, 0x17);
        if (local_a == 0x4a)
        {
            local_10 = 0x4a;
        }
        else
        {
            // OK P1
            // 0d3e
            local_c = 0; // TODO
            FUN_0000_043e(0x31c1); // "Copyright 1988 Lord British"
            FUN_0000_06bc(0);
            do {
                // 0d4d
                FUN_1000_1BF2(0xf, 0xf);
                func_0x0000ca6a();
                FUN_1000_1850(0x31dd); // "Select: "
                func_0x0000cb0e();
                FUN_1000_1BF2(0x17, 0xf);
                D_5356 = 0x113;
                local_4 = 0;
                do {
                    // 0d75
                    local_10 = FUN_1000_2032(func_0x00009978());
                    if (local_10 == 0) {
                        F_INTRO_2090();
                    }
                    // 0d86
                    local_4++;
                } while ((local_4 < 200) && (local_10 == 0));
                D_5356 = local_8;
                // OK P1!
                switch ((int)local_10)
                {
                    case 1:
                    case 3:
                        local_c--;
                        if (local_c < 0) {
                            local_c = 5;
                        }
                        FUN_0000_06bc(local_c);
                        break;
                    case 2:
                    case 4:
                        local_c++;
                        if (5 < local_c) {
                            local_c = 0;
                        }
                        FUN_0000_06bc(local_c);
                        break;
                    case 0xd:
                    case 0x20:
                        // 0de2
#define TEXT_3270 "JCTUAR"
                        local_10 = TEXT_3270[local_c];
                        break;
                    case 0:
                        local_10 = 0x52;
                        break;
                    case 0x4a:
                        FUN_0000_06bc(0);
                        break;
                    case 0x43:
                        FUN_0000_06bc(1);
                        break;
                    case 0x54:
                        FUN_0000_06bc(2);
                        break;
                    case 0x55:
                        FUN_0000_06bc(3);
                        break;
                    case 0x41:
                        FUN_0000_06bc(4);
                        break;
                    case 0x52:
                        FUN_0000_06bc(5);
                        break;
                    default:
                        local_10 = 0;
                        break;
                }
            } while (local_10 <= 0x20);
        }

        // 0e47
        switch ((int)local_10)
        {
            case 0x4a:
                // 0e7c
                func_0x0000e1be();
                func_0x0000acd6(0);
                FUN_1000_1B94(2);
                FUN_1000_1BF2(0, 0xc);
                if (D_5893_map_id == 0x40) {
                    while (func_0x00008e34(*(undefined2 *)0x25f0) == 0) {}
                    D_5893_map_id = 0x41;
                }
                // 0ead
                func_0x0000a35e(3);
                func_0x0000a3ae(0x31e6, 0x55a6, ((int)&D_6606 - (int)&D_55a6)/*0x1060*/, 0); // "SAVED.GAM"
                if (*(char*)D_55a8_party == '\0')
                {
                    FUN_1000_1850(0x31f0); // "\n\nNo active game."
                    FUN_1000_1850(0x3203); // "Please create a character "
                    FUN_1000_1850(0x321e); // "or transfer one from Ultima IV. "
                    func_0x00009c1a(0);
                    D_a9cb = 0xff;
                    func_0x0000a35e(0);
                    FUN_1000_1B94(0);
                    FUN_1000_16BA(0xff);
                    func_0x00008a62(1);
                    FUN_1000_16BA(0xff);
                    func_0x00008a62(0);
                    FUN_0000_05b0(0);
                    local_a = 0;
                }
                else
                {
                    // 0f26
                    func_0x0000a3ae(0x323f, 0xb21e, 0x200, 0); // "SAVED.OOL"
                    func_0x0000a35e(1);
                    func_0x0000a418(0x3249, 0xb21e, 0x100); // "BRIT.OOL"
                    func_0x0000a418(0x3252, 0xb31e, 0x100); // "UNDER.OOL"
                    if ((D_5893_map_id == 0) && (D_5895 != 0)) {
                        func_0x0000a35e(5);
                        while (func_0x000094b4(0x325c) == 0) {} // "UNDER.DAT"
                        func_0x0000a418(0x3266, 0xb31e, 0x100); // "UNDER.OOL"
                    }
                    func_0x0000acd6(0xffff);
                    D_52be = 8;
                    return;
                }
                break;
            case 0x54:
                FUN_1000_16BA(0xff);
                FUN_0000_132a();
                goto L_0fab; // TODO: get rid of goto
                //break;
            case 0x43:
                // 0fa8
                func_0x0000fb0e();
L_0fab:
                FUN_1000_1C22(0, 0, 0, 0x27, 0x18);
                FUN_1000_1B94(0);
                FUN_1000_16BA(0xff);
                func_0x00008a62(1);
                FUN_1000_16BA(0xff);
                FUN_0000_05b0(0);
                FUN_0000_0010();
                func_0x00008a62(0);
                break;
            case 0x55:
                FUN_0000_014e();
                FUN_0000_05b0(0);
                break;
                
            case 0x41: // 'A'
                // 0ff4
                if (D_5893_map_id != '@') {
                    func_0x00008e6e();
                    D_5893_map_id = 0x40;
                }
                FUN_0000_072e();
                break;

            case 0x52:
                func_0x0000fb1a();
                break;
        }
    } while( 1 );
}

F_INTRO_1016() {} // transfer_u4_data (91d6)
F_INTRO_1278() {} // print_u4_class (9438)
F_INTRO_12ea(int a) {}
F_INTRO_132a() {} // transfer_character (94ea)
F_INTRO_1e22(int a) {} // (9fe2)
F_INTRO_1e62() {} // (a022)
F_INTRO_1f26(int a) {} // (a0e6)
F_INTRO_2024() {}
F_INTRO_2090() {}
F_INTRO_20ae() {} // update_demo (a26e)
