#pragma once
#include <d3dx9.h>

class AnimationManager
{
public:
	AnimationManager(void);
	AnimationManager(float rectSizeX, float rectSizeY, float actualSizeX, float actualSizeY, float frameRate);
	~AnimationManager(void);
	
	void initialize(float rectSizeX, float rectSizeY, float actualSizeX, float actualSizeY, float frameRate);
	RECT getRect();
	void animationGeneration();
	void animationGeneration2();

	void resetRect();

private:
	RECT rect;
	float frameRate, count;
	D3DXVECTOR2 rectSize, actualSize;
	bool reverse;
};

