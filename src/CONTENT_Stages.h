#define MAX_NUM_ENEMIES 50
#define MAX_NUM_ENEMIES_MODULE 5
#define NUM_MODULES_OUTDOORS 24
#define NUM_MODULES_OUTDOORS_EXITS 8
#define NUM_MODULES_INDOORS 16
#define NUM_MODULES_INDOORS_EXITS 8

void STAGE_Load(int StageNumber, int CheckPointNumber, bool ShowSplashScreen, bool ShowResultspage);
void STAGE_Save(int StageNumber);
void STAGE_Copy_To_Cache(int StageNumber);
void STAGE_Copy_To_StageC64();
void STAGES_Files_Names_Load();
void STAGES_Import();

void STAGE_Draw();
void STAGE_Interface_Draw();

void LOOP_Editor_Stages();
void LOOP_Editor_Stages_Change_Stage_Settings();
bool LOOP_Editor_Stages_Room_For_Object(int TileType, int x, int y);
void LOOP_Editor_Stages_Create(int BackgroundColour, bool RandomObjects, bool RandomPlants, bool RandomCoins);
void LOOP_Editor_Stages_Create_Distribute_Modules(int BackgroundColour);
void LOOP_Editor_Stages_Create_Distribute_Objects(int BackgroundColour);
void LOOP_Editor_Stages_Delete_Tile(int x, int y);
void LOOP_Editor_Stages_Draw_Enemies();
void LOOP_Editor_Stages_Draw_Enemy(int EnemyNumber);
void LOOP_Editor_Stages_Draw_Enemy_Selection();
void LOOP_Editor_Stages_Draw_Autocreate_Functions();
void LOOP_Editor_Stages_Draw_Interface();
void LOOP_Editor_Stages_Draw_Stage();
void LOOP_Editor_Stages_Load_Stage(int Stage);
void LOOP_Editor_Stages_Pick_TileType();
void LOOP_Editor_Stages_Set_Enemy(int x, int y);
void LOOP_Editor_Stages_Set_New_Enemy(int EnemyType, int x, int y);
void LOOP_Editor_Stages_Set_StartPosition();
void LOOP_Editor_Stages_Set_Tile(int TileType, int x, int y);
void LOOP_Editor_Stages_Set_Tile_Check(int TileType, int x, int y);
void LOOP_Editor_Stages_SPRITE_Platform_Draw();
void LOOP_Editor_Stages_SPRITE_Platform_Set(int x, int y);

void CREATOR_Stages_Clear();
void CREATOR_Stages_Clear_Enemies();
void CREATOR_Stages_Create_Ground_With_Holes(int BackgroundColour, bool Holes);
void CREATOR_Stages_Ground(int IndooOutdoor);
void CREATOR_Stages_Reset_Start_Positions();

void STAGES_Import_RANDOM_Modules();

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int StagePosX;
  int StagePosY;
  bool MarkSolids;
  bool MarkExits;
  bool MarkLethals;
  bool ShowInterface;
  bool SingleTileMode;
  int CurrentTileType;
  int TileType;        // above ground, underground, different colours...
  int CurrentEnemy;
  int CurrentEnemyType;
  bool DrawGrid;
  bool DontSetATile;
  bool SquareThisBlock;
  int Frame_3;
  int Frame_4;
  int Frame_6;
  int Frame_8;
  int ElementGroup;

  int CurrentStartPosition;
  int StartPositionX_Tile[4];
  int StartPositionY_Tile[4];

  int Stage;

  int TileNumber[256][30];
  int BackgroundColour;
  int Enemy_Type[MAX_NUM_ENEMIES];
  bool Enemy_InUse[MAX_NUM_ENEMIES];
  int Enemy_Direction[MAX_NUM_ENEMIES];
  int Enemy_PosX[MAX_NUM_ENEMIES];
  int Enemy_PosY[MAX_NUM_ENEMIES];
  int Enemy_Alive[MAX_NUM_ENEMIES];

  int Platform_Start_X;
  int Platform_Start_Y;
  int Platform_End_X;
  int Platform_End_Y;
  bool Platform_inUse;
  bool Platform_StartGrabbed;
  bool Platform_EndGrabbed;
} StagesEditor_Type;

extern StagesEditor_Type ME;

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int TileNumber[256][30];
  int StageHeight;
  int StageWidth;
  int StageHeightPixels;
  int StageWidthPixels;
  int CheckPointX[4];
  int CheckPointY[4];
  int BackgroundColour;
  int TileType;            // above ground, underground, different colours...
  int AnimationCounter[256][30];
}StageDef_C64;
extern StageDef_C64 StageC64;

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int CloudPosX[12];
  int CloudPosY[12];
  int BrickPosX[12];
  int BrickPosY[12];
  int TubePosX[4];
  int TubeFire[4];
}BackGroundElements_Def;
extern BackGroundElements_Def BackGroundElements;

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int TileNumber[50][256][30];
  int StartPositionX[50][4];
  int StartPositionY[50][4];
  int BackgroundColour[50];

  char Name[50][100];          // name of the stage (default = "noname")

  int TileType[50];            // above ground, underground, different colours...
  int WarpToStage[50];
  int PlatformInUse[50];
  int PlatformX[50];
  int PlatformY[50];
  int PlatformType[50];
  int PlatformDirection[50];
  int PlatformPathLength[50];
  int PlatformMovePos[50];
  int Enemy_Type[50][MAX_NUM_ENEMIES];
  int Enemy_InUse[50][MAX_NUM_ENEMIES];
  int Enemy_Direction[50][MAX_NUM_ENEMIES];
  int Enemy_PosX[50][MAX_NUM_ENEMIES];
  int Enemy_PosY[50][MAX_NUM_ENEMIES];
  int Substage_Array[50][40][30];
  int Substage_StartPositionX[50];
  int Substage_StartPositionY[50];
  int Substage_PlatformInUse[50];      //Platform.inUse
  int Substage_PlatformX[50];          //Platform.Start_X
  int Substage_PlatformY[50];          // Platform.Start_Y
  int Substage_PlatformType[50];
  int Substage_PlatformDirection[50];
  int Substage_PlatformPathlength[50]; //Platform.End_Y = Platform.Start_Y-Substage_PlatformPathlength
  int Substage_PlatformMovePos[50];
}StageCacheDef_C64;
extern StageCacheDef_C64 StageCache_C64;

// ##############################################
// ##############################################
// ##############################################

extern int StagePosX;
extern int StagePosY;

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  char Name[100];          // name of the stage (default = "noname")
  int Number;              // every stage has a number
  int Array[256][30];      // tile array
  int TileType;            // above ground, underground, different colours...
  int BackgroundColour;    // background colour (blue or black)
  int StartPositionX[4];
  int StartPositionY[4];
  int WarpToStage;
  int PlatformInUse;
  int PlatformX;
  int PlatformY;
  int PlatformType;
  int PlatformDirection;
  int PlatformPathLength;
  int PlatformMovePos;
  int Enemy_Type[MAX_NUM_ENEMIES];
  int Enemy_InUse[MAX_NUM_ENEMIES];
  int Enemy_Direction[MAX_NUM_ENEMIES];
  int Enemy_PosX[MAX_NUM_ENEMIES];
  int Enemy_PosY[MAX_NUM_ENEMIES];
  int Substage_Array[40][30];
  int Substage_StartPositionX;
  int Substage_StartPositionY;
  int Substage_PlatformInUse;
  int Substage_PlatformX;
  int Substage_PlatformY;
  int Substage_PlatformType;
  int Substage_PlatformDirection;
  int Substage_PlatformPathlength;
  int Substage_PlatformMovePos;
} ImportStage_Struct;
extern ImportStage_Struct ImportStage;

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int TileNumber[32][30];
  int Enemy_Type[MAX_NUM_ENEMIES_MODULE];
  int Enemy_InUse[MAX_NUM_ENEMIES_MODULE];
  int Enemy_Direction[MAX_NUM_ENEMIES_MODULE];
  int Enemy_PosX[MAX_NUM_ENEMIES_MODULE];
  int Enemy_PosY[MAX_NUM_ENEMIES_MODULE];
}Stage_Random_Module_Def;
extern Stage_Random_Module_Def Stage_Random_Module_Outdoors[128];
extern Stage_Random_Module_Def Stage_Random_Module_Outdoors_Exit[8];
extern Stage_Random_Module_Def Stage_Random_Module_Indoors[128];
extern Stage_Random_Module_Def Stage_Random_Module_Indoors_Exit[8];
