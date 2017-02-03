#include "globals.h"

TileEditor_Type TE;
Uint32 timecounter_Scrolling;
void Mark_Nothing();
void Mark_Tiles();
void Tilesheet_Save();
void Change_Settings();
int MouseOverTileNumber;

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Tiles()
{
  TE.PosX = 0;
  TE.PosY = 100;
  Mark_Nothing();
  TE.MarkSolids = true;
  timecounter_Scrolling=SDL_GetTicks();

  // MAKE SURE IT'S WINDOWED AND 4:3
  if(GV.Resolution != RESOLUTION_640x480){SYSTEM_SetResolution(RESOLUTION_640x480);}
  if(CurrentScreenMode==1){toggleScreenmode();}

  while(!QuitProgram && !QuitToMenu)
  {
    getInput();
    INPUT_General();
    TE.ScrollX = 0;
    TE.ScrollY = 0;

    if(Key_ESCAPE_pressed){QuitToMenu = true;}

    //if(Key_F1_pressed) {GV.GameType = TYPE_C64;     GAMETYPE_Load();}
    //if(Key_F2_pressed) {GV.GameType = TYPE_OPENGGS; GAMETYPE_Load();}
    //if(Key_F3_pressed) {GV.GameType = TYPE_AMIGA;   GAMETYPE_Load();}

    if(Key_CTRL && Key_S_pressed)      {Tilesheet_Save(); AUDIO_Sound_Play(AUDIO_DISK);}
    if(Key_LEFT)                       {TE.ScrollX = 4;}
    if(Key_RIGHT)                      {TE.ScrollX = -4;}
    if(Key_UP)                         {TE.ScrollY = 4;}
    if(Key_DOWN)                       {TE.ScrollY = -4;}

    if(MouseButtonLeft_pressed)
    {
      if(MouseY > 100){Mark_Tiles();}
      if(MouseY < 100){Change_Settings();}
    }

    if(SDL_GetTicks() - timecounter_Scrolling > 5)
    {
      timecounter_Scrolling = SDL_GetTicks();
      //TE.PosX += TE.ScrollX;
      TE.PosY += TE.ScrollY;
      //if(TE.PosX > 0){TE.PosX = 0;}
      //if(TE.PosX < GV.Screen_Width-TS.Width_Pixels){TE.PosX = GV.Screen_Width-TS.Width_Pixels;}
      if(TE.PosY > 100){TE.PosY = 100;}
      if(TE.PosY < GV.Screen_Height-TS.Height_Pixels){TE.PosY = GV.Screen_Height-TS.Height_Pixels;}
    }

    Update_Screen();  // draw the scene
  }

  getInput();  // make sure no "pressed key" is carried over to the menu...
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Tiles_Interface_Draw()
{
  SDL_SetRenderDrawColor(gRenderer, 100, 100, 100, 255);
  SDL_Rect outlineRect = {0, 0, GV.Screen_Width, 100};
  SDL_RenderFillRect(gRenderer, &outlineRect);
  SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
  SDL_Rect outlineRect2 = {0, 97, GV.Screen_Width, 3};
  SDL_RenderFillRect(gRenderer, &outlineRect2);

  Print(10,10,0,0,"< Non-Solid");
  Print(10,22,0,0,"< Exit");
  Print(10,34,0,0,"< Lethal");
  Print(10,46,0,0,"< Fire");
  Print(10,58,0,0,"< Coin");
  Print(10,70,0,0,"< Coinblock");
  Print(10,82,0,0,"< Breakable");

  if(TE.MarkSolids)     {Print(10,10,0,0,">");}
  if(TE.MarkExits)      {Print(10,22,0,0,">");}
  if(TE.MarkLethals)    {Print(10,34,0,0,">");}
  if(TE.MarkFire)       {Print(10,46,0,0,">");}
  if(TE.MarkCoins)      {Print(10,58,0,0,">");}
  if(TE.MarkCoinBlocks) {Print(10,70,0,0,">");}
  if(TE.MarkBreakables) {Print(10,82,0,0,">");}

  Print(180,10,0,0,"< PowerUp Block");
  Print(180,22,0,0,"< Coinblock (Helmet)");
  Print(180,34,0,0,"< Colour Changing");
  Print(180,46,0,0,"< Sub-Stage Entrance");
  Print(180,58,0,0,"< Drop Stone");
  Print(180,70,0,0,"< Warp Stone");

  if(TE.MarkPowerUpBlocks)    {Print(180,10,0,0,">");}
  if(TE.MarkCoinBlocksHelmet) {Print(180,22,0,0,">");}
  if(TE.MarkColourChanging)   {Print(180,34,0,0,">");}
  if(TE.MarkSubStageEntrance)   {Print(180,46,0,0,">");}
  if(TE.MarkDropStone)        {Print(180,58,0,0,">");}
  if(TE.MarkWarpStone)        {Print(180,70,0,0,">");}


  Print(490,10,0,0,"CTRL+S to save");
}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Tiles_Draw()
{
  SDL_Rect SrcRect;
  SDL_Rect DstRect;

  SrcRect.x = 0;
  SrcRect.y = 0;
  SrcRect.w = TS.Width_Pixels;
  SrcRect.h = TS.Height_Pixels;
  DstRect.w = SrcRect.w;
  DstRect.h = SrcRect.h;
  DstRect.x = TE.PosX;
  DstRect.y = TE.PosY;
  SDL_RenderCopyEx(gRenderer, TilesTexture, &SrcRect, &DstRect, 0, NULL, SDL_FLIP_NONE );

  int j, i, k;
  for(j=0;j<TS.Height;j++)
  {
    for(i=0;i<TS.Width;i++)
    {
      k = i + (j * TS.Width);
      if(TE.MarkSolids && !TileType[k].Solid)         {INTERFACE_Tile_Draw((i*TS.Tile_Width)+TE.PosX, j*TS.Tile_Height+TE.PosY, INTERFACE_MARK_SOLID);}
      if(TE.MarkExits && TileType[k].Exit)            {INTERFACE_Tile_Draw((i*TS.Tile_Width)+TE.PosX, j*TS.Tile_Height+TE.PosY, INTERFACE_MARK_EXIT);}
      if(TE.MarkLethals && TileType[k].Lethal)        {INTERFACE_Tile_Draw((i*TS.Tile_Width)+TE.PosX, j*TS.Tile_Height+TE.PosY, INTERFACE_MARK_LETHAL);}
      if(TE.MarkFire && TileType[k].Fire)             {INTERFACE_Tile_Draw((i*TS.Tile_Width)+TE.PosX, j*TS.Tile_Height+TE.PosY, INTERFACE_MARK_FIRE);}
      if(TE.MarkCoins && TileType[k].Coin)            {INTERFACE_Tile_Draw((i*TS.Tile_Width)+TE.PosX, j*TS.Tile_Height+TE.PosY, INTERFACE_MARK_COIN);}
      if(TE.MarkCoinBlocks && TileType[k].CoinBlock)  {INTERFACE_Tile_Draw((i*TS.Tile_Width)+TE.PosX, j*TS.Tile_Height+TE.PosY, INTERFACE_MARK_COIN_BLOCK);}
      if(TE.MarkBreakables && TileType[k].Breakable)  {INTERFACE_Tile_Draw((i*TS.Tile_Width)+TE.PosX, j*TS.Tile_Height+TE.PosY, INTERFACE_MARK_BREAKABLE);}
      if(TE.MarkPowerUpBlocks && TileType[k].PowerUpBlock) {INTERFACE_Tile_Draw((i*TS.Tile_Width)+TE.PosX, j*TS.Tile_Height+TE.PosY, INTERFACE_MARK_POWERUP_BLOCK);}
      if(TE.MarkCoinBlocksHelmet && TileType[k].CoinBlockHelmet) {INTERFACE_Tile_Draw((i*TS.Tile_Width)+TE.PosX, j*TS.Tile_Height+TE.PosY, INTERFACE_MARK_COIN_BLOCK);}
      if(TE.MarkColourChanging && TileType[k].ColourChanging) {INTERFACE_Tile_Draw((i*TS.Tile_Width)+TE.PosX, j*TS.Tile_Height+TE.PosY, INTERFACE_MARK_COLOUR_CHANGING);}
      if(TE.MarkSubStageEntrance && TileType[k].SubStageEntrance) {INTERFACE_Tile_Draw((i*TS.Tile_Width)+TE.PosX, j*TS.Tile_Height+TE.PosY, INTERFACE_MARK_EXIT);}
      if(TE.MarkDropStone && TileType[k].DropStone) {INTERFACE_Tile_Draw((i*TS.Tile_Width)+TE.PosX, j*TS.Tile_Height+TE.PosY, INTERFACE_MARK_DROPSTONE);}
      if(TE.MarkWarpStone && TileType[k].WarpStone) {INTERFACE_Tile_Draw((i*TS.Tile_Width)+TE.PosX, j*TS.Tile_Height+TE.PosY, INTERFACE_MARK_WARPSTONE);}
    }
  }
  PrintInt(MouseX, MouseY+30, 0, 0, MouseOverTileNumber);
}

// ##############################################
// ##############################################
// ##############################################

void Change_Settings()
{
  if(MouseY > 9 && MouseY < 21 && MouseX > 9 && MouseX < 21)
  {
    Mark_Nothing();
    TE.MarkSolids = true;
  }
  if(MouseY > 21 && MouseY < 33 && MouseX > 9 && MouseX < 21)
  {
    Mark_Nothing();
    TE.MarkExits = true;
  }
  if(MouseY > 33 && MouseY < 45 && MouseX > 9 && MouseX < 21)
  {
    Mark_Nothing();
    TE.MarkLethals = true;
  }
  if(MouseY > 45 && MouseY < 57 && MouseX > 9 && MouseX < 21)
  {
    Mark_Nothing();
    TE.MarkFire = true;
  }
  if(MouseY > 57 && MouseY < 69 && MouseX > 9 && MouseX < 21)
  {
    Mark_Nothing();
    TE.MarkCoins = true;
  }
  if(MouseY > 69 && MouseY < 81 && MouseX > 9 && MouseX < 21)
  {
    Mark_Nothing();
    TE.MarkCoinBlocks = true;
  }
  if(MouseY > 81 && MouseY < 93 && MouseX > 9 && MouseX < 21)
  {
    Mark_Nothing();
    TE.MarkBreakables = true;
  }

  // SECOND COLUMN
  if(MouseY > 9 && MouseY < 21 && MouseX > 179 && MouseX < 191)
  {
    Mark_Nothing();
    TE.MarkPowerUpBlocks = true;
  }

  if(MouseY > 21 && MouseY < 33 && MouseX > 179 && MouseX < 191)
  {
    Mark_Nothing();
    TE.MarkCoinBlocksHelmet = true;
  }

  if(MouseY > 33 && MouseY < 45 && MouseX > 179 && MouseX < 191)
  {
    Mark_Nothing();
    TE.MarkColourChanging = true;
  }

  if(MouseY > 45 && MouseY < 57 && MouseX > 179 && MouseX < 191)
  {
    Mark_Nothing();
    TE.MarkSubStageEntrance = true;
  }

  if(MouseY > 57 && MouseY < 69 && MouseX > 179 && MouseX < 191)
  {
    Mark_Nothing();
    TE.MarkDropStone = true;
  }

  if(MouseY > 69 && MouseY < 81 && MouseX > 179 && MouseX < 191)
  {
    Mark_Nothing();
    TE.MarkWarpStone = true;
  }
}

// ##############################################
// ##############################################
// ##############################################

void Mark_Nothing()
{
  TE.MarkExits = false;
  TE.MarkSolids = false;
  TE.MarkLethals = false;
  TE.MarkFire = false;
  TE.MarkCoins = false;
  TE.MarkCoinBlocks = false;
  TE.MarkBreakables = false;
  TE.MarkPowerUpBlocks = false;
  TE.MarkCoinBlocksHelmet = false;
  TE.MarkColourChanging = false;
  TE.MarkSubStageEntrance = false;
  TE.MarkDropStone = false;
  TE.MarkWarpStone = false;
}

// ##############################################
// ##############################################
// ##############################################

void Mark_Tiles()
{
  int Col = (int)((MouseX-TE.PosX)/TS.Tile_Width);
  int Row = (int)((MouseY-TE.PosY)/TS.Tile_Height);
  int TileNumber = (Row * TS.Width)+Col;
  if(TE.MarkSolids){TileType[TileNumber].Solid = !TileType[TileNumber].Solid;}
  if(TE.MarkExits){TileType[TileNumber].Exit = !TileType[TileNumber].Exit;}
  if(TE.MarkLethals){TileType[TileNumber].Lethal = !TileType[TileNumber].Lethal;}
  if(TE.MarkFire){TileType[TileNumber].Fire = !TileType[TileNumber].Fire;}
  if(TE.MarkCoins){TileType[TileNumber].Coin = !TileType[TileNumber].Coin;}
  if(TE.MarkCoinBlocks){TileType[TileNumber].CoinBlock = !TileType[TileNumber].CoinBlock;}
  if(TE.MarkBreakables){TileType[TileNumber].Breakable = !TileType[TileNumber].Breakable;}
  if(TE.MarkPowerUpBlocks){TileType[TileNumber].PowerUpBlock = !TileType[TileNumber].PowerUpBlock;}
  if(TE.MarkCoinBlocksHelmet){TileType[TileNumber].CoinBlockHelmet = !TileType[TileNumber].CoinBlockHelmet;}
  if(TE.MarkColourChanging){TileType[TileNumber].ColourChanging = !TileType[TileNumber].ColourChanging;}
  if(TE.MarkSubStageEntrance){TileType[TileNumber].SubStageEntrance = !TileType[TileNumber].SubStageEntrance;}
  if(TE.MarkDropStone){TileType[TileNumber].DropStone = !TileType[TileNumber].DropStone;}
  if(TE.MarkWarpStone){TileType[TileNumber].WarpStone = !TileType[TileNumber].WarpStone;}
  MouseOverTileNumber = TileNumber;
}

// ##############################################
// ##############################################
// ##############################################

void Tilesheet_Save()
{
  int j, i, k;
  for(j=0;j<TS.Height;j++)
  {
    for(i=0;i<TS.Width;i++)
    {
      k = i + (j * TS.Width);
      TS.Solid[k] = TileType[k].Solid; // COPY INFOS INTO TS
      TS.Exit[k] = TileType[k].Exit; // COPY INFOS INTO TS
      TS.Lethal[k] = TileType[k].Lethal; // COPY INFOS INTO TS
      TS.Fire[k] = TileType[k].Fire; // COPY INFOS INTO TS
      TS.Coin[k] = TileType[k].Coin; // COPY INFOS INTO TS
      TS.CoinBlock[k] = TileType[k].CoinBlock; // COPY INFOS INTO TS
      TS.Breakable[k] = TileType[k].Breakable; // COPY INFOS INTO TS
      TS.PowerUpBlock[k] = TileType[k].PowerUpBlock; // COPY INFOS INTO TS
      TS.CoinBlockHelmet[k] = TileType[k].CoinBlockHelmet; // COPY INFOS INTO TS
      TS.ColourChanging[k] = TileType[k].ColourChanging; // COPY INFOS INTO TS
      TS.SubStageEntrance[k] = TileType[k].SubStageEntrance; // COPY INFOS INTO TS
      TS.DropStone[k] = TileType[k].DropStone; // COPY INFOS INTO TS
      TS.WarpStone[k] = TileType[k].WarpStone; // COPY INFOS INTO TS
    }
  }

  FILE *Spritesheet_File;
  Spritesheet_File = fopen ("base/Tilesheetinfo.tsi", "wb");

  if (Spritesheet_File != NULL)
  {
    fwrite (&TS, sizeof (TS), 1, Spritesheet_File);    // write data
    fclose (Spritesheet_File);    // close file again
  }
}

// ##############################################
// ##############################################
// ##############################################

void TileSheet_Load()
{
  int x;
  FILE *Spritesheet_File;
  Spritesheet_File = fopen ("base/Tilesheetinfo.tsi", "rb");

  if (Spritesheet_File != NULL)
  {
    fread (&TS, sizeof (TS), 1, Spritesheet_File);
    for(x=0; x<NUMBER_OF_TILES; x++)
    {
      TileType[x].Solid = TS.Solid[x];
      TileType[x].Exit = TS.Exit[x];
      TileType[x].Lethal = TS.Lethal[x];
      TileType[x].Fire = TS.Fire[x];
      TileType[x].Coin = TS.Coin[x];
      TileType[x].CoinBlock = TS.CoinBlock[x];
      TileType[x].Breakable = TS.Breakable[x];
      TileType[x].PowerUpBlock = TS.PowerUpBlock[x];
      TileType[x].CoinBlockHelmet = TS.CoinBlockHelmet[x];
      TileType[x].ColourChanging = TS.ColourChanging[x];
      TileType[x].SubStageEntrance = TS.SubStageEntrance[x];
      TileType[x].DropStone = TS.DropStone[x];
      TileType[x].WarpStone = TS.WarpStone[x];
    }
    fclose (Spritesheet_File);
   }

  // FOR SOME REASON THIS INFO IS LOST WHEN LOADING SPRITESHEET_FILE
/*
  TS.Width = TILESHEET_WIDTH_TILES;
  TS.Height = TILESHEET_HEIGHT_TILES;
  TS.Width_Pixels = TS.Width * TS.Tile_Width;
  TS.Height_Pixels = TS.Height * TS.Tile_Height;
*/
  // FOR SOME REASON THIS INFO IS LOST WHEN LOADING SPRITESHEET_FILE
}

// ##############################################
// ##############################################
// ##############################################
