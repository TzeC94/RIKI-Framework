#include "AnimationManager.h"


AnimationManager::AnimationManager(void)
{
	count = currentSheet = 0.0f;

	currentRow = 1;
}

AnimationManager::~AnimationManager(void)
{
}

void AnimationManager::InitNewAnimationSheet(D3DXVECTOR2 rectSize, D3DXVECTOR2 sheetSize, float secondsToNextAnimation, int noOfRow){

	AnimationData AD;
	AD.rectSize = rectSize;
	AD.sheetSize = sheetSize;
	AD.secondsToNextAnimation = secondsToNextAnimation;

	AD.totalRow = noOfRow;

	AD.rect.left = 0;
	AD.rect.top = 0;
	AD.rect.right = (long)rectSize.x;
	AD.rect.bottom = (long)rectSize.y;


	animationData.push_back(AD);

}

RECT AnimationManager::GetRect()
{

	return animationData[currentSheet].rect;

}

void AnimationManager::AnimationUpdate(){

	if(count >= animationData[currentSheet].secondsToNextAnimation){

		//Loop Process
		if(animationData[currentSheet].rect.right >= (long)animationData[currentSheet].sheetSize.x){
			
			if(currentRow < animationData[currentSheet].totalRow){

				currentRow++;

				animationData[currentSheet].rect.top += (long)animationData[currentSheet].rectSize.y;
				animationData[currentSheet].rect.bottom += (long)animationData[currentSheet].rectSize.y;

			}else{
			
				currentRow = 0;

				animationData[currentSheet].rect.top = (long)0.0f;
				animationData[currentSheet].rect.bottom = (long)animationData[currentSheet].rectSize.y;

			}

			animationData[currentSheet].rect.left = (long)0.0f;
			animationData[currentSheet].rect.right = (long)animationData[currentSheet].rectSize.x;

		}else{
		
			animationData[currentSheet].rect.left += (long)animationData[currentSheet].rectSize.x;
			animationData[currentSheet].rect.right += (long)animationData[currentSheet].rectSize.x;

		}

		count = 0.0f;
		
	}

	count += Time::instance()->deltaTime();

}

void AnimationManager::SetCurrentSheet(int sheetNo){

	ResetRect();

	currentSheet = sheetNo;

}

void AnimationManager::ResetRect()
{
	
	int loopCount = animationData.size();

	for(int i = 0; i < loopCount; i++){
	
		animationData[i].rect.left = animationData[i].rect.top = (long)0.0f;
		animationData[i].rect.right = (long)this->animationData[i].rectSize.x;
		animationData[i].rect.bottom = (long)this->animationData[i].rectSize.y;

	}

	count = 0.0f;

}