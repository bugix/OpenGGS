#include "globals.h"

Stage_Random_Module_Def Stage_Random_Module_Outdoors[128];
Stage_Random_Module_Def Stage_Random_Module_Outdoors_Exit[8];
Stage_Random_Module_Def Stage_Random_Module_Indoors[128];
Stage_Random_Module_Def Stage_Random_Module_Indoors_Exit[8];


// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_Create(int BackgroundColour, bool RandomObjects, bool RandomPlants, bool RandomCoins)
{
  int x, y;
  int RandomPlantNumber;
  int RandomPlant;
  int RandomPosition;

  ME.BackgroundColour = BackgroundColour;
  if(BackgroundColour == 0){ME.TileType = 0;} // STANDARD OUTDOOR TILES
  if(BackgroundColour == 1){ME.TileType = 1 + rand() % 3;} // ONE OF THE INDOOR COLOURS

  // DELETE ALL TILES
  CREATOR_Stages_Clear();

  //DELETE ALL ENEMIES
  CREATOR_Stages_Clear_Enemies();

  // CREATE GROUND
  //CREATOR_Stages_Create_Ground_With_Holes(BackgroundColour, true);

  //ADD SOME MODULES && EXITS
  LOOP_Editor_Stages_Create_Distribute_Modules(BackgroundColour);

/*
  // SET SOME OBJECTS
  if(RandomObjects){LOOP_Editor_Stages_Create_Distribute_Objects(BackgroundColour);}


    if(RandomCoins)
    {
    for(x = 0; x < 8; x++) // ADD SOME COIN BLOCKS
    {
      RandomPosition = rand() % 225;
      RandomPosition += 10;
      int RandomPositionY = rand() % 8;
      // DONT BUILD TOO CLOSE TO ONANOTHER
      if(ME.TileNumber[RandomPosition+0][RandomPositionY+1] == 0 &&
         ME.TileNumber[RandomPosition+0][RandomPositionY+2] == 0 &&
         ME.TileNumber[RandomPosition+1][RandomPositionY+1] == 0 &&
         ME.TileNumber[RandomPosition+1][RandomPositionY+2] == 0 &&
         ME.TileNumber[RandomPosition+2][RandomPositionY+1] == 0 &&
         ME.TileNumber[RandomPosition+2][RandomPositionY+2] == 0 &&
         ME.TileNumber[RandomPosition+0][RandomPositionY-1] == 0 &&
         ME.TileNumber[RandomPosition+0][RandomPositionY-2] == 0 &&
         ME.TileNumber[RandomPosition+1][RandomPositionY-1] == 0 &&
         ME.TileNumber[RandomPosition+1][RandomPositionY-2] == 0 &&
         ME.TileNumber[RandomPosition+2][RandomPositionY-1] == 0 &&
         ME.TileNumber[RandomPosition+2][RandomPositionY-2] == 0)
      {LOOP_Editor_Stages_Set_Tile(560, RandomPosition, 18-RandomPositionY);}
    }

    for(x = 0; x < 25; x++) // ADD SOME COINS
    {
      RandomPosition = rand() % 225;
      RandomPosition += 10;
      int RandompositionY = rand() % 8;
      LOOP_Editor_Stages_Set_Tile(3, RandomPosition, 18-RandompositionY);
    }
    }
*/


  // SET SOME PLANTS
  if(RandomPlants && BackgroundColour == 0)
  {
    for(x = 0; x < 20; x++)
    {
      RandomPlantNumber = rand() % 6;
      RandomPosition = rand() % 245;
      if(RandomPlantNumber == 0){RandomPlant = 160;}
      if(RandomPlantNumber == 1){RandomPlant = 170;}
      if(RandomPlantNumber == 2){RandomPlant = 177;}
      if(RandomPlantNumber == 3){RandomPlant = 181;}
      if(RandomPlantNumber == 4){RandomPlant = 186;}
      if(RandomPlantNumber == 5){RandomPlant = 60;}

      if(TileType[ME.TileNumber[RandomPosition][27]].Solid &&
         TileType[ME.TileNumber[RandomPosition+1][27]].Solid &&
         TileType[ME.TileNumber[RandomPosition+ElementWidth(RandomPlant)][27]].Solid &&
         TileType[ME.TileNumber[RandomPosition+ElementWidth(RandomPlant)-1][27]].Solid) // DON'T BUILD OVER HOLES
      {
        LOOP_Editor_Stages_Set_Tile(RandomPlant, RandomPosition, 27-ElementHeight(RandomPlant));
      }
    }
  }

  // SET STARTPOSITIONS
  ME.StartPositionX_Tile[0] = 5;
  ME.StartPositionX_Tile[1] = 100;
  ME.StartPositionX_Tile[2] = 200;
  ME.StartPositionX_Tile[3] = 4;

  for(x=0; x<4; x++)
  {
    y = 29;
    while(TileType[ME.TileNumber[ME.StartPositionX_Tile[x]][y]].Solid ||
          TileType[ME.TileNumber[ME.StartPositionX_Tile[x+1]][y]].Solid ||
          TileType[ME.TileNumber[ME.StartPositionX_Tile[x]][y-1]].Solid ||
          TileType[ME.TileNumber[ME.StartPositionX_Tile[x+1]][y-1]].Solid)
   {y--;} // MAKE SURE PLAYER IS NOT INSIDE AN OBJECT
    ME.StartPositionY_Tile[x] = y;
    if(ME.StartPositionY_Tile[x] > 27 ||
       TileType[ME.TileNumber[ME.StartPositionX_Tile[x]][y]].Lethal ||
       TileType[ME.TileNumber[ME.StartPositionX_Tile[x-1]][y]].Lethal ||
       TileType[ME.TileNumber[ME.StartPositionX_Tile[x+1]][y]].Lethal)
    {
      ME.StartPositionY_Tile[x] = 20;
      LOOP_Editor_Stages_Set_Tile(566, ME.StartPositionX_Tile[x]-2, ME.StartPositionY_Tile[x]+1);
      LOOP_Editor_Stages_Set_Tile(566, ME.StartPositionX_Tile[x], ME.StartPositionY_Tile[x]+1);
      LOOP_Editor_Stages_Set_Tile(566, ME.StartPositionX_Tile[x]+2, ME.StartPositionY_Tile[x]+1);
    }
  }
}

// ##############################################
// ##############################################
// ##############################################



void LOOP_Editor_Stages_Create_Distribute_Modules(int BackgroundColour)
{
  int x, y, z, a;
  int ModulePosX[8];
  int NumOutdoorModules = 32;
  int NumOutdoorExitModules = 8;
  int NumIndoorModules = 24;
  int NumIndoorExitModules = 8;

  ModulePosX[0] = 0;
  ModulePosX[1] = 32;
  ModulePosX[2] = 64;
  ModulePosX[3] = 96;
  ModulePosX[4] = 128;
  ModulePosX[5] = 160;
  ModulePosX[6] = 192;
  ModulePosX[7] = 224;

  int RandomOutdoors[7];
  int RandomOutdoors_Exit = rand() % NumOutdoorExitModules;
  RandomOutdoors[0] = rand() % NumOutdoorModules;
  RandomOutdoors[1] = rand() % NumOutdoorModules;
  RandomOutdoors[2] = rand() % NumOutdoorModules;
  RandomOutdoors[3] = rand() % NumOutdoorModules;
  RandomOutdoors[4] = rand() % NumOutdoorModules;
  RandomOutdoors[5] = rand() % NumOutdoorModules;
  RandomOutdoors[6] = rand() % NumOutdoorModules;

  int RandomIndoors[7];
  int RandomIndoors_Exit = rand() % NumIndoorExitModules;
  RandomIndoors[0] = rand() % NumIndoorModules;
  RandomIndoors[1] = rand() % NumIndoorModules;
  RandomIndoors[2] = rand() % NumIndoorModules;
  RandomIndoors[3] = rand() % NumIndoorModules;
  RandomIndoors[4] = rand() % NumIndoorModules;
  RandomIndoors[5] = rand() % NumIndoorModules;
  RandomIndoors[6] = rand() % NumIndoorModules;

  for(y = 0; y < 30; y++)  // 30 TILES HIGH
  {
    for (x = 0; x < 32; x++)  // 32 TILES WIDE
    {
      if(BackgroundColour==0 && Stage_Random_Module_Outdoors_Exit[RandomOutdoors_Exit].TileNumber[x][y] != 0)
      {
        ME.TileNumber[ModulePosX[7]+x][y] = Stage_Random_Module_Outdoors_Exit[RandomOutdoors_Exit].TileNumber[x][y];
        // SETTING THE ENEMIES
        for(a = 0; a < MAX_NUM_ENEMIES_MODULE; a++)
        {
          if(Stage_Random_Module_Outdoors_Exit[RandomOutdoors_Exit].Enemy_InUse[a] == 1)
          {
            LOOP_Editor_Stages_Set_New_Enemy(Stage_Random_Module_Outdoors_Exit[RandomOutdoors_Exit].Enemy_Type[a],
                                             Stage_Random_Module_Outdoors_Exit[RandomOutdoors_Exit].Enemy_PosX[a]+(7*32),
                                             Stage_Random_Module_Outdoors_Exit[RandomOutdoors_Exit].Enemy_PosY[a]);
          }
        }
      }
      if(BackgroundColour==1 && Stage_Random_Module_Indoors_Exit[RandomIndoors_Exit].TileNumber[x][y] != 0)
      {
        ME.TileNumber[ModulePosX[7]+x][y] = Stage_Random_Module_Indoors_Exit[RandomIndoors_Exit].TileNumber[x][y];
        // SETTING THE ENEMIES
        for(a = 0; a < MAX_NUM_ENEMIES_MODULE; a++)
        {
          if(Stage_Random_Module_Indoors_Exit[RandomIndoors_Exit].Enemy_InUse[a] == 1)
          {
            LOOP_Editor_Stages_Set_New_Enemy(Stage_Random_Module_Indoors_Exit[RandomIndoors_Exit].Enemy_Type[a],
                                             Stage_Random_Module_Indoors_Exit[RandomIndoors_Exit].Enemy_PosX[a]+(7*32),
                                             Stage_Random_Module_Indoors_Exit[RandomIndoors_Exit].Enemy_PosY[a]);
          }
        }
      }
    }
  }

  for(z = 0; z < 7; z++)  // 7 POSSIBLE POSITIONS
  {
    for(y = 0; y < 30; y++)  // 30 TILES HIGH
    {
      for (x = 0; x < 32; x++)  // 32 TILES WIDE
      {
        if(BackgroundColour==0 && Stage_Random_Module_Outdoors[RandomOutdoors[z]].TileNumber[x][y] != 0)
        {
          ME.TileNumber[ModulePosX[z]+x][y] = Stage_Random_Module_Outdoors[RandomOutdoors[z]].TileNumber[x][y];
          // SETTING THE ENEMIES
          for(a = 0; a < MAX_NUM_ENEMIES_MODULE; a++)
          {
            if(Stage_Random_Module_Outdoors[RandomOutdoors[z]].Enemy_InUse[a] == 1)
            {
              LOOP_Editor_Stages_Set_New_Enemy(Stage_Random_Module_Outdoors[RandomOutdoors[z]].Enemy_Type[a],
                                               Stage_Random_Module_Outdoors[RandomOutdoors[z]].Enemy_PosX[a]+(z*32),
                                               Stage_Random_Module_Outdoors[RandomOutdoors[z]].Enemy_PosY[a]);
            }
          }

        }
        if(BackgroundColour==1 && Stage_Random_Module_Indoors[RandomIndoors[z]].TileNumber[x][y] != 0)
        {
          ME.TileNumber[ModulePosX[z]+x][y] = Stage_Random_Module_Indoors[RandomIndoors[z]].TileNumber[x][y];
          // SETTING THE ENEMIES
          for(a = 0; a < MAX_NUM_ENEMIES_MODULE; a++)
          {
            if(Stage_Random_Module_Indoors[RandomIndoors[z]].Enemy_InUse[a] == 1)
            {
              LOOP_Editor_Stages_Set_New_Enemy(Stage_Random_Module_Indoors[RandomIndoors[z]].Enemy_Type[a],
                                               Stage_Random_Module_Indoors[RandomIndoors[z]].Enemy_PosX[a]+(z*32),
                                               Stage_Random_Module_Indoors[RandomIndoors[z]].Enemy_PosY[a]);
            }
          }
        }
      }
    }
  }

}

// ##############################################
// ##############################################
// ##############################################

void LOOP_Editor_Stages_Create_Distribute_Objects(int BackgroundColour)
{
  int x;
  int RandomPosition;
  int RandomObjectNumber;
  int RandomObject;
  int HaveThisFeature = rand() % 3;
  int GroundHeight;
  if(BackgroundColour == 0){GroundHeight = 3;}
  if(BackgroundColour == 1){GroundHeight = 4;}

  if(HaveThisFeature == 1)  // HAVE FIRE TOWERS
  {
    for(x = 0; x < 5; x++)  // ADD SOME FIRE TOWERS
    {
      RandomPosition = rand() % 225;
      RandomPosition += 10;
      if(TileType[ME.TileNumber[RandomPosition][27]].Solid && TileType[ME.TileNumber[RandomPosition+ElementWidth(514)][27]].Solid) // DON'T BUILD OVER HOLES
      {
        bool CanBeBuilt = true;
        if(!LOOP_Editor_Stages_Room_For_Object(514, RandomPosition, 27-GroundHeight)){CanBeBuilt = false;}
        if(!LOOP_Editor_Stages_Room_For_Object(514, RandomPosition, 27-GroundHeight-3)){CanBeBuilt = false;}
        if(!LOOP_Editor_Stages_Room_For_Object(6, RandomPosition+1, 27-GroundHeight-5)){CanBeBuilt = false;}
        if(CanBeBuilt)
        {
          LOOP_Editor_Stages_Set_Tile(514, RandomPosition, 27-GroundHeight);
          LOOP_Editor_Stages_Set_Tile(514, RandomPosition, 27-GroundHeight-3);
          LOOP_Editor_Stages_Set_Tile(6, RandomPosition+1, 27-GroundHeight-5);
        }
      }
    }
  }

  for(x = 0; x < 5; x++) // ADD SOME TOWERS
  {
    RandomPosition = rand() % 225;
    RandomPosition += 10;
    if(TileType[ME.TileNumber[RandomPosition][27]].Solid && TileType[ME.TileNumber[RandomPosition+ElementWidth(514)][27]].Solid) // DON'T BUILD OVER HOLES
    {
      bool CanBeBuilt = true;
      if(!LOOP_Editor_Stages_Room_For_Object(514, RandomPosition, 27-GroundHeight)){CanBeBuilt = false;}
      if(!LOOP_Editor_Stages_Room_For_Object(514, RandomPosition, 27-GroundHeight-3)){CanBeBuilt = false;}
      if(CanBeBuilt)
      {
        LOOP_Editor_Stages_Set_Tile(514, RandomPosition, 27-GroundHeight);
        LOOP_Editor_Stages_Set_Tile(514, RandomPosition, 27-GroundHeight-3);
      }
    }
  }

  for(x = 0; x < 20; x++) // ADD SOME RANDOM OBJECTS
  {
    RandomObjectNumber = rand() % 6;
    RandomPosition = rand() % 225;
    RandomPosition += 10;
    if(RandomObjectNumber == 0){RandomObject = 16;}
    if(RandomObjectNumber == 1){RandomObject = 511;}
    if(RandomObjectNumber == 2){RandomObject = 50;}
    if(RandomObjectNumber == 3){RandomObject = 32;}
    if(RandomObjectNumber == 4){RandomObject = 587;}
    if(RandomObjectNumber == 5){RandomObject = 678;}

    if(TileType[ME.TileNumber[RandomPosition][27]].Solid &&
       TileType[ME.TileNumber[RandomPosition+1][27]].Solid &&
       TileType[ME.TileNumber[RandomPosition+ElementWidth(RandomObject)][27]].Solid) // DON'T BUILD OVER HOLES
    {
      LOOP_Editor_Stages_Set_Tile(RandomObject, RandomPosition, 27-ElementHeight(RandomObject)-GroundHeight+3);
    }
  }
}

// ##############################################
// ##############################################
// ##############################################

