#include "scrollingEngine.h"


scrollingEngine::scrollingEngine(void)
{
	pos.x = pos.y = pos2.x = pos2.y = 0;
	speed = 1.0f;
	deltaTime = 0.0167f;
	iniSpeed = 0.0f;
}


scrollingEngine::~scrollingEngine(void)
{
}

void scrollingEngine::initialize(float posObject1X, float posObject1Y, float posObject2X, float posObject2Y, float iniSpeed)
{
	pos.x = posObject1X;
	pos.y = posObject1Y;

	pos2.x = posObject2X;
	pos2.y = posObject2Y;

	this->iniSpeed = iniSpeed;
}

D3DXVECTOR2 scrollingEngine::getPosition()
{
	return pos;
}

D3DXVECTOR2 scrollingEngine::getPosition2()
{
	return pos2;
}

void scrollingEngine::update()
{
	if(pos.x + 600 <= 0)
		pos.x = 1800;

	if(pos2.x + 600 <= 0)
		pos2.x = 1800;

	pos.x -= iniSpeed * speed * deltaTime;
	pos2.x -= iniSpeed * speed * deltaTime;
}

void scrollingEngine::setSpeed(float speed)
{
	this->speed = speed;
}