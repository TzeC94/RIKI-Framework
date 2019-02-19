#pragma once
#include <d3dx9.h>

#include <vector>

#include "Time.h"

using namespace std;

struct AnimationData{

	int totalRow;

	RECT rect;	//Current rect size and position in the sprite sheet

	float secondsToNextAnimation;	//Time Counter purposes

	D3DXVECTOR2 rectSize, sheetSize;	//Size of the sprite sheet

};

class AnimationManager
{
public:
	AnimationManager(void);
	~AnimationManager(void);
	
	void InitNewAnimationSheet(D3DXVECTOR2 rectSize, D3DXVECTOR2 sheetSize, float secondsToNextAnimation, int noOfRow);
	RECT GetRect();
	void AnimationUpdate();

	//Function to set current sheet of animation to play
	void SetCurrentSheet(int sheetNo);

	void ResetRect();

private:

	float count;
	int currentSheet;

	int currentRow;

	vector<AnimationData> animationData;

};