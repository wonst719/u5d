#include "COMMON.H"
#include "VARS.H"
#include "FUNCS.H"

#include <stdio.h>

F_CAST2_0e76();

void F_BLCKTHRN_0910_death();

char* F_OUTSUBS_0368_GetWorldSavefile();
void F_OUTSUBS_01b4(int param_1, int param_2);
void F_OUTSUBS_02c8(int a, int b);
int F_OUTSUBS_0388(char* param_1);
F_OUTSUBS_0458();
void F_OUTSUBS_0566(void);
F_OUTSUBS_05ee();
F_OUTSUBS_05fc();

F_MAINOUT_109e();
int F_MAINOUT_1a60();
F_MAINOUT_1be8();

// OK P1
void F_MAINOUT_0000(void)
{
    FUN_1000_4be8();
    FUN_1000_4f7c(0);

    D_58a4 = D_5956 = D_24e6 = 1;
    D_5955 = 0;
    D_589b = D_5896_map_x & 0xf0;
    if ((D_5896_map_x & 0xf) < 8)
    {
        D_589b = (D_589b - 0x10) & 0xf0;
    }

    // 0034
    D_589c = D_5897_map_y & 0xf0;
    if ((D_5897_map_y & 0xf) < 8)
    {
        D_589c = (D_589c - 0x10) & 0xf0;
    }

    // 004f
    F_OUTSUBS_01b4(0, 1);
    F_OUTSUBS_01b4(0, -1);
    FUN_1000_4f7c(0);
    FUN_1000_5e4a();
    FUN_1000_2e96_print_direction(-1);
    FUN_1000_4a84();
    F_OUTSUBS_0566();
}

// TODO: MATCH
void F_MAINOUT_007a(void)
{
    uint uVar1;
    uint uVar2;

    uVar1 = (int)((uint)D_5896_map_x - (uint)D_5c5a[1]._2_x) >> 0xf;
    uVar2 = (int)((uint)D_5897_map_y - (uint)D_5c5a[1]._3_y) >> 0xf;
    if ((((D_5c5a[1]._0_tile != '\0') && (D_5c5a[1]._4_z == D_5895_map_level)) &&
        ((int)(((uint)D_5896_map_x - (uint)D_5c5a[1]._2_x ^ uVar1) - uVar1) < 6)) &&
        ((int)(((uint)D_5897_map_y - (uint)D_5c5a[1]._3_y ^ uVar2) - uVar2) < 6)) {
        FUN_1000_3ae6(1);
    }
}

// OK P1
int F_MAINOUT_00da(int param_1)
{
    int local1_6;
    int local2_4 = 0;

    switch (D_587c & 0xfc)
    {
    case 0x10:
        // 010a
        FUN_1000_1850_print_string("Ride "); // 2946
        if (param_1 == 1)
        {
            D_587c = 0x12;
        }
        else if (param_1 == 3)
        {
            D_587c = 0x13;
        }
        break;

    case 0x14:
        // 0130
        FUN_1000_1850_print_string("Fly ");
        if (param_1 == 1)
        {
            D_587c = 0x14;
        }
        else if (param_1 == 3)
        {
            D_587c = 0x15;
        }
        break;

    case 0x28:
        // 0152
        FUN_1000_1850_print_string("Row ");
        D_587c = (char)param_1 + (D_587c & 0xfc);
        break;

    case 0x20:
    case 0x24:
        // 016a
        local1_6 = D_587c;
        D_587c = (char)param_1 + (D_587c & 0xfc);
        if (local1_6 != D_587c)
        {
            FUN_1000_1850_print_string("Head ");

            switch (param_1)
            {
            case 0:
                FUN_1000_1850_print_string("North\n");
                break;
            case 2:
                FUN_1000_1850_print_string("South\n");
                break;
            case 1:
                FUN_1000_1850_print_string("East\n");
                break;
            case 3:
                FUN_1000_1850_print_string("West\n");
                break;
            }

            // 01ad
            D_5956 = local2_4 = 1;
            if (D_5c5a[0]._5 < 0x32)
            {
                FUN_1000_1850_print_string("Hull weak!\n");
            }
        }
        // 01dc
        else if (D_587c < 0x24 && D_5892_wind_dir == 0)
        {
            local2_4 = 1;
        }

        break;
    }

    // 0129
    return local2_4;
}

// TODO: MATCH
// Check before Walk/Move
int F_MAINOUT_01fe(int param_2, int param_1)
{
    char cVar1;
    bool bVar2;
    int iVar3;
    const char* uVar4;
    byte bStack_6;

    if ((D_587c & 0xfc) == 0x24)
    {
        FUN_1000_1850_print_string("Rowing!\n");
    }
    bVar2 = 1;
    iVar3 = FUN_1000_368e(param_2 + (uint)D_5896_map_x, param_1 + (uint)D_5897_map_y, D_5895_map_level);
    bStack_6 = (byte)iVar3;
    if (iVar3 != 0)
    {
        bVar2 = 0;
        if ((D_587c < 0x30) && (0x1f < D_587c))
        {
            if ((0x27 < D_587c) && ((0x23 < iVar3 && (iVar3 < 0x28))))
            {
            LAB_0000_0283:
                bVar2 = 1;
            }
        }
        else if (((0x23 < iVar3) && (iVar3 < 0x2c)) || ((iVar3 == 0x1b || ((bStack_6 & 0xfe) == 0x10))))
            goto LAB_0000_0283;
    }
    cVar1 = D_ab02[param_2 + param_1 * 0x20 + 0xa5];
    if ((bVar2) && (iVar3 = FUN_1000_2c4c(D_587c, cVar1), iVar3 != 0))
    {
        iVar3 = 1;
    }
    else
    {
        iVar3 = 0;
    }
    if (iVar3 != 0)
    {
        return iVar3;
    }
    if (D_5955 == '\0')
    {
        if ((0x1f < D_587c) && ((bStack_6 & 0xfc) == 0xec))
        {
            return 0;
        }
        FUN_1000_1850_print_string("Blocked!\n");
        if (cVar1 == '/') {
            FUN_1000_1850_print_string("OUCH!\n");
            FUN_1000_2aa8();
        }
        else
        {
            FUN_1000_22c0_pcspk_play_tone(0xa5, 200);
        }
        FUN_1000_1b16_clear_keyboard_buffer();
        return 0;
    }
    if (cVar1 == '\x03')
    {
        FUN_1000_1850_print_string("BREAKING UP!\n");
    }
    else
    {
        if (cVar1 == 'G')
            goto LAB_0000_02df;
        FUN_1000_1850_print_string("COLLISION!\n");
    }
LAB_0000_02df:
    if (cVar1 == 'G') {
        FUN_1000_1850_print_string("Docked!\n");
        D_587c = D_587c + '\x04';
    }
    else
    {
        FUN_1000_223c_audio_white_noise(300, 2000, 100);
        F_MAINOUT_109e();
    }
    D_5955 = 0;
    D_5956 = 1;
    return 0;
}

// TODO: MATCH
// Move
void F_MAINOUT_0354(int param_1, int param_2)
{
    byte bVar1;
    byte bVar2;

    D_5896_map_x = D_5896_map_x + (char)param_1;
    D_5897_map_y = D_5897_map_y + (char)param_2;
    D_24e6 = 1;
    bVar1 = D_5896_map_x - D_589b & 0x1f;
    bVar2 = D_5897_map_y - D_589c & 0x1f;
    if ((((bVar1 < 5) || (0x1a < bVar1)) || (bVar2 < 5)) || (0x1a < bVar2)) {
        F_OUTSUBS_02c8(param_1, param_2); // 7bd2
        D_589b = (char)param_1 * 16 + D_589b & 0xf0; // wrap x?
        D_589c = (char)param_2 * 16 + D_589c & 0xf0; // wrap y?
        F_OUTSUBS_01b4(param_1, param_2); // 7b8a
        FUN_1000_5e4a();
    }
    return;
}

// TODO: MATCH
void F_MAINOUT_03e0(void)
{
    byte bVar1;
    byte* pbVar2;
    int iVar3;
    int iVar4;
    undefined2 uVar5;
    int iStack_6;

    pbVar2 = (byte*)FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y);
    bVar1 = *pbVar2;
    if (bVar1 == 5) {
    LAB_0000_0406:
        iStack_6 = 0;
    }
    else {
        if ((bVar1 != 0x1e) && (bVar1 != 0x1f)) {
            if ((bVar1 < 4) || (0xf < bVar1)) goto LAB_0000_0406;
            if (8 < bVar1) {
                iStack_6 = 2;
                goto LAB_0000_041f;
            }
        }
        iStack_6 = 1;
    }
LAB_0000_041f:
    if (iStack_6 == 1) {
        iVar3 = F_MAINOUT_1a60();
        F_MAINOUT_007a();
        if (iVar3 == 0) {
            FUN_1000_1850_print_string("Slow progress!\n");
        }
        uVar5 = 2;
    }
    else {
        if (iStack_6 != 2) {
            return;
        }
        iVar3 = F_MAINOUT_1a60();
        F_MAINOUT_007a();
        iVar4 = F_MAINOUT_1a60();
        F_MAINOUT_007a();
        if (iVar3 + iVar4 == 0) {
            FUN_1000_1850_print_string("Very slow!\n");
        }
        uVar5 = 4;
    }
    FUN_1000_4f7c(uVar5);
    return;
}

// OK P1
int F_MAINOUT_0490(int param_1, int param_2)
{
    int local_8;
    int local_6;
    int local_4;

    if ((D_587c & 0xfc) == 0x20)
    {
        if (param_1 != D_5955)
        {
            D_5955 = param_1;
            D_5883 = 0;
        }
        D_5956 = 0;
    }

    // 04b8
    if ((D_587c == 0x1c) || ((D_587c & 0xfe) == 0x12))
    {
        FUN_1000_433e_audio_some_noise();
    }

    // 04cb
    local_6 = local_8 = 0;

    switch (param_1)
    {
    case 3:
        // 04f0
        local_8--;
#if _WIN32
        local_4 = F_MAINOUT_00da(0);
        if (local_4 != 0)
        {
            return local_4;
        }
#else
        if (F_MAINOUT_00da(0))
        {
            return;
        }
#endif

        // 0500
        if (D_5955 == 0)
        {
            FUN_1000_1850_print_string("North\n"); // 29db
        }
        break;

    case 4:
        // 054e
        local_8++;
#if _WIN32
        local_4 = F_MAINOUT_00da(2);
        if (local_4 != 0)
        {
            return local_4;
        }
#else
        if (F_MAINOUT_00da(2))
        {
            return;
        }
#endif
        if (D_5955 == 0)
        {
            FUN_1000_1850_print_string("South\n");
        }
        break;

    case 2:
        // 055c
        local_6++;
#if _WIN32
        local_4 = F_MAINOUT_00da(1);
        if (local_4 != 0)
        {
            return local_4;
        }
#else
        if (F_MAINOUT_00da(1))
        {
            return;
        }
#endif
        if (D_5955 == 0)
        {
            FUN_1000_1850_print_string("East\n");
        }
        break;

    case 1:
        // 0576
        local_6--;
#if _WIN32
        local_4 = F_MAINOUT_00da(3);
        if (local_4 != 0)
        {
            return local_4;
        }
#else
        if (F_MAINOUT_00da(3))
        {
            return;
        }
#endif
        if (D_5955 == 0)
        {
            FUN_1000_1850_print_string("West\n");
        }
        break;
    }

    // 050e
    local_4 = F_MAINOUT_01fe(local_6, local_8);
    if (param_2 == 0 && local_4 != 0)
    {
        if ((D_587c & 0xfe) == 0x12)
        {
            FUN_1000_433e_audio_some_noise();
        }
        // 0530
        F_MAINOUT_0354(local_6, local_8);
        F_MAINOUT_03e0();
    }
    return local_4;
}

// OK P1
int F_MAINOUT_0598(void)
{
    int local1_a;
    int local2_8;
    int local3_6;
    int local4_4;

    FUN_1000_5910_update_map();
    if (D_a9fa != 0)
    {
        FUN_1000_2900_update_vitals();
        D_a9fa = 0;
    }

    // 05b2
    if ((D_ab02[0xc5] & 0xfc) == 0xd4)
    {
        F_OUTSUBS_0458();
        local3_6 = 0;
    }
    else
    {
        // 05c6
        if (D_5956 != 0)
        {
            FUN_1000_16ba_print_char(10);
            FUN_1000_4c2a();
        }

        // 05d7
        D_5956 = 1;
        while (D_5955 != 0)
        {
            local3_6 = FUN_1000_2032_to_upper(FUN_1000_1b38_keystroke_cursor());
            if (local3_6 != 0 && local3_6 != D_5955)
                break;

            // 05e6
            local3_6 = (uint)D_5955;
            if (D_5892_wind_dir != 0)
            {
                local2_8 = local1_a = 0;

                switch (local3_6)
                {
                case 3:
                    // 0614
                    local1_a = -1;
                    break;
                case 4:
                    // 0658
                    local1_a = 1;
                    break;
                case 2:
                    // 0660
                    local2_8 = 1;
                    break;
                case 1:
                    // 0668
                    local2_8 = -1;
                    break;
                }

                // 0619
                local4_4 = 1;
                if (D_29f5[D_5892_wind_dir] != local2_8)
                {
                    local4_4++;
                }
                // 062e
                if (D_29f9[D_5892_wind_dir] != local1_a)
                {
                    local4_4++;
                }
                // 0640
                if (local4_4 % 3 <= (uint)D_5883)
                {
                    D_5883 = 0;
                    break;
                }
            }

            // 0670
            if (D_57bb > 0x7f)
            {
                D_a524 = (uint)(D_a524 == 0);
                FUN_1000_4f7c(1);
            }
            else
            {
                FUN_1000_4f7c(2);
            }

            if (D_a524 == 0 || D_57bb < 0x80)
            {
                F_MAINOUT_1a60();
            }

            FUN_1000_3ae6(1);
            D_5883 = D_5883 + 1;
        }

        if (D_5955 == 0)
        {
            local3_6 = FUN_1000_266c_get_ch();
        }
    }

    return local3_6;
}

// Load map
// TODO: MATCH
int F_MAINOUT_0790(char* param_1)
{
    undefined2 uVar1;
    int iVar2;
    int iVar3;
    char cStack_4;

    FUN_1000_1850_print_string(param_1);
    iVar3 = 0x20;
    do {
        if ((*(char*)(iVar3 + D_1e8a) == D_5896_map_x) &&
            (*(char*)(iVar3 + D_1eb2) == D_5897_map_y)) break;
        iVar3 = iVar3 + 1;
    } while (iVar3 < 0x28);
    if (iVar3 < 0x28) {
        if (D_587c != '\x1c') {
            FUN_1000_1850_print_string("\nOn foot!\n");
            return 0;
        }
        if (iVar3 == 0x27)
        {
            if ((D_58c8[0] & D_58c8[1] & D_58c8[2]) < 0x80)
            {
                FUN_1000_1850_print_string("\nAttacked at entrance!\n");
                iVar3 = FUN_1000_38e4();
                D_5c5a[iVar3]._0_tile = 0xfc;
                uVar1 = FUN_1000_6150_attack_monster(iVar3, iVar3);
                return uVar1;
            }
        }
        else
        {
            FUN_1000_1850_print_string("\n\n");
            FUN_1000_16ba_print_char(0xfc);
            FUN_1000_1850_print_string(D_1e3a[iVar3]);
            FUN_1000_16ba_print_char(0xfb);
        }
        FUN_1000_16ba_print_char(10);
        if (D_a9bd != '\x01')
        {
            FUN_1000_251e_switch_disks(1);
            do { iVar2 = FUN_1000_1674_test_open_file("BRIT.DAT"); } while (iVar2 == 0);
        }

        uVar1 = F_OUTSUBS_0368_GetWorldSavefile(); // THUNK 7a22
        FUN_1000_25d8_write_file_to_disk(uVar1, D_5c5a, 0x100);
        FUN_1000_251e_switch_disks(2);
        FUN_1000_256e_read_file_from_disk("DUNGEON.DAT", D_595a, 0x200, iVar3 * 0x200 + -0x4000);
        cStack_4 = (char)iVar3;
        D_5893_map_id = cStack_4 + '\x01';
        if ((D_5895_map_level == '\0') || ((char)(cStack_4 + '\x01') == '(')) {
            D_5895_map_level = 0;
            D_5897_map_y = 1;
            D_5896_map_x = 1;
            D_6603 = 1;
            D_6602 = 5;
        }
        else {
            D_5895_map_level = 7;
            D_6603 = 3;
            D_6602 = 4;
            D_5897_map_y = 7;
            D_5896_map_x = 7;
        }
    }
    else {
        FUN_1000_1850_print_string("\nWhat dungeon?\n");
    }
    return 1;
}

// TODO: MATCH
int F_MAINOUT_08de(void)
{
    byte bVar1;
    byte* pbVar2;
    const char* uVar3;
    int iVar4;
    undefined2 uStack_4;

    FUN_1000_1850_print_string("Enter ");
    pbVar2 = (byte*)FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y);
    bVar1 = *pbVar2;
    if (bVar1 == 0x16) {
        uVar3 = "cave";
    LAB_0000_09ab:
        uStack_4 = F_MAINOUT_0790(uVar3);
    }
    else {
        if (bVar1 < 0x17) {
            if (bVar1 == 0x10) {
                uVar3 = "hut";
            }
            else {
                if (bVar1 == 0x11) {
                    FUN_1000_1850_print_string("the Shrine of the Codex!\n");
                    goto LAB_0000_0968;
                }
                if (bVar1 == 0x12) {
                    uVar3 = "keep";
                }
                else if (bVar1 == 0x13) {
                    uVar3 = "village";
                }
                else if (bVar1 == 0x14) {
                    uVar3 = "towne";
                }
                else {
                    if (bVar1 != 0x15) goto LAB_0000_09ee;
                    uVar3 = "castle";
                }
            }
        }
        else {
            if (bVar1 == 0x19) {
                FUN_1000_1850_print_string("the shrine of\n");
                iVar4 = 0;
                do {
                    if ((*(char*)(iVar4 + D_1f6e) == D_5896_map_x) &&
                        (*(char*)(iVar4 + D_1f76) == D_5897_map_y)) break;
                    iVar4 = iVar4 + 1;
                } while (iVar4 < 8);
                FUN_1000_1850_print_string(D_1f4e[iVar4]);
                FUN_1000_16ba_print_char(10);
            LAB_0000_0968:
                F_CAST2_0e76(); // THUNK 7a6a
                return 1;
            }
            if (bVar1 < 0x19) {
                if (bVar1 == 0x17) {
                    uVar3 = "mine";
                }
                else {
                    if (bVar1 != 0x18) {
                    LAB_0000_09ee:
                        FUN_1000_1850_print_string("What?\n");
                        return 0;
                    }
                    uVar3 = "dungeon";
                }
                goto LAB_0000_09ab;
            }
            if (bVar1 == 0x1a) {
                FUN_1000_1850_print_string("ruins");
                return 1;
            }
            if (bVar1 == 0x1b) {
                uVar3 = "lighthouse";
            }
            else if (bVar1 == 0x39) {
                uVar3 = "the palace of Blackthorn!";
            }
            else {
                if (bVar1 != 0x3e) goto LAB_0000_09ee;
                uVar3 = "the Castle of Lord British!";
            }
        }
        uStack_4 = F_OUTSUBS_0388(uVar3); // THUNK 7bba
    }
    return uStack_4;
}

// OK P1
int F_MAINOUT_0a1a(int param_1)
{
    if (*FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y) == 0xff && D_587a != 0xe)
    {
        D_58a5 = 0;
        if (param_1 == 0)
        {
            FUN_1000_5910_update_map();
            param_1 = 1;
        }
    }
    else
    {
        param_1 = 0;
        FUN_1000_4f7c(0);
    }

    return param_1;
}

// OK P1
// check earthquake
void F_MAINOUT_0a60(void)
{
    if (D_5895_map_level != 0)
    {
        if (FUN_1000_2092_random_range(0, 0xff) == 0x69)
        {
            FUN_1000_1850_print_string("EARTHQUAKE!\n");
            FUN_1000_3072();
            FUN_1000_2aa8();
        }
    }
}

// OK P1 (stack)
void F_MAINOUT_0a84_main_loop()
{
    int local_4 = 0;
    byte local_6;
    int local_8;
    int local_a;
    bool local_c;
    int local_e; // not used
    int local_10; // not used
    int local_12;
    do {
        // 0a8f
        local_c = 0;
        local_a = 1;
        local_4 = F_MAINOUT_0a1a(local_4);
        local_8 = FUN_1000_39fc_get_first_active_party_member();
        if (local_8 == 1)
        {
            FUN_1000_16ba_print_char(10);
            FUN_1000_4c2a();
            // 0aba
            FUN_1000_1850_print_string("Zzzzzz...\n");
        }
        else if (local_8 == -1) // 0ac2
        {
            if (D_a9bd != 1)
            {
                FUN_1000_251e_switch_disks(1);
                // 0ad6
                while (FUN_1000_1674_test_open_file("BRIT.DAT") == 0) {}
            }
            // 0ae1
            FUN_1000_25d8_write_file_to_disk(F_OUTSUBS_0368_GetWorldSavefile(), D_5c5a, 0x100);
            F_BLCKTHRN_0910_death();
            local_c = 1;
            local_a = 0;
        }
        else
        {
            // 0b00
            if (FUN_1000_48a8() != 0)
            {
                F_CAST2_0e76();
            }
            // 0b0a
            if (D_5893_map_id != 0)
            {
                return;
            }
            // 0b14
            local_6 = F_MAINOUT_0598();
            if (local_6 < 0x20)
            {
                switch (local_6 & 0xff)
                {
                case 0xb: // 0b34
                    FUN_1000_1a3e_print_number(D_5888, 1, 0x20);
                    // -> 0b75
                    FUN_1000_16ba_print_char(10);
                    // -> 0af8
                    local_a = 0;
                    break; // -> 0c12

                case 5: // 0b48
                    FUN_1000_1850_print_string("Exit to DOS? ");
                    local_6 = FUN_1000_266c_get_ch();
                    if (local_6 == 'Y')
                    {
                        FUN_1000_0878_set_old_video_mode();
                        FUN_1000_02f4_exit_to_dos(0);
                    }
                    else
                    {
                        FUN_1000_1850_print_string("N\n");
                    }
                    break;

                case 0x16: // 0b6e
                    FUN_1000_1850_print_string("1.16");
                    // 0b75
                    FUN_1000_16ba_print_char(10);
                    local_a = 0;
                    break;

                case 0x13: // 0b80
                    FUN_1000_1850_print_string("Sound ");
                    if (D_a9ce != 0)
                    {
                        FUN_1000_1850_print_string("Off\n");
                    }
                    else
                    {
                        FUN_1000_1850_print_string("On\n");
                    }
                    // ?
                    D_a9ce = !D_a9ce;
                    break;

                case 1: // 0baa
                case 2:
                case 3:
                case 4:
                    local_a = F_MAINOUT_0490(local_6, local_4);
                    break;

                case 0: // 0af8
                    local_a = 0;
                    break;

                default: // 0bb8
                    FUN_1000_1850_print_string("What?\n");
                    break;
                }
            }
            else
            {
                // 0bee
                if ((local_6 < 0x30) || (0x39 < local_6))
                {
                    // 0bfa
                    local_a = FUN_1000_3178_process_command(local_6 & 0xff);
                }
                else
                {
                    // 0c06
                    local_a = FUN_1000_4080(local_6);
                }
            }
        }
        // 0c12
        if ((D_587c & 0xfc) != 0x20)
        {
            D_5955 = 0;
        }
        // 0c20
        if (D_5893_map_id != 0)
        {
            local_c = 1;
        }
        else
        {
            if (local_a != 0)
            {
                // 0c39
                FUN_1000_4f7c(2);
                local_12 = *FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y);
                if ((local_12 & 0xfe) == 0x6a)
                {
                    F_MAINOUT_1be8();
                }
                // 0c64
                else if ((local_12 == 4) && (D_587c == 0x1c))
                {
                    F_OUTSUBS_05fc();
                    FUN_1000_3ae6(1);
                }
                else if (local_12 == 0x8f)
                {
                    F_OUTSUBS_05ee();
                }
                else if (D_5896_map_x == 0xe9 && D_5897_map_y == 0xeb && D_5895_map_level == 0 && D_5893_map_id == 0)
                {
                    FUN_1000_1850_print_string("\n\"");
                    if (D_58cc != 0)
                    {
                        FUN_1000_1850_print_string("Pass, Seeker!\"\n");
                    }
                    else
                    {
                        FUN_1000_1850_print_string("Thou art not upon a Sacred Quest!\n");
                        FUN_1000_1850_print_string("Passage denied!\"\n");
                        D_5897_map_y++;
                    }
                }

                // 0cd0
                F_MAINOUT_0a60();
                FUN_1000_2ae8();
                if (local_12 == 1 && ((D_587c & 0xfc) == 0x28 || (D_587c & 0xfe) == 0x14))
                {
                    FUN_1000_1850_print_string("Rough seas!\n");
                    FUN_1000_3522(D_5896_map_x, D_5897_map_y);
                    F_MAINOUT_109e();
                }
                if ((local_12 & 0xfc) == 0xd4)
                {
                    F_OUTSUBS_0458();
                }
                F_MAINOUT_1a60();
            }
        }
    } while (!local_c);
}

// on_load_mainout_ovl
// OK P1 (reg)
void F_MAINOUT_0d22()
{
    undefined1 local_8;
    int local_6;
    ActorFmt* local_4;

    F_MAINOUT_0000();

    if (D_6605 >= 0x40)
    {
        local_6 = FUN_1000_38e4();
        local_4 = &D_5c5a[local_6]; // get some actor
        local_4->_7 = D_6605 & 0x3f;
        local_4->_2_x = D_5953; // ship_x
        local_4->_3_y = D_5954; // ship_y
        local_4->_4_z = 0;

        if (D_6605 > 0x7f)
        {
            local_8 = 0x25;
        }
        else
        {
            local_8 = 0x29;
        }

        local_4->_0_tile = local_4->_1 = local_8;
        local_4->_5 = 99;
        D_6605 = 0;
    }

    F_MAINOUT_0a84_main_loop();
}

// TODO: Match
int F_MAINOUT_0d8c(void)
{
    byte bVar1;
    int iStack_4;

    if (D_5895_map_level < 0x80)
    {
        bVar1 = *FUN_1000_4402_get_address_of_tile_id(D_5896_map_x, D_5897_map_y);
        if ((bVar1 < 0x20) || (0x26 < bVar1))
        {
            if ((bVar1 == 4) || ((8 < bVar1 && (bVar1 < 0x10))))
            {
                iStack_4 = 2;
            }
            else
            {
                iStack_4 = 1;
            }
        }
        else
        {
            iStack_4 = 0;
        }
        if ((0x1f < D_587f) || (D_587f < 5))
        {
            iStack_4 = iStack_4 + 3;
        }
    }
    else
    {
        iStack_4 = 3;
    }

    return iStack_4;
}

void F_MAINOUT_0fc4() {}

// TODO: Match
int F_MAINOUT_105c(int param_1)
{
    int uVar1;

    if (((param_1 < 0x2c) || (0x2f < param_1)) &&
        (((param_1 < 0x80 || ((0xb3 < param_1 && (param_1 < 0xb8)))) ||
            ((0xe7 < param_1 && (param_1 < 0xec)))))) {
        uVar1 = 0;
    }
    else {
        uVar1 = 1;
    }
    return uVar1;
}

F_MAINOUT_109e() {}

int F_MAINOUT_131a(int a) {}

void F_MAINOUT_198c(int a) {}

// TODO: Match
int F_MAINOUT_1a60()
{
    int iVar2;
    int iVar3;
    int iStack_4;

    iStack_4 = 0;
    if (D_587a == 'T')
    {
        iStack_4 = 0;
        return iStack_4;
    }
    else
    {
        if (D_587a == 'Q')
        {
            D_2c55 = D_2c55 ^ 1;
            if (D_2c55 != 0)
            {
                iStack_4 = 0;
                return iStack_4;
            }
        }
        if (((D_587c & 0xfe) == 0x12) || ((D_587c & 0xfe) == 0x14))
        {
            D_2c57 = D_2c57 ^ 1;
            if (D_2c57 != 0)
            {
                iStack_4 = 0;
                return iStack_4;
            }
        }
        if (FUN_1000_2092_random_range(1, 0x1e) < F_MAINOUT_0d8c())
        {
            F_MAINOUT_0fc4();
        }
        for (iVar2 = 0x1f; 0 < iVar2; iVar2--)
        {
            iVar3 = F_MAINOUT_105c(D_5c5a[iVar2]._0_tile);
            if (iVar3 != 0)
            {
                iVar3 = F_MAINOUT_131a(iVar2);
                iStack_4 = iStack_4 + iVar3;
                if (iStack_4 == 0)
                {
                    F_MAINOUT_198c(iVar2);
                }
            }
        }

        for (iVar2 = 0x1f; 0 < iVar2; iVar2--)
        {
            iVar3 = F_MAINOUT_105c(D_5c5a[iVar2]._0_tile);
            if (iVar3 != 0 && ((0x1f < (D_5c5a[iVar2]._2_x - D_589b) || (0x1f < (D_5c5a[iVar2]._3_y - D_589c)))))
            {
                FUN_1000_3a74(0, 0, 0, 0, 0, 0, iVar2);
            }
        }
    }
    return iStack_4;
}

// bridge?
F_MAINOUT_1be8() {}
