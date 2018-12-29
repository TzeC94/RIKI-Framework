#include "AnimationManager.h"


AnimationManager::AnimationManager(void)
{
	rectSize.x = 0;
	rectSize.y = 0;
	rect.left = 0;
	rect.top = 0;
	rect.right = 0;
	rect.bottom = 0;
	count = 0;
}

AnimationManager::~AnimationManager(void)
{
}

void AnimationManager::Initialize(D3DXVECTOR2 rectSize, D3DXVECTOR2 sheetSize, float secondsToNextAnimation){

	this->rectSize = rectSize;
	this->sheetSize = sheetSize;
	this->secondsToNextAnimation = secondsToNextAnimation;

	rect.left = 0;
	rect.top = 0;
	rect.right = (long)rectSize.x;
	rect.bottom = (long)rectSize.y;

	count = 0;

}

RECT AnimationManager::GetRect()
{
	return rect;
}

void AnimationManager::AnimationUpdate(){

	if(count >= secondsToNextAnimation){

		//Loop Process
		if(rect.right == (long)sheetSize.x){
			
			rect.left = (long)0.0f;
			rect.right = (long)rectSize.x;

		}else{
		
			rect.left += (long)rectSize.x;
			rect.right += (long)rectSize.x;

		}

		count = 0.0f;
		
	}

	count += Time::instance()->deltaTime();

}

void AnimationManager::ResetRect()
{
	rect.left = 0;
	rect.top = 0;
	rect.right = (long)this->rectSize.x;
	rect.bottom = (long)this->rectSize.y;
	count = 0.0f;
	secondsToNextAnimation = 0.0f;
}