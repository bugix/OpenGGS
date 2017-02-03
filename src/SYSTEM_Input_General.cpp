#include "globals.h"

// ##############################################
// ##############################################
// ##############################################

void INPUT_General()
{
  // CLICK ON "X" CLOSES PROGRAM
  if(e.type == SDL_QUIT){QuitProgram = true;}

  // CHANGE VOLUME OF MUSIC
  if(Key_PAGEUP_pressed)  {AUDIO_Volume_Change_Music(VolumePercentage_Music += 10, true); AUDIO_Sound_Play(AUDIO_CLICK);}
  if(Key_PAGEDOWN_pressed){AUDIO_Volume_Change_Music(VolumePercentage_Music -= 10, true); AUDIO_Sound_Play(AUDIO_CLICK);}

  if(Key_PLUS_pressed) {AUDIO_Volume_Change_Sound(VolumePercentage_Sound += 10, true); AUDIO_Sound_Play(AUDIO_CLICK);}
  if(Key_MINUS_pressed){AUDIO_Volume_Change_Sound(VolumePercentage_Sound -= 10, true); AUDIO_Sound_Play(AUDIO_CLICK);}

  // TOGGLE WINDOWED/FULLSCREEN
  if(Key_LALT && Key_ENTER_pressed) {toggleScreenmode();}
}
