#include "COMMON.H"
#include "VARS.H"

#include <stdio.h>

F_OUTSUBS_01b4(int a, int b) { puts("F_OUTSUBS_0194"); }

// OK P1
char* F_OUTSUBS_0368_GetWorldSavefile()
{
	if (D_5895_map_level == 0)
		return "BRIT.OOL";
	else
		return "UNDER.OOL";
}

F_OUTSUBS_0458() {}
F_OUTSUBS_0566() { puts("F_OUTSUBS_0546"); }
F_OUTSUBS_05ee() {}
F_OUTSUBS_05fc() {}
