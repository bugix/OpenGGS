#include "globals.h"

Mix_Chunk* AUDIO_CHUNK_Disk;
Mix_Chunk* AUDIO_CHUNK_Jump;
Mix_Chunk* AUDIO_CHUNK_Stomp;
Mix_Chunk* AUDIO_CHUNK_Killed;
Mix_Chunk* AUDIO_CHUNK_Ding;
Mix_Chunk* AUDIO_CHUNK_Click;
Mix_Chunk* AUDIO_CHUNK_GotPowerUp;
Mix_Chunk* AUDIO_CHUNK_Shoot;
Mix_Chunk* AUDIO_CHUNK_Crack;

Mix_Music* BGM_Title;
Mix_Music* BGM_Outdoors;
Mix_Music* BGM_Indoors;

int VolumePercentage_Music;
int VolumePercentage_Sound;
int ShowVolume_Music;
int ShowVolume_Sound;

// ##############################################
// ##############################################
// ##############################################

void AUDIO_Define()
{
  //*********************************
  // initialize sound
  //Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,1,512);
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
  AUDIO_Volume_Change_Music(25, false);  // SET VOLUME TO 25%
  AUDIO_Volume_Change_Sound(25, false);  // SET VOLUME TO 25%
  Mix_AllocateChannels(8);  // ALLOCATE MIXING CHANNELS

  //*********************************

  Mix_FreeChunk(AUDIO_CHUNK_Disk); AUDIO_CHUNK_Disk = NULL;
  AUDIO_CHUNK_Disk  = Mix_LoadWAV(FileName.WavChunk[AUDIO_DISK]);      //load the chunks

  Mix_FreeChunk(AUDIO_CHUNK_Jump); AUDIO_CHUNK_Jump = NULL;
  AUDIO_CHUNK_Jump  = Mix_LoadWAV(FileName.WavChunk[AUDIO_JUMP]);      //load the chunks

  Mix_FreeChunk(AUDIO_CHUNK_Stomp); AUDIO_CHUNK_Stomp = NULL;
  AUDIO_CHUNK_Stomp = Mix_LoadWAV(FileName.WavChunk[AUDIO_STOMP]);     //load the chunks

  Mix_FreeChunk(AUDIO_CHUNK_Killed); AUDIO_CHUNK_Killed = NULL;
  AUDIO_CHUNK_Killed  = Mix_LoadWAV(FileName.WavChunk[AUDIO_KILLED]);      //load the chunks

  Mix_FreeChunk(AUDIO_CHUNK_Ding); AUDIO_CHUNK_Ding = NULL;
  AUDIO_CHUNK_Ding  = Mix_LoadWAV(FileName.WavChunk[AUDIO_DING]);      //load the chunks

  Mix_FreeChunk(AUDIO_CHUNK_Click); AUDIO_CHUNK_Click = NULL;
  AUDIO_CHUNK_Click  = Mix_LoadWAV(FileName.WavChunk[AUDIO_CLICK]);      //load the chunks

  Mix_FreeChunk(AUDIO_CHUNK_GotPowerUp); AUDIO_CHUNK_GotPowerUp = NULL;
  AUDIO_CHUNK_GotPowerUp = Mix_LoadWAV(FileName.WavChunk[AUDIO_GOTPOWERUP]);      //load the chunks

  Mix_FreeChunk(AUDIO_CHUNK_Shoot); AUDIO_CHUNK_Shoot = NULL;
  AUDIO_CHUNK_Shoot = Mix_LoadWAV(FileName.WavChunk[AUDIO_SHOOT]);      //load the chunks

  Mix_FreeChunk(AUDIO_CHUNK_Crack); AUDIO_CHUNK_Crack = NULL;
  AUDIO_CHUNK_Crack = Mix_LoadWAV(FileName.WavChunk[AUDIO_CRACK]);      //load the chunks

  Mix_FreeMusic(BGM_Title); BGM_Title = NULL;
  BGM_Title=Mix_LoadMUS(FileName.BGM_Title);

  Mix_FreeMusic(BGM_Outdoors); BGM_Outdoors = NULL;
  BGM_Outdoors=Mix_LoadMUS(FileName.BGM_Outdoors);

  Mix_FreeMusic(BGM_Indoors); BGM_Indoors = NULL;
  BGM_Indoors=Mix_LoadMUS(FileName.BGM_Indoors);

}

// ##############################################
// ##############################################
// ##############################################

void AUDIO_Volume_Change_Music(int Percentage, bool ShowVolumeOverlay)
{
  int Value128 = 0;
  // VOLUME OF SAMPLES
  if(Percentage < 1){Value128 = 0; Percentage = 0;}

  if(Percentage > 99){Value128 = 128; Percentage = 100;}

  if(Percentage > 0 && Percentage < 100)
  {
    Value128 = (int)(128*Percentage/100);
  }

  VolumePercentage_Music = Percentage;
  GV.VolumeMusic = Value128/4;
  Mix_VolumeMusic(GV.VolumeMusic);

  if(ShowVolumeOverlay){ShowVolume_Music = 3;}
}

// ##############################################
// ##############################################
// ##############################################

void AUDIO_Volume_Change_Sound(int Percentage, bool ShowVolumeOverlay)
{
  int Value128 = 0;
  // VOLUME OF SAMPLES
  if(Percentage < 1){Value128 = 0; Percentage = 0;}

  if(Percentage > 99){Value128 = 128; Percentage = 100;}

  if(Percentage > 0 && Percentage < 100)
  {
    Value128 = (int)(128*Percentage/100);
  }

  VolumePercentage_Sound = Percentage;
  GV.VolumeSounds = Value128;
  Mix_Volume(-1, GV.VolumeSounds);

  if(ShowVolumeOverlay){ShowVolume_Sound = 3;}
}

// ##############################################
// ##############################################
// ##############################################

void AUDIO_Sound_Play(int SoundNumber)
{
  //Mix_PlayChannel(-1,WavChunk[soundNumber],0);
  if(GV.VolumeSounds > 0)
  {
    if(SoundNumber == AUDIO_DISK)       {Mix_PlayChannel(-1,AUDIO_CHUNK_Disk,0);}
    if(SoundNumber == AUDIO_JUMP)       {Mix_PlayChannel(-1,AUDIO_CHUNK_Jump,0);}
    if(SoundNumber == AUDIO_STOMP)      {Mix_PlayChannel(-1,AUDIO_CHUNK_Stomp,0);}
    if(SoundNumber == AUDIO_KILLED)     {Mix_PlayChannel(-1,AUDIO_CHUNK_Killed,0);}
    if(SoundNumber == AUDIO_DING)       {Mix_PlayChannel(-1,AUDIO_CHUNK_Ding,0);}
    if(SoundNumber == AUDIO_CLICK)      {Mix_PlayChannel(-1,AUDIO_CHUNK_Click,0);}
    if(SoundNumber == AUDIO_GOTPOWERUP) {Mix_PlayChannel(-1,AUDIO_CHUNK_GotPowerUp,0);}
    if(SoundNumber == AUDIO_SHOOT)      {Mix_PlayChannel(-1,AUDIO_CHUNK_Shoot,0);}
    if(SoundNumber == AUDIO_CRACK)      {Mix_PlayChannel(-1,AUDIO_CHUNK_Crack,0);}
  }

  if(SoundNumber == AUDIO_GOTPOWERUP)
  {
    GV.TempMusicVolume = GV.VolumeMusic;
    GV.VolumeMusic = 0;
    GV.TempMusicOffCounter = 1000;
    Mix_VolumeMusic(GV.VolumeMusic);
  }
}

// ##############################################
// ##############################################
// ##############################################

void AUDIO_Music_Play(int MusicNumber)
{
  if(GV.VolumeMusic > 0 && GV.MusicEnabled)
  {
    // PLAY MUSIC

    if(MusicNumber == MUSIC_MENU)      {Mix_PlayMusic(BGM_Title,-1);}
    if(MusicNumber == MUSIC_OUTDOORS)  {Mix_PlayMusic(BGM_Outdoors,-1);}
    if(MusicNumber == MUSIC_INDOORS)   {Mix_PlayMusic(BGM_Indoors,-1);}
   // if(MusicNumber == MUSIC_HIGHSCORE) {Mix_PlayMusic(BackgroundMusic[MUSIC_HIGHSCORE],-1);}

  }
}
