#include "globals.h"


// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_SPRITE_Platform_Set(int x, int y)
{
  if(ME.Platform_StartGrabbed){ME.Platform_Start_X = x; ME.Platform_Start_Y = y; ME.Platform_End_X = x; ME.DontSetATile = true;}
  if(ME.Platform_EndGrabbed){ME.Platform_End_Y = y; ME.DontSetATile = true;}
  if(ME.Platform_Start_Y < 2){ME.Platform_Start_Y = 2;}
  if(ME.Platform_End_Y > ME.Platform_Start_Y){ME.Platform_End_Y = ME.Platform_Start_Y-1;}

  ME.Platform_StartGrabbed = false;
  ME.Platform_EndGrabbed = false;

}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_SPRITE_Platform_Draw()
{
  SDL_Rect SrcRect;
  SDL_Rect DstRect;

  SrcRect.x = Platform.x;
  SrcRect.y = Platform.y;


  SrcRect.w = Platform.w;
  SrcRect.h = Platform.h;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = (ME.Platform_Start_X*TS.Tile_Width) - ME.StagePosX;
  DstRect.y = (ME.Platform_Start_Y)*TS.Tile_Height;
  SDL_RenderCopyEx(gRenderer, TilesTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  INTERFACE_Tile_Draw(DstRect.x+TS.Tile_Width, DstRect.y, INTERFACE_MARK_ARROW_UP);
  INTERFACE_Tile_Draw(DstRect.x+(7*TS.Tile_Width), DstRect.y, INTERFACE_MARK_ARROW_UP);

  if(!ME.Platform_StartGrabbed){INTERFACE_Tile_Draw(DstRect.x, DstRect.y, INTERFACE_MARK_GRAB);}
  if(ME.Platform_StartGrabbed){INTERFACE_Tile_Draw(DstRect.x, DstRect.y, INTERFACE_MARK_GRAB_ACTIVE);}

  DstRect.x = (ME.Platform_End_X*TS.Tile_Width) - ME.StagePosX;
  DstRect.y = (ME.Platform_End_Y)*TS.Tile_Height;
  SDL_RenderCopyEx(gRenderer, TilesTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  INTERFACE_Tile_Draw(DstRect.x+TS.Tile_Width, DstRect.y, INTERFACE_MARK_ARROW_DOWN);
  INTERFACE_Tile_Draw(DstRect.x+(7*TS.Tile_Width), DstRect.y, INTERFACE_MARK_ARROW_DOWN);

  if(!ME.Platform_EndGrabbed){INTERFACE_Tile_Draw(DstRect.x, DstRect.y, INTERFACE_MARK_GRAB);}
  if(ME.Platform_EndGrabbed){INTERFACE_Tile_Draw(DstRect.x, DstRect.y, INTERFACE_MARK_GRAB_ACTIVE);}
}

// ##############################################
// ##############################################
// ##############################################
