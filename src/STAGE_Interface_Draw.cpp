#include "globals.h"

// ##############################################
// ##############################################
// ##############################################

void STAGE_Interface_Draw()
{

  Print_Big(HUD.PlayerX,HUD.PlayerY,0,0, "PLAYER");
  if(PC.Points < 10){PrintInt_Big(HUD.PlayerX+80,HUD.PlayerY+16,0,0, PC.Points);}
  if(PC.Points > 9 && PC.Points < 100){PrintInt_Big(HUD.PlayerX+64,HUD.PlayerY+16,0,0, PC.Points);}
  if(PC.Points > 99 && PC.Points < 1000){PrintInt_Big(HUD.PlayerX+48,HUD.PlayerY+16,0,0, PC.Points);}
  if(PC.Points > 999 && PC.Points < 10000){PrintInt_Big(HUD.PlayerX+32,HUD.PlayerY+16,0,0, PC.Points);}
  if(PC.Points > 9999){PrintInt_Big(HUD.PlayerX+16,HUD.PlayerY+16,0,0, PC.Points);}

  Print_Big(HUD.BonusX, HUD.BonusY, 0, 0, "BONUS");
  if(PC.Coins < 10){PrintInt_Big(HUD.BonusX+64, HUD.BonusY+16, 0, 0, PC.Coins);}
  if(PC.Coins > 9 && PC.Coins < 100){PrintInt_Big(HUD.BonusX+48, HUD.BonusY+16, 0, 0, PC.Coins);}
  if(PC.Coins > 99){PrintInt_Big(HUD.BonusX+32, HUD.BonusY+16, 0, 0, PC.Coins);}

  Print_Big(HUD.LivesX, HUD.LivesY, 0, 0, "LIVES");
  if(PC.Lives < 10){PrintInt_Big(HUD.LivesX+64, HUD.LivesY+16, 0, 0, PC.Lives);}
  if(PC.Lives > 9){PrintInt_Big(HUD.LivesX+48, HUD.LivesY+16, 0, 0, PC.Lives);}

  Print_Big(HUD.StageX, 0, 0, 0, "STAGE");
  if(PC.Stage < 10){PrintInt_Big(HUD.StageX+64, HUD.StageY+16, 0, 0, PC.Stage);}
  if(PC.Stage > 9 && PC.Stage < 100) {PrintInt_Big(HUD.StageX+48, HUD.StageY+16, 0, 0, PC.Stage);}
  if(PC.Stage > 99) {PrintInt_Big(HUD.StageX+32, HUD.StageY+16, 0, 0, PC.Stage);}

  Print_Big(HUD.TimeX, HUD.TimeY, 0, 0, "TIME");
  PrintInt_Big(HUD.TimeX+48, HUD.TimeY+16, 0, 0, 0);

/*
  if(PC.Exit_Reached){Print(150, 10, 0, 0, "EXIT REACHED");}
  if(!PC.Exit_Reached){Print(150, 10, 2, 0, "EXIT REACHED");}

  if(PC.OnGround){Print(150, 20, 0, 0, "ON GROUND");}
  if(!PC.OnGround){Print(150, 20, 2, 0, "ON GROUND");}

  if(PC.JumpOnGoing){Print(150, 40, 0, 0, "JUMP ONGOING");}
  if(!PC.JumpOnGoing){Print(150, 40, 2, 0, "JUMP ONGOING");}

  if(PC.Dead){Print(150, 50, 0, 0, "DEAD");}
  if(!PC.Dead){Print(150, 50, 2, 0, "DEAD");}

  if(PC.WallGrinding){Print(150, 60, 0, 0, "WALLGRINDING");}
  if(!PC.WallGrinding){Print(150, 60, 2, 0, "WALLGRINDING");}

  Print(300, 10, 0, 0, "Run Vel:");
  PrintInt(390, 10, 0, 0, PC.RunVelocity);
*/

}


// ##############################################
// ##############################################
// ##############################################
