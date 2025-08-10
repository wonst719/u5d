#include "COMMON.H"
#include "VARS.H"

char* OUTSUBS_0368_GetWorldSavefile()
{
	if (D_5895_map_level == 0)
		return "BRIT.OOL";
	else
		return "UNDER.OOL";
}
