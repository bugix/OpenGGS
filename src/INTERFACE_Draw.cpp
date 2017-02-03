#include "globals.h"

// ##############################################
// ##############################################
// ##############################################

void INTERFACE_Tile_Draw(int x, int y, int Number)
{
  SDL_Rect SrcRect;
  SDL_Rect DstRect;

  SrcRect.x = TileType[Number].x;
  SrcRect.y = TileType[Number].y;
  SrcRect.w = TS.Tile_Width;
  SrcRect.h = TS.Tile_Height;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = x;
  DstRect.y = y;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
}

// ##############################################
// ##############################################
// ##############################################

void OVERLAY_Volume_Draw_Music()
{
  if(ShowVolume_Music>0)
  {
    int VolumePosX = GV.Screen_Width-52;
    int VolumePosY = 4;
    SDL_SetRenderDrawColor(gRenderer, 75, 75, 75, 255);

    SDL_Rect FillRect1 = {VolumePosX, VolumePosY, 4, 212 };
    SDL_RenderFillRect(gRenderer, &FillRect1);

    SDL_Rect FillRect2 = {VolumePosX+44, VolumePosY, 4, 212 };
    SDL_RenderFillRect(gRenderer, &FillRect2);

    SDL_Rect FillRect3 = {VolumePosX, VolumePosY, 48, 4 };
    SDL_RenderFillRect(gRenderer, &FillRect3);

    SDL_Rect FillRect4 = {VolumePosX, VolumePosY+212, 48, 4 };
    SDL_RenderFillRect(gRenderer, &FillRect4);

    SDL_Rect FillRect5 = {VolumePosX+8, VolumePosY+208, 32, -(2*VolumePercentage_Music) };
    SDL_RenderFillRect(gRenderer, &FillRect5);
  }
}

// ##############################################
// ##############################################
// ##############################################

void OVERLAY_Volume_Draw_Sound()
{
  if(ShowVolume_Sound>0)
  {
    int VolumePosX = GV.Screen_Width-52;
    int VolumePosY = 4;
    SDL_SetRenderDrawColor(gRenderer, 100, 100, 100, 255);

    SDL_Rect FillRect1 = {VolumePosX, VolumePosY, 4, 212 };
    SDL_RenderFillRect(gRenderer, &FillRect1);

    SDL_Rect FillRect2 = {VolumePosX+44, VolumePosY, 4, 212 };
    SDL_RenderFillRect(gRenderer, &FillRect2);

    SDL_Rect FillRect3 = {VolumePosX, VolumePosY, 48, 4 };
    SDL_RenderFillRect(gRenderer, &FillRect3);

    SDL_Rect FillRect4 = {VolumePosX, VolumePosY+212, 48, 4 };
    SDL_RenderFillRect(gRenderer, &FillRect4);

    SDL_Rect FillRect5 = {VolumePosX+8, VolumePosY+208, 32, -(2*VolumePercentage_Sound) };
    SDL_RenderFillRect(gRenderer, &FillRect5);
  }
}

// ##############################################
// ##############################################
// ##############################################
