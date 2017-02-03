#include "globals.h"

Text_Offset_Def StageFile_Load;
void Load_Stagefile(int StagefileNumber);

// ##############################################
// ##############################################
// ##############################################

void LOOP_Stagefile_Load()
{
  int GameModeTemp = GV.Mode;
  GV.Mode = MODE_STAGEFILE_LOAD;
  Menu.MenuEntriesFileLoad = 16;
  Menu.ActiveFileLoad = 0;
  Mix_HaltMusic();

  StageFile_Load.x_off = 20;
  StageFile_Load.y_off = 20;

  while(!QuitProgram && !QuitToMenu)
  {
    getInput();
    INPUT_General();

    Menu.Active = Menu.ActiveFileLoad;
    Menu.MenuEntries = Menu.MenuEntriesFileLoad;

    if(Key_ESCAPE_pressed || Joy_ESCAPE_pressed){QuitToMenu = true;}

    if(Key_RIGHT_pressed || Joy_RIGHT_pressed)
    {
      AUDIO_Sound_Play(AUDIO_CLICK);
      Menu.ActiveFileLoad += 1;
      if(Menu.ActiveFileLoad > Menu.MenuEntriesFileLoad-1){Menu.ActiveFileLoad = Menu.MenuEntriesFileLoad-1;}
    }

    if(Key_LEFT_pressed || Joy_LEFT_pressed)
    {
      AUDIO_Sound_Play(AUDIO_CLICK);
      Menu.ActiveFileLoad -= 1;
      if(Menu.ActiveFileLoad < 0){Menu.ActiveFileLoad = 0;}
    }

    if(Key_DOWN_pressed || Joy_DOWN_pressed)
    {
      AUDIO_Sound_Play(AUDIO_CLICK);
      if(Menu.ActiveFileLoad < Menu.MenuEntriesFileLoad-Menu.Cols){Menu.ActiveFileLoad = Menu.ActiveFileLoad + Menu.Cols;}
    }

    if(Key_UP_pressed || Joy_UP_pressed)
    {
      AUDIO_Sound_Play(AUDIO_CLICK);
      if(Menu.ActiveFileLoad > Menu.Cols-1){Menu.ActiveFileLoad = Menu.ActiveFileLoad - Menu.Cols;}
    }

    if(!Key_LALT)
    {
      if(Key_ENTER_pressed || Joy_OK_pressed) {GV.RandomLevels = false; Load_Stagefile(Menu.ActiveFileLoad+1);}
    }

    Update_Screen();  // draw the scene
  }
  GV.Mode = GameModeTemp;
  getInput();  // make sure no "pressed key" is carried over to the menu...
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Stagefile_Load_Draw()
{
  int x;
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


  SrcRect.x = 256;
  SrcRect.y = 208;
  SrcRect.w = 32;
  SrcRect.h = 32;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;

  for(x=0;x<Menu.MenuEntries;x++)
  {
    DstRect.x = Menu.x[x]+86;
    DstRect.y = Menu.y[x]+56;
    SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
    Print(Menu.x[x-1]+10,Menu.y[x-1]+10,0,0,FileName.StageShort[x]);
  }
}

// ##############################################
// ##############################################
// ##############################################

void Load_Stagefile(int StagefileNumber)
{
  if(strncmp("---", FileName.Stage[StagefileNumber], 2) != 0)
  {
    snprintf(FileName.Stage[0], sizeof(char) * 128, FileName.Stage[StagefileNumber]);
    AUDIO_Sound_Play(AUDIO_DISK);
    STAGES_Import();
    QuitToMenu = true;
  }
}

// ##############################################
// ##############################################
// ##############################################

