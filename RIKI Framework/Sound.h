#ifndef SOUND_H
#define SOUND_H

#include "FMOD\fmod.hpp"
#include <string>
#include <sstream>

using namespace std;

/*
Standard music class function include
-play
-load
-stop
-repeat
-pause/resume
-next track
-previous track
*/

class Sound
{
protected:
	FMOD::System * fmodSystem;
	FMOD_RESULT result;
	FMOD::Sound * source[6];
	FMOD::Sound * musicSource;
	FMOD::Channel * fmodChannel;

	int numSong;
	char songName[100];

	string combinedName;
	string timeCounting;

	bool isPlaying;
	bool stopStatus;

	unsigned int timePos;
	unsigned int musicLength;
	unsigned int currentTime;

public:
	//Initialize
	Sound();
	~Sound();

	//core feature

	//simple load sound function, only able to load 1 sound
	void loadSound(string musicLocation);
	//play the music it loaded
	void playMusic();
	void stopMusic();
	void fastForward();
	void rewind();
	void pauseAndPlaySong(bool status);

	//repeat the only loaded music
	void repeatMusic();

	//set the music volume, 0.1 - 1 only
	void setVolume(float volume);

	//system checking
	bool fmodResult();
	bool SystemResult();
	
	//get and set
	string getSongName();
	bool getStopStatus();
	//get the music current playing time
	string getMusicPlayingTime();
};

#endif

