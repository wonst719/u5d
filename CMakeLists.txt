cmake_minimum_required(VERSION 3.16)
project(Impera C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

option(IMPERA_BUNDLED_SDL "Build pinned SDL dependencies for portable releases" OFF)
if(IMPERA_BUNDLED_SDL)
    include(cmake/ReleaseDependencies.cmake)
else()
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL3 REQUIRED sdl3)
    pkg_check_modules(SDL3_MIXER REQUIRED sdl3-mixer)
endif()

set(SOURCES
    src/mod/contents.c
    src/mod/actors.c
    src/mod/types_game.c
    src/mod/contents_game.c
    src/mod/npcs.c src/mod/maps.c src/mod/package.c src/mod/types.c
    src/mod/runtime.c
    src/graphics/tileset.c
    src/common/icon.c
    src/common/folder_picker.c
    src/common/file_picker.c
    src/common/u4_transfer.c
    src/common/data_setup.c
    src/common/save_slots.c
    src/common/engine_settings.c
    src/audio/pcspeaker.c
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
	src/text/text_window.c
	src/text/text_input.c
	src/text/input_engine.c
	src/text/dialogue_runtime.c
	src/text/dialogue_game.c
	src/text/game_frame.c
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
	src/common/util.c
    src/common/settings.c
	src/event/evt_sdl.c
	src/graphics/animate.c
	src/graphics/image.c
	src/graphics/grap_buf.c
	src/graphics/origin.c
	src/graphics/crt.c
	src/graphics/grap_sdl.c
	src/graphics/widescreen.c
	src/graphics/grap.c
	src/graphics/reveal.c
	src/graphics/wd.c
	src/common/debug.c
	src/common/lzw.c
	src/common/memory.c
	src/key/key_sdl.c
	src/key/mouse.c
	src/time/time_sdl.c
)

add_executable(Impera ${SOURCES})
if(WIN32)
    enable_language(RC)
    target_sources(Impera PRIVATE packaging/impera.rc)
    target_include_directories(Impera PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/packaging")
endif()

option(U5D_BUILD_TESTS "Build native savegame regression tests" OFF)
set(U5D_TARGETS Impera)
if(U5D_BUILD_TESTS)
    enable_testing()
    add_executable(impera_extended_maps_test tests/extended_maps_test.c src/mod/maps.c src/mod/npcs.c src/mod/package.c src/mod/types.c src/mod/contents.c)
    target_include_directories(impera_extended_maps_test PRIVATE src)
    add_test(NAME extended_maps_codec COMMAND impera_extended_maps_test)
    add_executable(impera_text_window_test tests/text_window_test.c src/text/text_window.c)
    target_include_directories(impera_text_window_test PRIVATE src tests)
    add_test(NAME text_window COMMAND impera_text_window_test)
    add_executable(impera_types_test tests/types_test.c tests/type_movement_oracle.c src/vars.c src/mod/types.c src/mod/npcs.c src/mod/maps.c src/mod/package.c src/mod/contents.c)
    target_include_directories(impera_types_test PRIVATE src)
    list(APPEND U5D_TARGETS impera_types_test)
    add_test(NAME custom_types COMMAND impera_types_test)
    add_executable(impera_contents_test tests/contents_test.c src/mod/contents.c src/mod/npcs.c src/mod/maps.c src/mod/package.c src/mod/types.c)
    target_include_directories(impera_contents_test PRIVATE src)
    add_test(NAME map_contents COMMAND impera_contents_test)
    add_executable(impera_mod_test tests/mod_test.c src/common/file.c src/common/debug.c src/mod/npcs.c src/mod/maps.c src/mod/package.c src/mod/types.c src/mod/runtime.c src/mod/contents.c)
    list(APPEND U5D_TARGETS impera_mod_test)
    file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/mod-runtime/game/Mods" "${CMAKE_BINARY_DIR}/mod-runtime/SAVEGAME")
    add_test(NAME mod_packages COMMAND impera_mod_test)
    set_tests_properties(mod_packages PROPERTIES WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/mod-runtime" TIMEOUT 20)
    add_executable(impera_contents_game_test tests/contents_game_test.c src/vars.c src/mod/contents_game.c src/mod/contents.c src/mod/npcs.c src/mod/maps.c src/mod/package.c src/mod/types.c)
    target_include_directories(impera_contents_game_test PRIVATE src)
    add_test(NAME map_contents_game COMMAND impera_contents_game_test)
    set(TEST_SOURCES ${SOURCES})
    add_executable(u5d_debug_test tests/debug_test.c src/common/debug.c)
    list(APPEND U5D_TARGETS u5d_debug_test)
    file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/debug-runtime")
    add_test(NAME diagnostics COMMAND u5d_debug_test)
    set_tests_properties(diagnostics PROPERTIES WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/debug-runtime" TIMEOUT 20)

    add_executable(u5d_pcspeaker_test tests/pcspeaker_test.c src/audio/pcspeaker.c)
    list(APPEND U5D_TARGETS u5d_pcspeaker_test)
    add_test(NAME pcspeaker_algorithms COMMAND u5d_pcspeaker_test)
    list(REMOVE_ITEM TEST_SOURCES src/ultima.c)
    add_executable(impera_tileset_test tests/tileset_test.c ${TEST_SOURCES})
    list(APPEND U5D_TARGETS impera_tileset_test)
    if(UNIX AND NOT APPLE)
        target_link_options(impera_tileset_test PRIVATE "-Wl,--wrap=SDL_RenderPresent")
        target_compile_definitions(impera_tileset_test PRIVATE TEST_TILESET_PRESENT)
    endif()
    add_test(NAME alternate_tilesets COMMAND impera_tileset_test)
    file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/tileset-runtime")
    set_tests_properties(alternate_tilesets PROPERTIES TIMEOUT 20
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/tileset-runtime"
        ENVIRONMENT "SDL_VIDEO_DRIVER=dummy;SDL_AUDIO_DRIVER=dummy;SDL_RENDER_DRIVER=software;IMPERA_TILESETS=${CMAKE_SOURCE_DIR}/textures/tilesets")
    add_executable(u5d_crt_test tests/crt_test.c ${TEST_SOURCES})
    list(APPEND U5D_TARGETS u5d_crt_test)
    if(UNIX AND NOT APPLE)
        target_link_options(u5d_crt_test PRIVATE "-Wl,--wrap=MOUSE_DrawFilteredCursor" "-Wl,--wrap=SDL_GetTicks" "-Wl,--wrap=SDL_RenderPresent")
        target_compile_definitions(u5d_crt_test PRIVATE TEST_FILTERED_CURSOR)
    endif()
    add_test(NAME crt_filter COMMAND u5d_crt_test)
    set_tests_properties(crt_filter PROPERTIES TIMEOUT 10
        ENVIRONMENT "SDL_VIDEO_DRIVER=dummy;SDL_AUDIO_DRIVER=dummy;SDL_RENDER_DRIVER=software")
    add_executable(u5d_savegame_test tests/savegame_test.c ${TEST_SOURCES})
    list(APPEND U5D_TARGETS u5d_savegame_test)
    add_executable(u5d_widescreen_test tests/widescreen_test.c ${TEST_SOURCES})
    list(APPEND U5D_TARGETS u5d_widescreen_test)
    add_test(NAME widescreen COMMAND u5d_widescreen_test)
    file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/widescreen-runtime")
    set_tests_properties(widescreen PROPERTIES
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/widescreen-runtime" TIMEOUT 10
        ENVIRONMENT "SDL_VIDEO_DRIVER=dummy;SDL_AUDIO_DRIVER=dummy;SDL_RENDER_DRIVER=software")
    file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/test-runtime/SAVEGAME")
    foreach(NPC_FILE TOWNE.NPC DWELLING.NPC CASTLE.NPC KEEP.NPC)
        configure_file("${CMAKE_SOURCE_DIR}/Ultima 5/${NPC_FILE}"
                       "${CMAKE_BINARY_DIR}/test-runtime/${NPC_FILE}" COPYONLY)
    endforeach()
    add_test(NAME savegame COMMAND u5d_savegame_test)
    set_tests_properties(savegame PROPERTIES WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/test-runtime")
    set_tests_properties(savegame PROPERTIES TIMEOUT 10)
    add_test(NAME missing_required_file COMMAND ${CMAKE_COMMAND}
             -DTEST_EXE=$<TARGET_FILE:u5d_savegame_test>
             -DTEST_DIR=${CMAKE_BINARY_DIR}/test-runtime
             -P ${CMAKE_SOURCE_DIR}/tests/check_missing_file.cmake)
    if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
        set(DIALOGUE_TEST_SOURCES ${TEST_SOURCES})
        list(REMOVE_ITEM DIALOGUE_TEST_SOURCES src/talk.c)
        add_executable(impera_dialogue_test tests/dialogue_runtime_test.c ${DIALOGUE_TEST_SOURCES})
        list(APPEND U5D_TARGETS impera_dialogue_test)
        target_link_options(impera_dialogue_test PRIVATE
            "-Wl,--wrap=ULTIMA_16ba_PrintChar" "-Wl,--wrap=ULTIMA_1c9e_SelectCharset"
            "-Wl,--wrap=ULTIMA_1f12_GetCurrentTextX" "-Wl,--wrap=ULTIMA_1850_PrintString")
        add_test(NAME dialogue_runtime COMMAND impera_dialogue_test)
        set_tests_properties(dialogue_runtime PROPERTIES TIMEOUT 10)
        # Independent reference: full native dispatch and framebuffer, observed without a port.
        # Keep df25c19 rendering/buffering independent of the extracted implementation.
        configure_file("${CMAKE_SOURCE_DIR}/tests/native_talk_reference.inc"
            "${CMAKE_BINARY_DIR}/native_talk_reference.inc" COPYONLY)
        file(READ "${CMAKE_SOURCE_DIR}/tests/native_talk_reference.inc" reference_talk_source)
        foreach(unit 1000 graphics/grap_buf 2000 3000 6000 vars)
            file(READ "${CMAKE_SOURCE_DIR}/src/${unit}.c" reference_unit)
            if(unit STREQUAL "1000")
                file(READ "${CMAKE_SOURCE_DIR}/tests/native_text_reference.inc" original_renderer)
                file(READ "${CMAKE_SOURCE_DIR}/tests/native_backspace_reference.inc" original_backspace)
                string(FIND "${reference_unit}" "/* Native globals remain" renderer_start)
                string(FIND "${reference_unit}" "// CHECKED (NOT MATCHING: register" renderer_end)
                math(EXPR renderer_length "${renderer_end}-${renderer_start}")
                string(SUBSTRING "${reference_unit}" ${renderer_start} ${renderer_length} renderer_adapter)
                string(REPLACE "${renderer_adapter}"
                    "static void ULTIMA_17f4_ApplyCharEffects(byte*, int);\n${original_renderer}\n"
                    reference_unit "${reference_unit}")
                string(FIND "${reference_unit}" "void ULTIMA_1fa0_Backspace(" backspace_start)
                string(SUBSTRING "${reference_unit}" ${backspace_start} -1 backspace_adapter)
                string(REPLACE "${backspace_adapter}" "${original_backspace}" reference_unit "${reference_unit}")
                file(READ "${CMAKE_SOURCE_DIR}/tests/native_string_reference.inc" original_string)
                string(FIND "${reference_unit}" "void ULTIMA_1850_PrintString(" string_start)
                string(FIND "${reference_unit}" "// CHECKED (NOT MATCHING: optimization)" string_end)
                math(EXPR string_length "${string_end}-${string_start}")
                string(SUBSTRING "${reference_unit}" ${string_start} ${string_length} string_adapter)
                string(REPLACE "${string_adapter}" "${original_string}\n" reference_unit "${reference_unit}")
            elseif(unit STREQUAL "vars")
                string(REPLACE "text/dialogue_dictionary.inc" "native_dictionary_reference.inc"
                    reference_unit "${reference_unit}")
                string(REPLACE "text/dialogue_keywords.inc" "native_keywords_reference.inc"
                    reference_unit "${reference_unit}")
            elseif(unit STREQUAL "2000" OR unit STREQUAL "3000" OR unit STREQUAL "6000")
                if(unit STREQUAL "2000")
                    set(fixture input_char)
                    set(begin_marker "int ULTIMA_266c_GetChar(")
                    set(end_marker "static void ULTIMA_2726")
                elseif(unit STREQUAL "3000")
                    set(fixture input_string)
                    set(begin_marker "void ULTIMA_3b1c_GetString(")
                    set(end_marker "int ULTIMA_3b9e(")
                else()
                    set(fixture match)
                    set(begin_marker "int ULTIMA_6f1e(")
                    set(end_marker "// ASM\nstatic int ULTIMA_6f90")
                endif()
                file(READ "${CMAKE_SOURCE_DIR}/tests/native_${fixture}_reference.inc" native_function)
                string(FIND "${reference_unit}" "${begin_marker}" begin_pos)
                string(FIND "${reference_unit}" "${end_marker}" end_pos)
                math(EXPR function_length "${end_pos}-${begin_pos}")
                string(SUBSTRING "${reference_unit}" ${begin_pos} ${function_length} adapter_function)
                string(REPLACE "${adapter_function}" "${native_function}\n" reference_unit "${reference_unit}")
                if(unit STREQUAL "6000")
                    file(READ "${CMAKE_SOURCE_DIR}/tests/native_frame_reference.inc" native_frame)
                    string(FIND "${reference_unit}" "/* Native game frame adapters */" frame_begin)
                    string(FIND "${reference_unit}" "// CHECKED\n// place actor on combat map" frame_end)
                    math(EXPR frame_length "${frame_end}-${frame_begin}")
                    string(SUBSTRING "${reference_unit}" ${frame_begin} ${frame_length} frame_adapter)
                    string(REPLACE "${frame_adapter}" "${native_frame}\n" reference_unit "${reference_unit}")
                endif()
            else()
                file(READ "${CMAKE_SOURCE_DIR}/tests/native_graphics_reference.inc" original_renderer)
                string(FIND "${reference_unit}" "static void textPixel(" renderer_start)
                string(FIND "${reference_unit}" "// 0x3f" renderer_end)
                math(EXPR renderer_length "${renderer_end}-${renderer_start}")
                string(SUBSTRING "${reference_unit}" ${renderer_start} ${renderer_length} renderer_adapter)
                string(REPLACE "${renderer_adapter}" "${original_renderer}\n" reference_unit "${reference_unit}")
            endif()
            string(REPLACE "/" "_" reference_unit_name "${unit}")
            file(WRITE "${CMAKE_BINARY_DIR}/reference_${reference_unit_name}.c" "${reference_unit}")
        endforeach()
        set(reference_dispatch "if (TALK_0f32_ProcessChar(*D_bcde++) != 0)")
        string(FIND "${reference_talk_source}" "${reference_dispatch}" reference_dispatch_position)
        if(reference_dispatch_position LESS 0)
            message(FATAL_ERROR "Native dialogue reference dispatch hook needs updating")
        endif()
        string(REPLACE "${reference_dispatch}"
            "REFERENCE_TraceOpcode(D_bcde);\n        ${reference_dispatch}"
            reference_talk_source "${reference_talk_source}")
        string(REPLACE "local_4 = *D_bcde++;"
            "REFERENCE_CheckCursor(D_bcde);\n        local_4 = *D_bcde++;"
            reference_talk_source "${reference_talk_source}")
        file(WRITE "${CMAKE_BINARY_DIR}/reference_talk.c" "${reference_talk_source}")
        set(reference_source_hashes "")
        foreach(source IN LISTS TEST_SOURCES)
            # COPYONLY registers configure dependencies without duplicate directory properties.
            configure_file("${CMAKE_SOURCE_DIR}/${source}"
                "${CMAKE_BINARY_DIR}/reference-source-snapshot/${source}" COPYONLY)
            file(SHA256 "${CMAKE_SOURCE_DIR}/${source}" source_hash)
            string(APPEND reference_source_hashes "${source}:${source_hash}\n")
        endforeach()
        configure_file("${CMAKE_SOURCE_DIR}/tests/dialogue_reference.c"
            "${CMAKE_BINARY_DIR}/reference-source-snapshot/runner.c" COPYONLY)
        file(SHA256 "${CMAKE_SOURCE_DIR}/tests/dialogue_reference.c" runner_hash)
        string(APPEND reference_source_hashes "runner:${runner_hash}")
        file(GLOB_RECURSE reference_headers CONFIGURE_DEPENDS
            "${CMAKE_SOURCE_DIR}/src/*.h" "${CMAKE_SOURCE_DIR}/src/text/*.inc")
        foreach(header IN LISTS reference_headers)
            file(RELATIVE_PATH header_name "${CMAKE_SOURCE_DIR}" "${header}")
            configure_file("${header}" "${CMAKE_BINARY_DIR}/reference-source-snapshot/${header_name}" COPYONLY)
            file(SHA256 "${header}" header_hash)
            string(APPEND reference_source_hashes "${header_name}:${header_hash}\n")
        endforeach()
        foreach(fixture text words graphics backspace string talk input_char input_string match dictionary keywords frame)
            configure_file("${CMAKE_SOURCE_DIR}/tests/native_${fixture}_reference.inc"
                "${CMAKE_BINARY_DIR}/reference-source-snapshot/native_${fixture}_reference.inc" COPYONLY)
            file(SHA256 "${CMAKE_SOURCE_DIR}/tests/native_${fixture}_reference.inc" fixture_hash)
            string(APPEND reference_source_hashes "native_${fixture}_reference.inc:${fixture_hash}\n")
        endforeach()
        string(SHA256 reference_source_id "${reference_source_hashes}")
        file(WRITE "${CMAKE_BINARY_DIR}/reference_provenance.h"
            "#define REFERENCE_SOURCE_ID \"${reference_source_id}\"\n")
        set(REFERENCE_SOURCES ${DIALOGUE_TEST_SOURCES})
        list(REMOVE_ITEM REFERENCE_SOURCES src/1000.c src/graphics/grap_buf.c src/2000.c src/3000.c src/6000.c src/vars.c)
        add_executable(impera_dialogue_reference tests/dialogue_reference.c tests/enhanced_look_oracle_stubs.c ${REFERENCE_SOURCES}
            "${CMAKE_BINARY_DIR}/reference_1000.c" "${CMAKE_BINARY_DIR}/reference_graphics_grap_buf.c"
            "${CMAKE_BINARY_DIR}/reference_2000.c" "${CMAKE_BINARY_DIR}/reference_3000.c" "${CMAKE_BINARY_DIR}/reference_6000.c"
            "${CMAKE_BINARY_DIR}/reference_vars.c")
        target_include_directories(impera_dialogue_reference PRIVATE "${CMAKE_SOURCE_DIR}/src/graphics"
            "${CMAKE_SOURCE_DIR}/tests")
        list(APPEND U5D_TARGETS impera_dialogue_reference)
        target_include_directories(impera_dialogue_reference PRIVATE "${CMAKE_BINARY_DIR}")
        target_compile_definitions(impera_dialogue_reference PRIVATE
            TEST_GAME_DIR="${CMAKE_SOURCE_DIR}/Ultima 5")
        foreach(symbol GRAP_PrintChar GRAP_ScrollWindow GRAP_SetPenColor GRAP_FillWindow GRAP_Line
                       GRAP_Pset KEY_PollKey TIME_GetTicksMs TIME_SleepMs ULTIMA_2056_GetTime
                       ULTIMA_266c_GetChar ULTIMA_3b1c_GetString ULTIMA_1b16_ClearKbdBuffer ULTIMA_5910_UpdateFrame)
            target_link_options(impera_dialogue_reference PRIVATE "-Wl,--wrap=${symbol}")
        endforeach()
        file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/dialogue-reference-runtime")
        add_test(NAME dialogue_reference COMMAND impera_dialogue_reference
            --output "${CMAKE_BINARY_DIR}/dialogue-reference-runtime")
        set_tests_properties(dialogue_reference PROPERTIES TIMEOUT 30)
        file(READ "${CMAKE_SOURCE_DIR}/src/talk.c" shared_talk_source)
        string(REPLACE "${reference_dispatch}"
            "REFERENCE_TraceOpcode(D_bcde);\n        ${reference_dispatch}"
            shared_talk_source "${shared_talk_source}")
        string(REPLACE "local_4 = *D_bcde++;"
            "REFERENCE_CheckCursor(D_bcde);\n        local_4 = *D_bcde++;"
            shared_talk_source "${shared_talk_source}")
        file(WRITE "${CMAKE_BINARY_DIR}/shared_reference_talk.c" "${shared_talk_source}")
        add_executable(impera_dialogue_shared_reference tests/dialogue_reference.c ${DIALOGUE_TEST_SOURCES})
        list(APPEND U5D_TARGETS impera_dialogue_shared_reference)
        target_include_directories(impera_dialogue_shared_reference PRIVATE "${CMAKE_BINARY_DIR}")
        target_compile_definitions(impera_dialogue_shared_reference PRIVATE
            IMPERA_REFERENCE_OBSERVER=1 DIALOGUE_REFERENCE_TALK="shared_reference_talk.c" TEST_GAME_DIR="${CMAKE_SOURCE_DIR}/Ultima 5")
        get_target_property(reference_wraps impera_dialogue_reference LINK_OPTIONS)
        target_link_options(impera_dialogue_shared_reference PRIVATE ${reference_wraps})
        find_package(Python3 COMPONENTS Interpreter REQUIRED)
        add_test(NAME dialogue_renderer_parity COMMAND "${CMAKE_COMMAND}"
            "-DPYTHON=${Python3_EXECUTABLE}"
            "-DCORPUS=${CMAKE_SOURCE_DIR}/tests/dialogue_original_corpus.py"
            "-DREFERENCE=$<TARGET_FILE:impera_dialogue_reference>"
            "-DSHARED=$<TARGET_FILE:impera_dialogue_shared_reference>"
            "-DOUTPUT=${CMAKE_BINARY_DIR}/dialogue-renderer-parity"
            "-DGAME=${CMAKE_SOURCE_DIR}/Ultima 5"
            "-DSCRIPT=${CMAKE_SOURCE_DIR}/tests/dialogue_reference_bye.tsv"
            -P "${CMAKE_SOURCE_DIR}/tests/dialogue_renderer_parity.cmake")
        set_tests_properties(dialogue_renderer_parity PROPERTIES TIMEOUT 180
            FIXTURES_SETUP native_dialogue_artifacts)
        add_test(NAME dialogue_reference_tlk COMMAND impera_dialogue_reference
            --output "${CMAKE_BINARY_DIR}/dialogue-reference-tlk-runtime"
            --tlk "${CMAKE_SOURCE_DIR}/Ultima 5/TOWNE.TLK" --npc 1
            --script "${CMAKE_SOURCE_DIR}/tests/dialogue_reference_bye.tsv")
        set_tests_properties(dialogue_reference_tlk PROPERTIES TIMEOUT 10)
        add_executable(impera_u4_transfer_test tests/u4_transfer_test.c ${TEST_SOURCES})
        list(APPEND U5D_TARGETS impera_u4_transfer_test)
        target_compile_definitions(impera_u4_transfer_test PRIVATE TEST_GAME_DIR="${CMAKE_SOURCE_DIR}/Ultima 5")
        add_test(NAME u4_transfer COMMAND impera_u4_transfer_test)
        set_tests_properties(u4_transfer PROPERTIES WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/test-runtime"
            ENVIRONMENT "SDL_VIDEODRIVER=dummy;SDL_AUDIODRIVER=dummy" TIMEOUT 10)
        add_executable(u5d_data_setup_test tests/data_setup_test.c ${TEST_SOURCES})
        list(APPEND U5D_TARGETS u5d_data_setup_test)
        target_link_options(u5d_data_setup_test PRIVATE "-Wl,--wrap=SDL_ShowOpenFolderDialog" "-Wl,--wrap=SDL_RenderPresent")
        target_compile_definitions(u5d_data_setup_test PRIVATE TEST_GAME_DIR="${CMAKE_SOURCE_DIR}/Ultima 5")
        file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/setup-runtime")
        add_test(NAME data_setup COMMAND u5d_data_setup_test)
        set_tests_properties(data_setup PROPERTIES WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/setup-runtime"
            ENVIRONMENT "SDL_VIDEO_DRIVER=dummy;SDL_AUDIO_DRIVER=dummy;SDL_RENDER_DRIVER=software" TIMEOUT 10)
        add_executable(u5d_save_slots_test tests/save_slots_test.c ${TEST_SOURCES})
        list(APPEND U5D_TARGETS u5d_save_slots_test)
        target_link_options(u5d_save_slots_test PRIVATE "-Wl,--wrap=SDL_RenderPresent")
        file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/slots-runtime")
        configure_file("${CMAKE_SOURCE_DIR}/Ultima 5/IBM.CH" "${CMAKE_BINARY_DIR}/slots-runtime/IBM.CH" COPYONLY)
        configure_file("${CMAKE_SOURCE_DIR}/Ultima 5/TILES.16" "${CMAKE_BINARY_DIR}/slots-runtime/TILES.16" COPYONLY)
        add_test(NAME save_slots COMMAND u5d_save_slots_test)
        set_tests_properties(save_slots PROPERTIES
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/slots-runtime"
            ENVIRONMENT "SDL_VIDEO_DRIVER=dummy;SDL_AUDIO_DRIVER=dummy;SDL_RENDER_DRIVER=software" TIMEOUT 20)
        add_executable(u5d_engine_settings_test tests/engine_settings_test.c ${TEST_SOURCES})
        list(APPEND U5D_TARGETS u5d_engine_settings_test)
        add_test(NAME music_directory_picker COMMAND u5d_engine_settings_test music_picker)
        set_tests_properties(music_directory_picker PROPERTIES WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/settings-runtime"
            ENVIRONMENT "SDL_VIDEO_DRIVER=dummy;SDL_AUDIO_DRIVER=dummy;SDL_RENDER_DRIVER=software" TIMEOUT 10 RUN_SERIAL TRUE)
        file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/settings-runtime")
        configure_file("${CMAKE_SOURCE_DIR}/Ultima 5/IBM.CH" "${CMAKE_BINARY_DIR}/settings-runtime/IBM.CH" COPYONLY)
        add_test(NAME engine_settings COMMAND u5d_engine_settings_test)
        foreach(exit_context settings menu cutscene gameplay)
            add_test(NAME ctrl_e_${exit_context} COMMAND u5d_engine_settings_test ${exit_context})
            set_tests_properties(ctrl_e_${exit_context} PROPERTIES
                WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/settings-runtime"
                ENVIRONMENT "SDL_VIDEO_DRIVER=dummy;SDL_AUDIO_DRIVER=dummy;SDL_RENDER_DRIVER=software"
                TIMEOUT 10 RUN_SERIAL TRUE)
        endforeach()
        set_tests_properties(engine_settings PROPERTIES WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/settings-runtime"
            ENVIRONMENT "SDL_VIDEO_DRIVER=dummy;SDL_AUDIO_DRIVER=dummy;SDL_RENDER_DRIVER=software" TIMEOUT 10)
        add_test(NAME gameplay_engine_options COMMAND u5d_engine_settings_test gameplay_options)
        set_tests_properties(gameplay_engine_options PROPERTIES
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/settings-runtime"
            ENVIRONMENT "SDL_VIDEO_DRIVER=dummy;SDL_AUDIO_DRIVER=dummy;SDL_RENDER_DRIVER=software"
            TIMEOUT 10 RUN_SERIAL TRUE)
        add_executable(u5d_audio_test tests/audio_test.c ${TEST_SOURCES})
        list(APPEND U5D_TARGETS u5d_audio_test)
        target_link_options(u5d_audio_test PRIVATE "-Wl,--wrap=SDL_PutAudioStreamData" "-Wl,--wrap=MIX_SetTrackAudio" "-Wl,--wrap=SDL_GetBasePath")
        file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/audio-runtime")
        add_test(NAME audio COMMAND u5d_audio_test)
        set_tests_properties(audio PROPERTIES WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/audio-runtime"
            ENVIRONMENT "SDL_AUDIO_DRIVER=dummy" TIMEOUT 10)
        add_executable(u5d_world_scroll_test tests/world_scroll_test.c ${TEST_SOURCES})
        list(APPEND U5D_TARGETS u5d_world_scroll_test)
        target_compile_definitions(u5d_world_scroll_test PRIVATE _FORTIFY_SOURCE=2)
        target_link_options(u5d_world_scroll_test PRIVATE "-Wl,--wrap=ULTIMA_35ec_SelectDirection"
            "-Wl,--wrap=ULTIMA_1a3e_PrintNumber" "-Wl,--wrap=ULTIMA_16ba_PrintChar"
            "-Wl,--wrap=ULTIMA_1c9e_SelectCharset" "-Wl,--wrap=AUDIO_PlayBgmPerMap"
            "-Wl,--wrap=ULTIMA_1850_PrintString"
            "-Wl,--wrap=OUTSUBS_01b4" "-Wl,--wrap=ULTIMA_5e4a")
        add_test(NAME world_scroll COMMAND u5d_world_scroll_test)
        add_executable(u5d_mouse_test tests/mouse_test.c ${TEST_SOURCES})
        list(APPEND U5D_TARGETS u5d_mouse_test)
        target_link_options(u5d_mouse_test PRIVATE
            "-Wl,--wrap=SDL_CreateTexture" "-Wl,--wrap=SDL_CreateTextureFromSurface" "-Wl,--wrap=SDL_UpdateTexture"
            "-Wl,--wrap=WIDE_TerrainPixel" "-Wl,--wrap=ULTIMA_433e_AudioFootstep" "-Wl,--wrap=SDL_CreateColorCursor" "-Wl,--wrap=SDL_GetTicks" "-Wl,--wrap=SDL_GetMouseState"
            "-Wl,--wrap=SDL_RenderPresent" "-Wl,--wrap=SDL_Delay"
            "-Wl,--wrap=ULTIMA_1850_PrintString" "-Wl,--wrap=ULTIMA_16ba_PrintChar")
        add_test(NAME mouse_controls COMMAND u5d_mouse_test)
        add_test(NAME mouse_controls_opaque COMMAND u5d_mouse_test --opaque)
        file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/mouse-runtime")
        set_tests_properties(mouse_controls mouse_controls_opaque PROPERTIES
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/mouse-runtime" TIMEOUT 10
            ENVIRONMENT "SDL_VIDEO_DRIVER=dummy;SDL_AUDIO_DRIVER=dummy;SDL_RENDER_DRIVER=software")
        add_executable(u5d_sleeping_ambush_test tests/sleeping_ambush_test.c ${TEST_SOURCES})
        list(APPEND U5D_TARGETS u5d_sleeping_ambush_test)
        target_link_options(u5d_sleeping_ambush_test PRIVATE
            "-Wl,--wrap=ULTIMA_1b16_ClearKbdBuffer" "-Wl,--wrap=TIME_SleepMs"
            "-Wl,--wrap=ULTIMA_266c_GetChar" "-Wl,--wrap=ULTIMA_20fa_WaitTicks")
        configure_file("${CMAKE_SOURCE_DIR}/Ultima 5/BRIT.CBT" "${CMAKE_BINARY_DIR}/ambush-runtime/BRIT.CBT" COPYONLY)
        configure_file("${CMAKE_SOURCE_DIR}/Ultima 5/TILES.16" "${CMAKE_BINARY_DIR}/ambush-runtime/TILES.16" COPYONLY)
        add_test(NAME sleeping_ambush COMMAND u5d_sleeping_ambush_test)
        add_test(NAME combat_entry COMMAND u5d_sleeping_ambush_test --combat-entry)
        set_tests_properties(sleeping_ambush combat_entry PROPERTIES TIMEOUT 45
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/ambush-runtime"
            ENVIRONMENT "SDL_VIDEO_DRIVER=dummy;SDL_AUDIO_DRIVER=dummy;SDL_RENDER_DRIVER=software")
        add_executable(u5d_combat_return_test tests/combat_return_test.c ${TEST_SOURCES})
        list(APPEND U5D_TARGETS u5d_combat_return_test)
        target_link_options(u5d_combat_return_test PRIVATE
            "-Wl,--wrap=DNGLOOK_117e" "-Wl,--wrap=COMBAT_0b94_MainLoop"
            "-Wl,--wrap=AUDIO_PlayBgmPerMap" "-Wl,--wrap=ULTIMA_2900_UpdateVitalsDisplay")
        add_test(NAME combat_return COMMAND u5d_combat_return_test)
        add_executable(u5d_file_case_test tests/file_case_test.c src/common/file.c src/common/debug.c src/mod/npcs.c src/mod/maps.c src/mod/package.c src/mod/types.c src/mod/runtime.c src/mod/contents.c)
        list(APPEND U5D_TARGETS u5d_file_case_test)
        target_include_directories(u5d_file_case_test PRIVATE ${CMAKE_SOURCE_DIR}/src)
        file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/case-runtime/MiXeD/SubDir"
                            "${CMAKE_BINARY_DIR}/case-runtime/SaVeGaMe"
                            "${CMAKE_BINARY_DIR}/case-runtime/u4SaVe"
                            "${CMAKE_BINARY_DIR}/case-runtime/bGm")
        add_test(NAME case_insensitive_files COMMAND u5d_file_case_test)
        set_tests_properties(case_insensitive_files PROPERTIES
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/case-runtime" TIMEOUT 10)
        find_package(Python3 COMPONENTS Interpreter REQUIRED)
        add_test(NAME runtime_filename_case COMMAND ${Python3_EXECUTABLE}
                 ${CMAKE_SOURCE_DIR}/tests/test_prepare_runtime.py)
    endif()
endif()

foreach(U5D_TARGET IN LISTS U5D_TARGETS)
target_include_directories(${U5D_TARGET} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${SDL3_INCLUDE_DIRS}
    ${SDL3_MIXER_INCLUDE_DIRS}
)

target_link_directories(${U5D_TARGET} PRIVATE
    ${SDL3_LIBRARY_DIRS}
    ${SDL3_MIXER_LIBRARY_DIRS}
)

target_link_libraries(${U5D_TARGET} PRIVATE
    ${SDL3_LIBRARIES}
    ${SDL3_MIXER_LIBRARIES}
)
if(IMPERA_BUNDLED_SDL)
    target_link_libraries(${U5D_TARGET} PRIVATE SDL3::SDL3-static SDL3_mixer::SDL3_mixer-static)
endif()
if(MSVC)
    target_compile_definitions(${U5D_TARGET} PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()
if(UNIX)
    target_link_libraries(${U5D_TARGET} PRIVATE m)
endif()
endforeach()

option(IMPERA_BUILD_WORKSHOP "Build the native Qt modding application" OFF)
if(IMPERA_BUILD_WORKSHOP)
    enable_language(CXX)
    add_subdirectory(workshop)
endif()
