
#define PC_RIGHT 0
#define PC_LEFT 1
#define PC_MORPH 2

#define PC_STAND 0
#define PC_WALK1 1
#define PC_WALK2 2
#define PC_JUMP 3
#define PC_TURN 4
#define PC_MORPH1 5
#define PC_MORPH2 6

#define PC_MODE1 0 // STARTING STRENGTH
#define PC_MODE2 1 // PUNK
#define PC_MODE3 2 // MORPHING INTO PUNK
#define PC_DEAD 9

#define PC_MORPHING_DURATION 250
#define PC_WARPING_DURATION 1000

void PC_Check_Tilecollision();
void PC_Check_TilecollisionNonSolid();
void PC_Check_Collision_Sprites();
void PC_Collision_Breakable();
void PC_Collision_CoinBlock();
void PC_Collision_CoinBlockHelmet();
void PC_Collision_DropStone();
bool PC_Collision_Exit();
void PC_Collision_PowerUpBlock();
void PC_Collision_WarpStone();
void PC_Death_Routine();
void PC_Define();
void PC_Draw(int x, int y);
void PC_Friction();
void PC_Gravity();
void PC_Jump();
void PC_Killed();
void PC_Run();
void PC_PowerUp_Set(int PowerUpNumber);

// ##############################################
// ##############################################
// ##############################################

typedef struct {
  int PosX;
  int PosY;
  int StagePosX;
  float JumpVelocity;
  int JumpStrength;
  float RunVelocity;
  int RunStrength;
  int FrameX[10][10][10];
  int FrameY[10][10][10];
  int FrameW[10][10][10];
  int FrameH[10][10][10];
  int ColWidth;
  int ColHeight;
  int ColWidthHalf;
  int ColWidthQuart;
  int ColHeightHalf;
  int ColHeightQuart;
  bool OnGround;
  int OnGroundDelay;
  int OnGroundDelayMax; // MILISECONDS PLAYER CAN STILL JUMP AFTER WALKING OFF A CLIFF (USEFULL FOR "STAIRS")
  bool HitWall;
  bool JumpOnGoing;
  int Direction;
  int Animation;
  int Stance;
  int Mode;
  int MorphingCounter;
  bool AccellRight;
  bool AccellLeft;
  bool ShowBorder;
  int Stage;
  int SubStageEntryStage;
  int SubStageNumber;
  bool GotoSubStage;
  bool Exit_Reached;
  int Coins;
  bool Dead;
  bool gotKilled;
  bool WallGrinding;
  bool OnPlatform;
  int PowerUp;
  int x1;
  int x2;
  int x3;
  int y1;
  int y2;
  int y3;
  int x1T;
  int x2T;
  int x3T;
  int y1T;
  int y2T;
  int y3T;
  bool GodMode;
  int TargetEnemy;
  int MovementVertical;
  int MovementHorizontal;
  int WarpCounter;
  int Lives;
  int Points;
} PC_Type;

extern PC_Type PC;

// ##############################################
// ##############################################
// ##############################################
