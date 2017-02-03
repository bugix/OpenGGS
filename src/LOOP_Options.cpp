#include "globals.h"

Options_Def Options;

// ##############################################
// ##############################################
// ##############################################

void LOOP_Options()
{
  int GameModeTemp = GV.Mode;
  GV.Mode = MODE_OPTIONS;
  Menu.Active = 0;

  Menu.MenuEntriesOptions = 16;
  Menu.ActiveOptions = 0;

  Options.x_off = 20;
  Options.y_off = 20;

  while(!QuitProgram && !QuitToMenu)
  {
    getInput();
    INPUT_General();

    Menu.Active = Menu.ActiveOptions;
    Menu.MenuEntries = Menu.MenuEntriesOptions;

    if(Key_ESCAPE_pressed || Joy_ESCAPE_pressed){QuitToMenu = true;}

    if(Key_RIGHT_pressed || Joy_RIGHT_pressed)
    {
      AUDIO_Sound_Play(AUDIO_CLICK);
      Menu.ActiveOptions += 1;
      if(Menu.ActiveOptions > Menu.MenuEntriesOptions-1){Menu.ActiveOptions = Menu.MenuEntriesOptions-1;}
    }

    if(Key_LEFT_pressed || Joy_LEFT_pressed)
    {
      AUDIO_Sound_Play(AUDIO_CLICK);
      Menu.ActiveOptions -= 1;
      if(Menu.ActiveOptions < 0){Menu.ActiveOptions = 0;}
    }

    if(Key_DOWN_pressed || Joy_DOWN_pressed)
    {
      AUDIO_Sound_Play(AUDIO_CLICK);
      if(Menu.ActiveOptions < Menu.MenuEntriesOptions-Menu.Cols){Menu.ActiveOptions = Menu.ActiveOptions + Menu.Cols;}

    }

    if(Key_UP_pressed || Joy_UP_pressed)
    {
      AUDIO_Sound_Play(AUDIO_CLICK);
      if(Menu.ActiveOptions > Menu.Cols-1){Menu.ActiveOptions = Menu.ActiveOptions - Menu.Cols;}
    }

    if(!Key_LALT &&(Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveOptions == 0 && GV.Resolution != RESOLUTION_640x480)  {SYSTEM_SetResolution(RESOLUTION_640x480);}
    if(!Key_LALT &&(Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveOptions == 1 && GV.Resolution != RESOLUTION_800x600)  {SYSTEM_SetResolution(RESOLUTION_800x600);}
    if(!Key_LALT &&(Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveOptions == 2 && GV.Resolution != RESOLUTION_1280x720) {SYSTEM_SetResolution(RESOLUTION_1280x720);}
    if(!Key_LALT &&(Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveOptions == 3) {toggleScreenmode();}
    if(!Key_LALT &&(Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveOptions == 4) {AUDIO_Volume_Change_Music(VolumePercentage_Music += 10, true); AUDIO_Sound_Play(AUDIO_CLICK);}
    if(!Key_LALT &&(Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveOptions == 5) {AUDIO_Volume_Change_Music(VolumePercentage_Music -= 10, true); AUDIO_Sound_Play(AUDIO_CLICK);}
    if(!Key_LALT &&(Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveOptions == 6) {AUDIO_Volume_Change_Sound(VolumePercentage_Sound += 10, true); AUDIO_Sound_Play(AUDIO_CLICK);}
    if(!Key_LALT &&(Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveOptions == 7) {AUDIO_Volume_Change_Sound(VolumePercentage_Sound -= 10, true); AUDIO_Sound_Play(AUDIO_CLICK);}
    if(!Key_LALT &&(Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveOptions == 8) {Mix_HaltMusic();
                                                                               GV.Mode = MODE_EDITOR_TILES;
                                                                               LOOP_Editor_Tiles();
                                                                               GV.Mode = MODE_OPTIONS;
                                                                               QuitToMenu = false;}
    if(!Key_LALT &&(Key_ENTER_pressed || Joy_OK_pressed) && Menu.ActiveOptions == 9) {GV.RandomLevels = !GV.RandomLevels; STAGES_Import();}
    Update_Screen();  // draw the scene
  }
  GV.Mode = GameModeTemp;
  Options_Save();
  getInput();  // make sure no "pressed key" is carried over to the menu...
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Options_Draw()
{
  int x;
  int Colour = 0;
  SDL_Rect SrcRect;
  SDL_Rect DstRect;

  SrcRect.x = 0;
  SrcRect.y = 208;
  SrcRect.w = 128;
  SrcRect.h = 96;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;


  for(x=0;x<Menu.MenuEntries;x++)
  {
    DstRect.x = Menu.x[x];
    DstRect.y = Menu.y[x];
    SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  }

  SrcRect.x = 128;
  DstRect.x = Menu.x[Menu.Active];
  DstRect.y = Menu.y[Menu.Active];
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );

  Colour = 0;
  if(GV.Resolution == RESOLUTION_640x480) {Colour = 3;}
  SrcRect.x = 320;
  SrcRect.y = 272;
  SrcRect.w = 32;
  SrcRect.h = 32;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Menu.x[0]+86;
  DstRect.y = Menu.y[0]+56;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(Menu.x[0]+10,Menu.y[0]+10,Colour,0,"Resolution");
  Print(Menu.x[0]+10,Menu.y[0]+22,Colour,0,"640x480");
  Print(Menu.x[0]+10,Menu.y[0]+34,2,0,"4x3");

  Colour = 0;
  if(GV.Resolution == RESOLUTION_800x600) {Colour = 3;}
  SrcRect.x = 320;
  SrcRect.y = 272;
  SrcRect.w = 32;
  SrcRect.h = 32;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Menu.x[1]+86;
  DstRect.y = Menu.y[1]+56;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(Menu.x[1]+10,Menu.y[1]+10,Colour,0,"Resolution");
  Print(Menu.x[1]+10,Menu.y[1]+22,Colour,0,"800x600");
  Print(Menu.x[1]+10,Menu.y[1]+34,2,0,"4x3");

  Colour = 0;
  if(GV.Resolution == RESOLUTION_1280x720) {Colour = 3;}
  SrcRect.x = 320;
  SrcRect.y = 240;
  SrcRect.w = 32;
  SrcRect.h = 32;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Menu.x[2]+86;
  DstRect.y = Menu.y[2]+56;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(Menu.x[2]+10,Menu.y[2]+10,Colour,0,"Resolution");
  Print(Menu.x[2]+10,Menu.y[2]+22,Colour,0,"1280x720");
  Print(Menu.x[2]+10,Menu.y[2]+34,2,0,"16x9");

  Colour = 0;
  Print(Menu.x[3]+10,Menu.y[3]+10,Colour,0,"Windowed/");
  Print(Menu.x[3]+10,Menu.y[3]+22,Colour,0,"Fullscreen");

  Colour = 0;
  SrcRect.x = 352;
  SrcRect.y = 208;
  SrcRect.w = 32;
  SrcRect.h = 32;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Menu.x[4]+86;
  DstRect.y = Menu.y[4]+56;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  SrcRect.y = 272;
  DstRect.x = Menu.x[4]+50;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(Menu.x[4]+10,Menu.y[4]+10,Colour,0,"Music");
  Print(Menu.x[4]+10,Menu.y[4]+22,Colour,0,"Volume ++");
  Print(Menu.x[4]+10,Menu.y[4]+34,2,0,"(Page Up)");

  Colour = 0;
  SrcRect.x = 352;
  SrcRect.y = 240;
  SrcRect.w = 32;
  SrcRect.h = 32;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Menu.x[5]+86;
  DstRect.y = Menu.y[5]+56;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  SrcRect.y = 272;
  DstRect.x = Menu.x[5]+50;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(Menu.x[5]+10,Menu.y[5]+10,Colour,0,"Music");
  Print(Menu.x[5]+10,Menu.y[5]+22,Colour,0,"Volume --");
  Print(Menu.x[5]+10,Menu.y[5]+34,2,0,"(Page Down)");

  Colour = 0;
  SrcRect.x = 352;
  SrcRect.y = 208;
  SrcRect.w = 32;
  SrcRect.h = 32;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Menu.x[6]+86;
  DstRect.y = Menu.y[6]+56;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(Menu.x[6]+10,Menu.y[6]+10,Colour,0,"Sound");
  Print(Menu.x[6]+10,Menu.y[6]+22,Colour,0,"Volume ++");
  Print(Menu.x[6]+10,Menu.y[6]+34,2,0,"(NumPad +)");

  Colour = 0;
  SrcRect.x = 352;
  SrcRect.y = 240;
  SrcRect.w = 32;
  SrcRect.h = 32;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = Menu.x[7]+86;
  DstRect.y = Menu.y[7]+56;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(Menu.x[7]+10,Menu.y[7]+10,Colour,0,"Sound");
  Print(Menu.x[7]+10,Menu.y[7]+22,Colour,0,"Volume --");
  Print(Menu.x[7]+10,Menu.y[7]+34,2,0,"(NumPad -)");

  Colour = 0;
  Print(Menu.x[8]+10,Menu.y[8]+10,Colour,0,"Edit Tiles");

  Colour = 0;
  Print(Menu.x[9]+10,Menu.y[9]+10,Colour,0,"Randomly");
  Print(Menu.x[9]+10,Menu.y[9]+22,Colour,0,"Generated");
  Print(Menu.x[9]+10,Menu.y[9]+34,Colour,0,"Levels");
  if(!GV.RandomLevels)
  {
    Print(Menu.x[9]+10,Menu.y[9]+46,Colour,0,"OFF");
  }
  if(GV.RandomLevels)
  {
    Print(Menu.x[9]+10,Menu.y[9]+46,Colour,0,"ON");
  }



}
