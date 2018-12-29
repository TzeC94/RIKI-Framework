#include "Time.h"

Time* Time::s_instance = NULL;

Time::Time(void)
{
	lastTime = (float)timeGetTime();
	timeBeginPeriod(1);
}

void Time::update()
{
	currTime = (float)timeGetTime();
	delta_Time = (currTime - lastTime) * 0.001f;
	lastTime = currTime;
}

float Time::deltaTime()
{
	return delta_Time;
}

Time* Time::instance(){

	if(s_instance == NULL)
		s_instance = new Time;

	return s_instance;

}

Time::~Time(void)
{
}
