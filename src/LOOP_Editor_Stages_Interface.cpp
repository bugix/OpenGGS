#include "globals.h"

void LOOP_Editor_Stages_Draw_Interface_Tile(int x, int y, int TileNumber);

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_Draw_Interface()
{
  if(ME.ShowInterface)
  {
    SDL_SetRenderDrawColor(gRenderer, 100, 100, 100, 255);
    SDL_Rect outlineRect = {0, 0, GV.Screen_Width, 416}; //GV.Screen_Height-200};
    SDL_RenderFillRect(gRenderer, &outlineRect);
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    SDL_Rect outlineRect2 = {0, 416, GV.Screen_Width, 3};
    SDL_RenderFillRect(gRenderer, &outlineRect2);

    if(!ME.SingleTileMode && ME.ElementGroup == 1)
    {
      Print(10,10,0,0,"Basic Elements");
      LOOP_Editor_Stages_Draw_Interface_Tile(10,30,501); // BREAKABLE
      LOOP_Editor_Stages_Draw_Interface_Tile(10,62,480); Print(10,80,2,0,"POWER");
      LOOP_Editor_Stages_Draw_Interface_Tile(10,94,560); Print(15,112,2,0,"COIN");
      LOOP_Editor_Stages_Draw_Interface_Tile(10,126,640); Print(10,144,2,0,"COINS");
      LOOP_Editor_Stages_Draw_Interface_Tile(10,158,250); //Print(62,162,0,0,"LAVA");
      LOOP_Editor_Stages_Draw_Interface_Tile(10,174,514); //Print(108,194,0,0,"BARREL");
      LOOP_Editor_Stages_Draw_Interface_Tile(10,222,10); //Print(78,226,0,0,"FLAMES");
      LOOP_Editor_Stages_Draw_Interface_Tile(10,238,80); Print(14,256,2,0,"WARP");
      LOOP_Editor_Stages_Draw_Interface_Tile(10,270,6); //Print(78,280,0,0,"FIRE");
      LOOP_Editor_Stages_Draw_Interface_Tile(10,302,32); //Print(62,312,0,0,"SPIKE");
      LOOP_Editor_Stages_Draw_Interface_Tile(10,350,3); //Print(426,88,0,0,"COIN");
      LOOP_Editor_Stages_Draw_Interface_Tile(10,382,630); //Print(426,88,0,0,"COIN");
      LOOP_Editor_Stages_Draw_Interface_Tile(10,398,633); //Print(426,88,0,0,"COIN");

      LOOP_Editor_Stages_Draw_Interface_Tile(110,30,581); Print(110,48,2,0,"STONE");

      LOOP_Editor_Stages_Draw_Interface_Tile(200,30,511); //Print(252,40,0,0,"BOX");
      LOOP_Editor_Stages_Draw_Interface_Tile(200,78,566); //Print(252,82,0,0,"CRUMBLE");
      LOOP_Editor_Stages_Draw_Interface_Tile(200,94,587); //Print(252,104,0,0,"UNBREAKABLE");
      LOOP_Editor_Stages_Draw_Interface_Tile(200,126,87); //Print(252,136,0,0,"PLANT");
      LOOP_Editor_Stages_Draw_Interface_Tile(200,158,50); //Print(252,168,0,0,"ORNAMENT");
      LOOP_Editor_Stages_Draw_Interface_Tile(200,206,104);//Print(284,216,0,0,"CLOUD");
      LOOP_Editor_Stages_Draw_Interface_Tile(200,238,16); //Print(268,248,0,0,"BARREL (2)");
      LOOP_Editor_Stages_Draw_Interface_Tile(200,302,83); //Print(268,312,0,0,"BARREL (3)");
      LOOP_Editor_Stages_Draw_Interface_Tile(200,334,636); //Print(252,338,0,0,"PIPE");
      LOOP_Editor_Stages_Draw_Interface_Tile(200,350,678); //UNBREAKABLE SQUARE
      LOOP_Editor_Stages_Draw_Interface_Tile(200,382,672); //BRICKS

      LOOP_Editor_Stages_Draw_Interface_Tile(300,14,674); //BRICKS (END LEFT)
      LOOP_Editor_Stages_Draw_Interface_Tile(300,46,676); //BRICKS (END RIGHT)
      LOOP_Editor_Stages_Draw_Interface_Tile(300,78,720); //EXIT 1
      LOOP_Editor_Stages_Draw_Interface_Tile(300,142,726); //EXIT 2
      LOOP_Editor_Stages_Draw_Interface_Tile(300,206,729); //EXIT 3
      LOOP_Editor_Stages_Draw_Interface_Tile(300,270,272); //EXIT 4
      LOOP_Editor_Stages_Draw_Interface_Tile(300,366,670); //DIRTY BRICKS
    }

    if(!ME.SingleTileMode && ME.ElementGroup == 2)
    {
      Print(10,10,0,0,"Other Elements");
      LOOP_Editor_Stages_Draw_Interface_Tile(10,30,775); //  GROUND 1
      LOOP_Editor_Stages_Draw_Interface_Tile(10,78,780); //  GROUND 2
      LOOP_Editor_Stages_Draw_Interface_Tile(10,126,783); // GROUND 3
      LOOP_Editor_Stages_Draw_Interface_Tile(10,174,788); // GROUND 4
      LOOP_Editor_Stages_Draw_Interface_Tile(10,222,791); // GROUND 5
      LOOP_Editor_Stages_Draw_Interface_Tile(10,270,794); // GROUND 6
      LOOP_Editor_Stages_Draw_Interface_Tile(10,318,797); // GROUND 7

      LOOP_Editor_Stages_Draw_Interface_Tile(150,30,160); //  PLANT 1
      LOOP_Editor_Stages_Draw_Interface_Tile(150,78,170); //  PLANT 2
      LOOP_Editor_Stages_Draw_Interface_Tile(150,110,177); // PLANT 3
      LOOP_Editor_Stages_Draw_Interface_Tile(150,158,181); // PLANT 4
      LOOP_Editor_Stages_Draw_Interface_Tile(150,206,186); // PLANT 5
      LOOP_Editor_Stages_Draw_Interface_Tile(150,254,60);  // PLANT 6
      LOOP_Editor_Stages_Draw_Interface_Tile(150,302,29);  // PLANT 7

      LOOP_Editor_Stages_Draw_Interface_Tile(320,30,269);  // FINAL COIN
    }

    if(!ME.SingleTileMode && ME.ElementGroup == 3)
    {
      Print(10,10,0,0,"Enemies");
      LOOP_Editor_Stages_Draw_Enemy_Selection();
    }

    if(!ME.SingleTileMode && ME.ElementGroup == 4)
    {
      Print(10,10,0,0,"Autogenerate-Functions");
      LOOP_Editor_Stages_Draw_Autocreate_Functions();
    }

    if(ME.SingleTileMode)
    {
      SDL_Rect outlineRect2 = {0, 61, GV.Screen_Width, 3};
      SDL_RenderFillRect(gRenderer, &outlineRect2);
      SDL_Rect SrcRect;
      SDL_Rect DstRect;
      SrcRect.x = 0;
      SrcRect.y = 0;
      SrcRect.w = TS.Width_Pixels;
      SrcRect.h = 352; // 288
      DstRect.w = SrcRect.w;
      DstRect.h = SrcRect.h;
      DstRect.x = 0;
      DstRect.y = 64;
      SDL_RenderCopyEx(gRenderer, TilesTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
      int x = (ME.CurrentTileType%TS.Width);
       int y = (((ME.CurrentTileType-x)/TS.Width)*TS.Tile_Height)+64;
      x = x*TS.Tile_Width;
      INTERFACE_Tile_Draw(x, y, INTERFACE_MARK_GRAB);
    }
  }

  if(!ME.ShowInterface)
  {
    Print(10,10,0,0,"Stage");
    PrintInt(70,10,0,0,ME.Stage);
    Print(10,22,2,0, "F1 - Toggle Interface");
    Print(10,34,2,0, "F2 - Toggle Grid");
    Print(10,46,2,0, "F3 - Next Stage");
    Print(10,58,2,0, "F4 - Previous Stage");
    Print(10,70,2,0, "F5 - Randomly generate stage");
    Print(240,22,2,0,"CTRL+S to save");
    if(ME.SingleTileMode) {Print(240,34,2,0, "F11 - Single Tile Mode");}
    if(!ME.SingleTileMode){Print(240,34,2,0, "F11 - Element Mode");}

    if(ME.Platform_inUse){Print(10,82,0,0, "Platform in use");}
  }

  if(ME.ShowInterface && !ME.SingleTileMode && ME.ElementGroup == 1)
  {
    Print(460,70,0,0, "< Colour 1");
    Print(460,82,0,0, "< Colour 2");
    Print(460,94,0,0, "< Colour 3");
    Print(460,106,0,0, "< Colour 4");
    if(ME.TileType == 0)Print(460,70,0,0, ">");
    if(ME.TileType == 1)Print(460,82,0,0, ">");
    if(ME.TileType == 2)Print(460,94,0,0, ">");
    if(ME.TileType == 3)Print(460,106,0,0, ">");

    Print(460,154,0,0, "< Platform");
    if(ME.Platform_inUse)Print(460,154,0,0, ">");

    if(ME.Platform_inUse){Print(460,166,0,0, "< Reset Platform");}

    Print(460,190,0,0, "< Outdoors");
    if(ME.BackgroundColour == 0)Print(460,190,0,0, ">");
    Print(460,202,0,0, "< Indoors");
    if(ME.BackgroundColour == 1)Print(460,202,0,0, ">");


    //Print(400,46,2,0, "F7 - Square Blocks");
  }

  if(ME.ShowInterface && !ME.SingleTileMode)
  {
  SDL_Rect SrcRect;
  SDL_Rect DstRect;

  SrcRect.x = 0;
  SrcRect.y = 160;
  SrcRect.w = 48;
  SrcRect.h = 48;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = 454;
  DstRect.y = 10;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );

  SrcRect.x = 48;
  DstRect.x = 512;
  DstRect.y = 10;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  }

}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_Pick_TileType()
{
  if(!ME.SingleTileMode && ME.ElementGroup == 1)
  {
    if(MouseX > 9 && MouseX < 9+(6*TS.Tile_Width))  // FIRST COLOUMN
    {
      if(MouseY > 29 && MouseY < 29+(2*TS.Tile_Height))  {ME.CurrentTileType = 501;}
      if(MouseY > 61 && MouseY < 61+(2*TS.Tile_Height))  {ME.CurrentTileType = 480;}
      if(MouseY > 93 && MouseY < 93+(2*TS.Tile_Height))  {ME.CurrentTileType = 560;}
      if(MouseY > 125 && MouseY < 125+(2*TS.Tile_Height)){ME.CurrentTileType = 640;}
      if(MouseY > 157 && MouseY < 157+(1*TS.Tile_Height)){ME.CurrentTileType = 250;} // LAVA
      if(MouseY > 173 && MouseY < 173+(3*TS.Tile_Height)){ME.CurrentTileType = 514;} // BARREL
      if(MouseY > 221 && MouseY < 221+(1*TS.Tile_Height)){ME.CurrentTileType = 10;} // LITTLE FLAMES
      if(MouseY > 237 && MouseY < 237+(2*TS.Tile_Height)){ME.CurrentTileType = 80;} // WARP BLOCK
      if(MouseY > 269 && MouseY < 269+(2*TS.Tile_Height)){ME.CurrentTileType = 6;} // FIRE
      if(MouseY > 301 && MouseY < 301+(3*TS.Tile_Height)){ME.CurrentTileType = 32;} // SPIKE
      if(MouseY > 349 && MouseY < 349+(2*TS.Tile_Height)){ME.CurrentTileType = 3;} // COIN
      if(MouseY > 381 && MouseY < 381+(2*TS.Tile_Height)){ME.CurrentTileType = 630;} // BRIDGE 1
      if(MouseY > 397 && MouseY < 397+(2*TS.Tile_Height)){ME.CurrentTileType = 633;} // BRIDGE 1
    }

    if(MouseX > 109 && MouseX < 109+(3*TS.Tile_Width))  // SECOND COLOUMN
    {
      if(MouseY > 29 && MouseY < 29+(2*TS.Tile_Height))  {ME.CurrentTileType = 581;}
    }

    if(MouseX > 199 && MouseX < 199+(6*TS.Tile_Width))  // THIRD COLOUMN
    {
      if(MouseY > 29 && MouseY < 29+(3*TS.Tile_Height))  {ME.CurrentTileType = 511;}
      if(MouseY > 77 && MouseY < 77+(1*TS.Tile_Height))  {ME.CurrentTileType = 566;} // CRUMBLE
      if(MouseY > 93 && MouseY < 93+(2*TS.Tile_Height))  {ME.CurrentTileType = 587;} // UNBREAKABLE
      if(MouseY > 125 && MouseY < 125+(2*TS.Tile_Height)){ME.CurrentTileType = 87;} // PLANT
      if(MouseY > 157 && MouseY < 157+(3*TS.Tile_Height)){ME.CurrentTileType = 50;} // ORNAMENT
      if(MouseY > 205 && MouseY < 205+(2*TS.Tile_Height)){ME.CurrentTileType = 104;} // CLOUD
      if(MouseY > 237 && MouseY < 237+(4*TS.Tile_Height)){ME.CurrentTileType = 16;} // BARREL (NARROW)
      if(MouseY > 301 && MouseY < 301+(2*TS.Tile_Height)){ME.CurrentTileType = 83;} // BARREL (FLAT)
      if(MouseY > 333 && MouseY < 333+(1*TS.Tile_Height)){ME.CurrentTileType = 636;} // PIPE
      if(MouseY > 349 && MouseY < 349+(2*TS.Tile_Height)){ME.CurrentTileType = 678;} // UNBREAKABLE SQUARE
      if(MouseY > 381 && MouseY < 381+(2*TS.Tile_Height)){ME.CurrentTileType = 672;} // BRICKS
    }

    if(MouseX > 299 && MouseX < 299+(8*TS.Tile_Width))  // FORTH COLOUMN
    {
      if(MouseY > 16 && MouseY < 16+(2*TS.Tile_Height))  {ME.CurrentTileType = 674;} // BRICKS (END LEFT)
      if(MouseY > 48 && MouseY < 48+(2*TS.Tile_Height))  {ME.CurrentTileType = 676;} // BRICKS (END RIGHT)
      if(MouseY > 77 && MouseY < 77+(4*TS.Tile_Height))  {ME.CurrentTileType = 720;} // EXIT 1
      if(MouseY > 141 && MouseY < 141+(4*TS.Tile_Height))  {ME.CurrentTileType = 726;} // EXIT 2
      if(MouseY > 205 && MouseY < 205+(4*TS.Tile_Height))  {ME.CurrentTileType = 729;} // EXIT 3
      if(MouseY > 269 && MouseY < 269+(6*TS.Tile_Height))  {ME.CurrentTileType = 272;} // EXIT 4
      if(MouseY > 365 && MouseY < 365+(4*TS.Tile_Height))  {ME.CurrentTileType = 670;} // EXIT 4
    }
  }

  if(!ME.SingleTileMode && ME.ElementGroup == 2)
  {
    if(MouseX > 9 && MouseX < 9+(6*TS.Tile_Width))  // FIRST COLOUMN
    {
      if(MouseY > 29 && MouseY < 29+(3*TS.Tile_Height))  {ME.CurrentTileType = 775;} // GROUND 1
      if(MouseY > 77 && MouseY < 77+(3*TS.Tile_Height))  {ME.CurrentTileType = 780;} // GROUND 2
      if(MouseY > 125 && MouseY < 125+(3*TS.Tile_Height)){ME.CurrentTileType = 783;} // GROUND 3
      if(MouseY > 173 && MouseY < 173+(3*TS.Tile_Height)){ME.CurrentTileType = 788;} // GROUND 4
      if(MouseY > 221 && MouseY < 221+(3*TS.Tile_Height)){ME.CurrentTileType = 791;} // GROUND 5
      if(MouseY > 269 && MouseY < 269+(3*TS.Tile_Height)){ME.CurrentTileType = 794;} // GROUND 6
      if(MouseY > 317 && MouseY < 317+(3*TS.Tile_Height)){ME.CurrentTileType = 797;} // GROUND 7
    }

    if(MouseX > 149 && MouseX < 149+(10*TS.Tile_Width))  // SECOND COLOUMN
    {
      if(MouseY > 29 && MouseY < 29+(3*TS.Tile_Height))  {ME.CurrentTileType = 160;} // PLANT 1
      if(MouseY > 77 && MouseY < 77+(2*TS.Tile_Height))  {ME.CurrentTileType = 170;} // PLANT 2
      if(MouseY > 109 && MouseY < 109+(3*TS.Tile_Height)){ME.CurrentTileType = 177;} // PLANT 3
      if(MouseY > 157 && MouseY < 157+(3*TS.Tile_Height)){ME.CurrentTileType = 181;} // PLANT 4
      if(MouseY > 205 && MouseY < 205+(3*TS.Tile_Height)){ME.CurrentTileType = 186;} // PLANT 5
      if(MouseY > 253 && MouseY < 253+(3*TS.Tile_Height)){ME.CurrentTileType = 60;}  // PLANT 6
      if(MouseY > 301 && MouseY < 301+(5*TS.Tile_Height)){ME.CurrentTileType = 29;}  // PLANT 7
    }

    if(MouseX > 319 && MouseX < 319+(3*TS.Tile_Width))  // THIRD COLOUMN
    {
      if(MouseY > 29 && MouseY < 29+(5*TS.Tile_Height))  {ME.CurrentTileType = 269;} // FINAL COIN
    }
  }


  if(!ME.SingleTileMode && ME.ElementGroup == 3)
  {
    if(MouseY > 90 && MouseY < 170)  // FIRST COLOUMN
    {
      if(MouseX > 50 && MouseX < 150)  {if(ME.CurrentEnemyType == 1){ME.CurrentEnemyType = 0;} else {ME.CurrentEnemyType = 1;}}
      if(MouseX > 150 && MouseX < 250) {if(ME.CurrentEnemyType == 2){ME.CurrentEnemyType = 0;} else {ME.CurrentEnemyType = 2;}}
      if(MouseX > 250 && MouseX < 350) {if(ME.CurrentEnemyType == 3){ME.CurrentEnemyType = 0;} else {ME.CurrentEnemyType = 3;}}
      if(MouseX > 350 && MouseX < 450) {if(ME.CurrentEnemyType == 4){ME.CurrentEnemyType = 0;} else {ME.CurrentEnemyType = 4;}}
      if(MouseX > 450 && MouseX < 550) {if(ME.CurrentEnemyType == 5){ME.CurrentEnemyType = 0;} else {ME.CurrentEnemyType = 5;}}
    }
    if(MouseY > 170 && MouseY < 250)  // FIRST COLOUMN
    {
      if(MouseX > 50 && MouseX < 150)  {if(ME.CurrentEnemyType == 6){ME.CurrentEnemyType = 0;} else {ME.CurrentEnemyType = 6;}}
      if(MouseX > 150 && MouseX < 250) {if(ME.CurrentEnemyType == 7){ME.CurrentEnemyType = 0;} else {ME.CurrentEnemyType = 7;}}
      if(MouseX > 250 && MouseX < 350) {if(ME.CurrentEnemyType == 8){ME.CurrentEnemyType = 0;} else {ME.CurrentEnemyType = 8;}}
      if(MouseX > 350 && MouseX < 450) {if(ME.CurrentEnemyType == 9){ME.CurrentEnemyType = 0;} else {ME.CurrentEnemyType = 9;}}
      if(MouseX > 450 && MouseX < 550) {if(ME.CurrentEnemyType == 10){ME.CurrentEnemyType = 0;} else {ME.CurrentEnemyType = 10;}}
    }
    if(MouseY > 250 && MouseY < 330)  // FIRST COLOUMN
    {
      if(MouseX > 50 && MouseX < 150)  {if(ME.CurrentEnemyType == 11){ME.CurrentEnemyType = 0;} else {ME.CurrentEnemyType = 11;}}
      if(MouseX > 150 && MouseX < 250) {if(ME.CurrentEnemyType == 12){ME.CurrentEnemyType = 0;} else {ME.CurrentEnemyType = 12;}}
      if(MouseX > 250 && MouseX < 350) {if(ME.CurrentEnemyType == 13){ME.CurrentEnemyType = 0;} else {ME.CurrentEnemyType = 13;}}
      if(MouseX > 350 && MouseX < 450) {if(ME.CurrentEnemyType == 14){ME.CurrentEnemyType = 0;} else {ME.CurrentEnemyType = 14;}}
      if(MouseX > 450 && MouseX < 550) {if(ME.CurrentEnemyType == 15){ME.CurrentEnemyType = 0;} else {ME.CurrentEnemyType = 15;}}
    }
  }

  if(!ME.SingleTileMode && ME.ElementGroup == 4)
  {
    if(MouseY > 64 && MouseY < 160)  // FIRST COLOUMN
    {
      if(MouseX > 8 && MouseX < 136)    {CREATOR_Stages_Clear(); CREATOR_Stages_Clear_Enemies();}
      if(MouseX > 144 && MouseX < 272)  {CREATOR_Stages_Clear(); CREATOR_Stages_Clear_Enemies(); CREATOR_Stages_Ground(ME.BackgroundColour);}
      if(MouseX > 280 && MouseX < 408)  {CREATOR_Stages_Clear_Enemies();}
      if(MouseX > 416 && MouseX < 544)  {CREATOR_Stages_Reset_Start_Positions();}


    }
  }

  if(!ME.SingleTileMode)
  {
    if(MouseY > 9 && MouseY < 58)  // SWITCH BETWEEN ME.ElementGroup
    {
      if(MouseX > 453 && MouseX < 503)  {ME.ElementGroup--; if(ME.ElementGroup<1){ME.ElementGroup = 4;}}
      if(MouseX > 511 && MouseX < 561)  {ME.ElementGroup++; if(ME.ElementGroup>4){ME.ElementGroup = 1;}}
    }
  }


  if(ME.SingleTileMode)
  {
    if(MouseY > 64 && MouseY < 416)
    {
      int Col = (int)(MouseX/TS.Tile_Width);
      int Row = (int)(MouseY/TS.Tile_Height)-4;
      ME.CurrentTileType = (Row * TS.Width)+Col;
    }
  }
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_Draw_Interface_Tile(int x, int y, int TileNumber)
{
  int El_Width, El_Height;

  for(El_Width = 0; El_Width < ElementWidth(TileNumber); El_Width++)
  {
    for(El_Height = 0; El_Height < ElementHeight(TileNumber); El_Height++)
    {
      TILE_Draw(x+(El_Width * TS.Tile_Width), y+(El_Height * TS.Tile_Height), TileNumber+El_Width+(El_Height*TS.Width));
    }
  }
  if(ME.CurrentTileType == TileNumber){INTERFACE_Tile_Draw(x, y, INTERFACE_MARK_GRAB);}
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_Draw_Enemy_Selection()
{
  SDL_Rect SrcRect;
  SDL_Rect DstRect;
  int x;

  int AnimationFrame;
  AnimationFrame = EV.Frame_4;

  for (x=1; x<16;x++)
  {
    if(x == 15){AnimationFrame = EV.Frame_7;}

    SrcRect.x = Enemy_Type[1].FrameX[NPC_LEFT][0][NPC_ALIVE];
    SrcRect.y = Enemy_Type[1].FrameY[NPC_LEFT][0][NPC_ALIVE];
    SrcRect.w = Enemy_Type[1].FrameW[NPC_LEFT][0][NPC_ALIVE];
    SrcRect.h = Enemy_Type[1].FrameH[NPC_LEFT][0][NPC_ALIVE];

    if(x < 16)
    {
      SrcRect.x = Enemy_Type[x].FrameX[NPC_LEFT][AnimationFrame][NPC_ALIVE];
      SrcRect.y = Enemy_Type[x].FrameY[NPC_LEFT][AnimationFrame][NPC_ALIVE];
      SrcRect.w = Enemy_Type[x].FrameW[NPC_LEFT][AnimationFrame][NPC_ALIVE];
      SrcRect.h = Enemy_Type[x].FrameH[NPC_LEFT][AnimationFrame][NPC_ALIVE];
    }

    DstRect.w = SrcRect.w;
    DstRect.h = SrcRect.h;
    if(x < 6)
    {
      DstRect.x = 50 + 100*(x-1)+(int)(SrcRect.w/2);
      DstRect.y = 160-SrcRect.h;
    }
    if(x > 5 && x < 11)
    {
      DstRect.x = 50 + 100*(x-6)+(int)(SrcRect.w/2);
      DstRect.y = 240-SrcRect.h;
    }
    if(x > 10 && x < 16)
    {
      DstRect.x = 50 + 100*(x-11)+(int)(SrcRect.w/2);
      DstRect.y = 320-SrcRect.h;
    }

    // DRAW ENEMY BACKGROUNDS
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    // MARK PICKED ENEMY
    if(ME.CurrentEnemyType == x){SDL_SetRenderDrawColor(gRenderer, 150, 150, 150, 255);}
    SDL_Rect outlineRect2 = {DstRect.x-(int)(SrcRect.w/2), DstRect.y+SrcRect.h-70, 99, 79};
    SDL_RenderFillRect(gRenderer, &outlineRect2);

    if(x == 12 || x == 13){DstRect.x -= (int)(SrcRect.w/2)-10;}
    SDL_RenderCopyEx(gRenderer, EnemiesTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );

  }

  //PrintInt(10,300,0,0,ME.CurrentTileType);
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_Draw_Autocreate_Functions()
{
  SDL_Rect SrcRect;
  SDL_Rect DstRect;
  SrcRect.x = 0;
  SrcRect.y = 208;
  SrcRect.w = 128;
  SrcRect.h = 96;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;

  DstRect.x = 8;
  DstRect.y = 64;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(DstRect.x+6,DstRect.y+6,0,0,"Erase all");

  DstRect.x = 144;
  DstRect.y = 64;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(DstRect.x+6,DstRect.y+6,0,0,"Erase all");
  Print(DstRect.x+6,DstRect.y+18,0,0,"and create");
  Print(DstRect.x+6,DstRect.y+30,0,0,"ground");

  DstRect.x = 280;
  DstRect.y = 64;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(DstRect.x+6,DstRect.y+6,0,0,"Erase all");
  Print(DstRect.x+6,DstRect.y+18,0,0,"enemies");

  DstRect.x = 416;
  DstRect.y = 64;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(DstRect.x+6,DstRect.y+6,0,0,"Reset Start");
  Print(DstRect.x+6,DstRect.y+18,0,0,"Positions");

  DstRect.x = 8;
  DstRect.y = 168;
  SDL_RenderCopyEx(gRenderer, InterfaceTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );
  Print(DstRect.x+6,DstRect.y+6,0,0,"Create");
  Print(DstRect.x+6,DstRect.y+18,0,0,"Random");
  Print(DstRect.x+6,DstRect.y+30,0,0,"Stage");


}
