#include "Sound.h"


Sound::Sound(void)
{
	//initialize other
	numSong = 0;

	stopStatus = false;

	fmodSystem = NULL;

	for(int a =0; a< 5; a++)
		source[a] = NULL;

	fmodChannel = NULL;

    result = FMOD::System_Create(&fmodSystem);

	fmodResult();

	SystemResult();

	result = fmodSystem->init(100, FMOD_INIT_NORMAL, 0);
    
    fmodResult();
}

bool Sound::fmodResult()
{
	if(result != FMOD_OK)
		return false;

	return true;
}

bool Sound::SystemResult()
{
	if(!fmodSystem)
		return false;

	return true;
}

void Sound::loadSound(string address)
{
	result = fmodSystem->createStream(address.c_str(), FMOD_DEFAULT, 0, &musicSource);
	fmodResult();
}

void Sound::playMusic()
{
	fmodSystem->playSound(FMOD_CHANNEL_REUSE, musicSource, false, &fmodChannel);
	musicSource->getName(songName, 100);
	stopStatus = false;
}

void Sound::stopMusic()
{
	fmodChannel->stop();
	stopStatus = true;
}

void Sound::fastForward()
{
	fmodChannel->getPosition(&timePos, FMOD_TIMEUNIT_MS);
	fmodChannel->setPosition(timePos+5000, FMOD_TIMEUNIT_MS);
}

void Sound::rewind()
{
	fmodChannel->getPosition(&timePos, FMOD_TIMEUNIT_MS);
	fmodChannel->setPosition(timePos-5000, FMOD_TIMEUNIT_MS);
}

string Sound::getSongName()
{
	musicSource->getName(songName, 100);
	return combinedName;
}

void Sound::pauseAndPlaySong(bool state)
{
	fmodChannel->isPlaying(&isPlaying);
	if(isPlaying == true)
	{
		if(state == true)
		{
			fmodChannel->setPaused(true);
		}
		else
		{
			fmodChannel->setPaused(false);
		}
	}
}

bool Sound::getStopStatus()
{
	return stopStatus;
}

string Sound::getMusicPlayingTime()
{
	stringstream timeNow, fullTime;
	musicSource->getLength(&musicLength, FMOD_TIMEUNIT_MS);
	fullTime << (musicLength/100) + 1;
	fmodChannel->getPosition(&currentTime, FMOD_TIMEUNIT_MS);
	timeNow << currentTime/100;
	timeCounting = timeNow.str() + "/" + fullTime.str();
	return timeCounting;
}

void Sound::repeatMusic()
{
	musicSource->setMode(FMOD_LOOP_NORMAL);
}

void Sound::setVolume(float volume)
{
	if(volume > 1)
	{
		volume = 1;
		fmodChannel->setVolume(volume);
	}
	else if(volume < 0.1)
	{
		volume = 0.1f;
		fmodChannel->setVolume(volume);
	}
	else
		fmodChannel->setVolume(volume);
}

Sound::~Sound(void)
{
	musicSource->release();
	
	fmodSystem->release();
}
