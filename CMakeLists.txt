cmake_minimum_required(VERSION 4.0)
project(ultima5 C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL3 REQUIRED sdl3)
pkg_check_modules(SDL3_MIXER REQUIRED sdl3-mixer)

set(SOURCES
	src/town.c
	src/mainout.c
	src/dungeon.c
	src/intro.c
	src/npc.c
	src/combat.c
	src/blckthrn.c
	src/lookobj.c
	src/dnglook.c
	src/outsubs.c
	src/shoppes.c
	src/endgame.c
	src/sjog.c
	src/cmds.c
	src/cast.c
	src/talk.c
	src/cast2.c
	src/zstats.c
	src/comsubs.c
	src/shoppes2.c
	src/shoppes3.c
	src/font.c
	src/vars.c
	src/ultima.c
	src/0000.c
	src/1000.c
	src/2000.c
	src/3000.c
	src/4000.c
	src/5000.c
	src/6000.c
	src/7000.c
	src/savegame.c
	src/grap_drv.c
	src/audio/audio.c
	src/audio/aud_mus.c
	src/audio/aud_sdl.c
	src/audio/aud_sfx.c
	src/backend/backend.c
	src/common/file.c
    src/common/settings.c
	src/event/evt_sdl.c
	src/graphics/animate.c
	src/graphics/image.c
	src/graphics/grap_buf.c
	src/graphics/origin.c
	src/graphics/grap_sdl.c
	src/graphics/grap.c
	src/graphics/reveal.c
	src/graphics/wd.c
	src/common/debug.c
	src/common/lzw.c
	src/common/memory.c
	src/key/key_sdl.c
	src/time/time_sdl.c
)

add_executable(ultima5 ${SOURCES})

target_include_directories(ultima5 PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${SDL3_INCLUDE_DIRS}
    ${SDL3_MIXER_INCLUDE_DIRS}
)

target_link_directories(ultima5 PRIVATE
    ${SDL3_LIBRARY_DIRS}
    ${SDL3_MIXER_LIBRARY_DIRS}
)

target_link_libraries(ultima5 PRIVATE
    ${SDL3_LIBRARIES}
    ${SDL3_MIXER_LIBRARIES}
)
