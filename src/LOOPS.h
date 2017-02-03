
#define MODE_MENU 0
#define MODE_GAMELOOP 10
#define MODE_EDITOR_STAGES 20
#define MODE_EDITOR_TILES 30
#define MODE_CREDITS 40
#define MODE_OPTIONS 50
#define MODE_STORY 60
#define MODE_SPLASHSCREEN 70
#define MODE_WARPSCREEN 80
#define MODE_STAGEFILE_LOAD 90

// ##############################################
// ##############################################
// ##############################################

void LOOP_Credits();
void LOOP_Credits_Draw();
void LOOP_Gameloop_Standard();
void LOOP_Gameloop_Splashscreen();
void LOOP_Gameloop_Splashscreen_Draw();
void LOOP_Gameloop_Warpscreen();
void LOOP_Gameloop_Warpscreen_Draw();
void LOOP_Stagefile_Load();
void LOOP_Stagefile_Load_Draw();
void LOOP_Menu();
void LOOP_Menu_Draw();
void LOOP_Menu_Define_Positions(int Cols);
void LOOP_Options();
void LOOP_Options_Draw();
void LOOP_Story();
void LOOP_Story_Draw();

typedef struct {
  int x_off;
  int y_off;
} Text_Offset_Def;
extern Text_Offset_Def Credits;
extern Text_Offset_Def Story;
extern Text_Offset_Def Splashscreen;
extern Text_Offset_Def WarpScreen;
extern Text_Offset_Def StageFile_Load;

typedef struct {
  int x_off;
  int y_off;
  int MenuPosition;
} Options_Def;
extern Options_Def Options;

// ##############################################
// ##############################################
// ##############################################

extern bool QuitToMenu;
extern int MenuPosition;
extern bool QuitProgram;

// ##############################################
// ##############################################
// ##############################################
