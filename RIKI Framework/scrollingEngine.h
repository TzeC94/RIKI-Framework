#pragma once
#include <d3dx9.h>

class scrollingEngine
{
private:
	D3DXVECTOR2 pos, pos2;
	float deltaTime, speed;
	float iniSpeed;

public:
	scrollingEngine(void);
	~scrollingEngine(void);

	void initialize(float posObject1X, float posObject1Y, float posObject2X, float posObject2Y, float iniSpeed);

	void update();

	//set image scrolling speed
	void setSpeed(float speed);

	//get image position
	D3DXVECTOR2 getPosition();
	D3DXVECTOR2 getPosition2();
};

