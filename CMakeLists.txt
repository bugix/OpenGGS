cmake_minimum_required(VERSION 3.7)
project(OpenGGS)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${OpenGGS_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_MIXER_INCLUDE_DIR})

set(SOURCE_FILES
src/ANIMATION.cpp
src/GRAPHICS_Sprites_Draw.cpp
src/LOOP_Editor_Stages_Creator_Functions.cpp
src/LOOP_Stagefile_Load.cpp
src/STAGE_Draw.cpp
src/AUDIO.cpp
src/GRAPHICS_Sprites_Move.cpp
src/LOOP_Editor_Stages_Enemies.cpp
src/LOOP_Story.cpp
src/STAGE_Interface_Draw.cpp
src/CONTENT_Gametype_Load.cpp
src/GRAPHICS_Tiles_Animations.cpp
src/LOOP_Editor_Stages_Interface.cpp
src/PLAYER.cpp
src/SYSTEM_Debug_Infos.cpp
src/CONTENT_Stages_Load_Write.cpp
src/GRAPHICS_Tiles_Define.cpp
src/LOOP_Editor_Stages_Set_Elements.cpp
src/PLAYER_Collision_NonSolids.cpp
src/SYSTEM_Draw_Text.cpp
src/ENEMIES.cpp
src/GRAPHICS_Tiles_Draw.cpp
src/LOOP_Editor_Stages_Sprites.cpp
src/PLAYER_Collision_Solids.cpp
src/SYSTEM_Input_General.cpp
src/ENEMIES_Collision.cpp
src/GRAPHICS_Tiles_Elements.cpp
src/LOOP_Editor_Stages_Stage_Settings.cpp
src/PLAYER_Collision_Solids_Specials.cpp
src/SYSTEM_SDL_Textures.cpp
src/ENEMIES_Draw.cpp
src/GRAPHICS_Tiles_Switch_Tile.cpp
src/LOOP_Editor_Tiles.cpp
src/PLAYER_Collision_Sprites.cpp
src/SYSTEM_SDL_init.cpp
src/ENEMIES_Move.cpp
src/INTERFACE_Draw.cpp
src/LOOP_Gameloop.cpp
src/PLAYER_Draw.cpp
src/SYSTEM_SDL_input.cpp
src/GAME_ENVIRONMENT.cpp
src/LOOP_Credits.cpp
src/LOOP_Gameloop_Splashscreens.cpp
src/PLAYER_Jump.cpp
src/SYSTEM_Update_Screen.cpp
src/GRAPHICS_Sprites.cpp
src/LOOP_Editor_Stages.cpp
src/LOOP_Menu.cpp
src/PLAYER_Killed.cpp
src/SYSTEM_Vector_Operations.cpp
src/GRAPHICS_Sprites_Bullets.cpp
src/LOOP_Editor_Stages_Creator.cpp
src/LOOP_Options.cpp
src/PLAYER_Run.cpp
src/main.cpp
)

add_executable(openggs ${SOURCE_FILES})

target_link_libraries(openggs ${SDL2_LIBRARY}
                             ${SDL2_IMAGE_LIBRARIES}
                             ${SDL2_MIXER_LIBRARIES})

