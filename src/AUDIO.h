
#define AUDIO_DISK 0
#define AUDIO_JUMP 1
#define AUDIO_DING 2
#define AUDIO_CRACK 3
#define AUDIO_STOMP 4
#define AUDIO_KILLED 5
#define AUDIO_GOTPOWERUP 6
#define AUDIO_PORTAL 7
#define AUDIO_CLICK 8
#define AUDIO_SHOOT 9

#define MUSIC_MENU 0
#define MUSIC_OUTDOORS 1
#define MUSIC_INDOORS 2
#define MUSIC_HIGHSCORE 3



// ##############################################
// ##############################################
// ##############################################

extern void AUDIO_Define();
extern void AUDIO_Music_Play(int MusicNumber);
extern void AUDIO_Sound_Play(int SoundNumber);
extern void AUDIO_Volume_Change_Music(int VolumePercentage, bool ShowVolumeOverlay);
extern void AUDIO_Volume_Change_Sound(int VolumePercentage, bool ShowVolumeOverlay);

extern int VolumePercentage_Music;
extern int VolumePercentage_Sound;
extern int ShowVolume_Music;
extern int ShowVolume_Sound;

extern Mix_Chunk* WavChunk[20];    //SOUND CHUNKS = WAV-FILES
extern Mix_Music* BGM_Title;
extern Mix_Music* BGM_Outdoors;
extern Mix_Music* BGM_Indoors;
