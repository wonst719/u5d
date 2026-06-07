#pragma once

#include "common/common.h"

void AnimateTileset(byte* tileset);
void AnimateTile_BuildMoongateTile(byte* tileset, int visibleRows, byte floorType, byte* backup);
void AnimateTile_RestoreMoongateTile(byte* tileset, byte* backup);
