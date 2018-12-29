#pragma once
#include <d3dx9.h>

#include "Time.h"

class AnimationManager
{
public:
	AnimationManager(void);
	~AnimationManager(void);
	
	void Initialize(D3DXVECTOR2 rectSize, D3DXVECTOR2 sheetSize, float secondsToNextAnimation);
	RECT GetRect();
	void AnimationUpdate();

	void ResetRect();

private:

	RECT rect;	//Current rect size and position in the sprite sheet

	float count, secondsToNextAnimation;	//Time Counter purposes

	D3DXVECTOR2 rectSize, sheetSize;	//Size of the sprite sheet

};

