#pragma once
#include <Windows.h>

class Time
{
private:
	float lastTime, currTime, delta_Time;

	//singleton
	static Time* s_instance;

public:
	Time(void);
	~Time(void);

	void update();

	float deltaTime();

	//singleton function
	static Time* instance();

};

