#include "globals.h"

// ##############################################
// ##############################################
// ##############################################

void PC_Draw(int x, int y)
{
  SDL_Rect SrcRect;
  SDL_Rect DstRect;

  SrcRect.x = PC.FrameX[PC.Direction][PC.Stance][PC.Mode];
  SrcRect.y = PC.FrameY[PC.Direction][PC.Stance][PC.Mode];
  SrcRect.w = PC.FrameW[PC.Direction][PC.Stance][PC.Mode];
  SrcRect.h = PC.FrameH[PC.Direction][PC.Stance][PC.Mode];

  if(PC.Dead)
  {
    SrcRect.x = PC.FrameX[PC_DEAD][PC_DEAD][PC_DEAD];
    SrcRect.y = PC.FrameY[PC_DEAD][PC_DEAD][PC_DEAD];
    SrcRect.w = PC.FrameW[PC_DEAD][PC_DEAD][PC_DEAD];
    SrcRect.h = PC.FrameH[PC_DEAD][PC_DEAD][PC_DEAD];
  }

  if(PC.MorphingCounter != 0 && PC.Animation==1)
  {
    SrcRect.x = PC.FrameX[PC_MORPH][PC_MORPH1][PC_MODE3];
    SrcRect.y = PC.FrameY[PC_MORPH][PC_MORPH1][PC_MODE3];
    SrcRect.w = PC.FrameW[PC_MORPH][PC_MORPH1][PC_MODE3];
    SrcRect.h = PC.FrameH[PC_MORPH][PC_MORPH1][PC_MODE3];
  }

  if(PC.MorphingCounter != 0 && PC.Animation==2)
  {
    SrcRect.x = PC.FrameX[PC_MORPH][PC_MORPH2][PC_MODE3];
    SrcRect.y = PC.FrameY[PC_MORPH][PC_MORPH2][PC_MODE3];
    SrcRect.w = PC.FrameW[PC_MORPH][PC_MORPH2][PC_MODE3];
    SrcRect.h = PC.FrameH[PC_MORPH][PC_MORPH2][PC_MODE3];
  }




  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;

  DstRect.x = GV.Screen_Width/2-int(SrcRect.w/2);

  if(PC.PosX < GV.Screen_Width/2)
    {DstRect.x = PC.PosX-int(SrcRect.w/2);}

  DstRect.x = PC.PosX -int(SrcRect.w/2) - PC.StagePosX;

  DstRect.y = y-SrcRect.h;
  SDL_RenderCopyEx(gRenderer, PlayerTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );

  if(PC.ShowBorder)
  {
    SDL_SetRenderDrawColor(gRenderer, 50, 50, 50, 255);
    SDL_RenderDrawLine(gRenderer, DstRect.x+int(SrcRect.w/2), y-10, DstRect.x+int(SrcRect.w/2), y+10);
    SDL_Rect outlineRect = {DstRect.x, y-SrcRect.h, SrcRect.w, SrcRect.h };
    SDL_RenderDrawRect(gRenderer, &outlineRect);
  }
}

// ##############################################
// ##############################################
// ##############################################
