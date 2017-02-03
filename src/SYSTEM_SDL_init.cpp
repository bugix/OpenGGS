#include "globals.h"

int CurrentScreenMode;
SDL_Window* gWindow = NULL;     //The window we'll be rendering to
SDL_Renderer* gRenderer = NULL; //The window renderer
SDL_Joystick* GameController = NULL;

// ##############################################
// ##############################################
// ##############################################

void init()
{
  CurrentScreenMode=0;

  //Initialize SDL
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
  {
    printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
  }
  else
  {
    //Enable VSync
    //if( !SDL_SetHint( SDL_HINT_RENDER_VSYNC, "1" ) ){printf( "Warning: VSync not enabled!\n" );}
    //Set texture filtering to linear
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ){printf( "Warning: Linear texture filtering not enabled!\n" );}

    //IMPORTANT
    //Start program in windowed mode! If renderers are created after program is in fullscreen mode
    //there are a lot of weird problems.
    //IMPORTANT

    //Create window
//    gWindow = SDL_CreateWindow( "GameBase (SDL 2.0)", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREENWIDTH, SCREENHEIGHT, SDL_WINDOW_SHOWN); //|SDL_WINDOW_FULLSCREEN
    //gWindow = SDL_CreateWindow( "OpenGGS 2.0 (aka OpenGGS Maker)", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GV.Screen_Width, GV.Screen_Height, SDL_WINDOW_SHOWN); //|SDL_WINDOW_FULLSCREEN
    gWindow = SDL_CreateWindow( "OpenGGS 2.0 (aka OpenGGS Maker) - BETA 3", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, GV.Screen_Width, GV.Screen_Height, SDL_WINDOW_SHOWN); //|SDL_WINDOW_FULLSCREEN
    if( gWindow == NULL )
    {
      printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
    }
    else
    {
      // Create renderer for window
      // gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
      // gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE );
      // gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
      gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED);
      if( gRenderer == NULL )
      {
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
      }
      else
      {
        //Initialize renderer color
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) )
        {
          printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        }
      }
    }
  }

   SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
   //SDL_RenderSetLogicalSize(gRenderer, GV.Screen_Width, GV.Screen_Height);

  int i;
  SDL_Init( SDL_INIT_GAMECONTROLLER );
  SDL_JoystickEventState(SDL_ENABLE);
  GameController = SDL_JoystickOpen( 0 );

  for( i=0; i < SDL_NumJoysticks(); i++ )
  {
    fprintf(stdout,"Joystick Found! - %i - \n\n", i); //SDL_JoystickName(i)
  }

}

// ##############################################
// ##############################################
// ##############################################

void toggleScreenmode()
{
/*
  // NEEDED FOR CUSTOM FULLSCREEN
  SDL_DisplayMode mode;
  mode.refresh_rate = 0;
  mode.driverdata = 0;
  mode.format = SDL_PIXELFORMAT_ARGB8888;
*/

  CurrentScreenMode=CurrentScreenMode+1;
  if(CurrentScreenMode>1){CurrentScreenMode=0;}
  SDL_ShowCursor(1);
  if(GV.Mode == MODE_GAMELOOP && CurrentScreenMode == 1){SDL_ShowCursor(0);}

  if(CurrentScreenMode==0)  // WINDOWED
  {
    SDL_RenderSetScale(gRenderer, 1, 1);
  }

  // DELETE THIS "IF" TO HAVE NORMAL SCALING
  if(CurrentScreenMode==1)  // FULLSCREEN
  {
/*
    SDL_GetCurrentDisplayMode(0, &mode);
    if(mode.h > 959){SDL_RenderSetScale(gRenderer, 2, 2);}
    SDL_SetWindowDisplayMode(gWindow, &mode);
*/
  }

  SDL_SetWindowFullscreen(gWindow, CurrentScreenMode);
}

// ##############################################
// ##############################################
// ##############################################

void SYSTEM_SetResolution(int Resolution)
{
  // IF FULLSCREEN GOTO WINDOWED MODE
  if(CurrentScreenMode==1){toggleScreenmode();}

  HUD.PlayerX = 16;
  HUD.PlayerY = 0;
  HUD.BonusX = 160;
  HUD.BonusY = 0;
  HUD.LivesX = 288;
  HUD.LivesY = 0;
  HUD.StageX = 416;
  HUD.StageY = 0;
  HUD.TimeX = 544;
  HUD.TimeY = 0;
  HUD.SmallCoinX = 160;
  HUD.SmallCoinY = 16;


  if(Resolution == RESOLUTION_640x480)
  {
    GV.Screen_Width = 640;
    GV.Screen_Height = 480;
    GV.Resolution = RESOLUTION_640x480;
    LOOP_Menu_Define_Positions(4);
  }

  if(Resolution == RESOLUTION_800x600)
  {
    GV.Screen_Width = 800;
    GV.Screen_Height = 600;
    GV.Resolution = RESOLUTION_800x600;
    LOOP_Menu_Define_Positions(5);
    HUD.PlayerX += 80;
    HUD.BonusX += 80;
    HUD.LivesX += 80;
    HUD.StageX += 80;
    HUD.TimeX += 80;
    HUD.SmallCoinX += 80;
  }

  if(Resolution == RESOLUTION_1280x720)
  {
    GV.Screen_Width = 1280;
    GV.Screen_Height = 720;
    GV.Resolution = RESOLUTION_1280x720;
    LOOP_Menu_Define_Positions(5);
    HUD.PlayerX += 320;
    HUD.BonusX += 320;
    HUD.LivesX += 320;
    HUD.StageX += 320;
    HUD.TimeX += 320;
    HUD.SmallCoinX += 320;
  }

  Sprite_SmallCoin[0].PosX = HUD.SmallCoinX;
  Sprite_SmallCoin[0].PosY = HUD.SmallCoinY;

  SDL_SetWindowSize(gWindow,GV.Screen_Width,GV.Screen_Height);
  SDL_SetWindowPosition(gWindow,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED);
  GV.ScreenWidthTiles = (int)(GV.Screen_Width/TS.Tile_Width);
  GV.ScreenHeightTiles = (int)(GV.Screen_Height/TS.Tile_Height);
}

// ##############################################
// ##############################################
// ##############################################

