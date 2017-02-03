#include "globals.h"

// needed because SDL does not create stdout and stderr anymore...
FILE * my_stdout = freopen ("my_stdout.txt", "wb" /*or "wt"*/, stdout);
FILE * my_stderr = freopen ("my_stderr.txt", "wb" /*or "wt"*/, stderr);


bool QuitProgram;
Config_Type Config;

void init();                    //Starts up SDL and creates window
void close();                   //Frees media and shuts down SDL
void iniSetup();

// ##############################################
// ##############################################
// ##############################################

int main( int argc, char* args[] )
{
  GAME_ENVIRONMENT_Define();

  init();               // Start up SDL and create window
  srand (time(NULL));   // initialize random seed
  defineAngles();

  Option_GameType_Load();
  GAMETYPE_Load();


  QuitProgram = false;

  LOOP_Menu();


  close();  //Free resources and close SDL
  return 0;
}

// ##############################################
// ##############################################
// ##############################################

void close()
{

  //Destroy window
  SDL_DestroyRenderer( gRenderer );
  SDL_DestroyWindow( gWindow );
 // SDL_JoystickClose( GameController );
//  GameController = NULL;

  gWindow = NULL;
  gRenderer = NULL;
  //Quit SDL subsystems
  IMG_Quit();
  SDL_Quit();
}

// ##############################################
// ##############################################
// ##############################################
