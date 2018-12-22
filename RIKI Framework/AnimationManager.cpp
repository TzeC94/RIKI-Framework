#include "AnimationManager.h"


AnimationManager::AnimationManager(void)
{
	rectSize.x = 0;
	rectSize.y = 0;
	actualSize.x = 0;
	actualSize.y = 0;
	frameRate = 0;
	rect.left = 0;
	rect.top = 0;
	rect.right = 0;
	rect.bottom = 0;
	count = 0;
	reverse = false;
}

AnimationManager::AnimationManager(float rectSizeX, float rectSizeY, float actualSizeX, float actualSizeY, float frameRate)
{
	this->rectSize.x = rectSizeX;
	this->rectSize.y = rectSizeY;
	this->actualSize.x = actualSizeX;
	this->actualSize.y = actualSizeY;
	this->frameRate = frameRate;
	rect.left = 0;
	rect.top = 0;
	rect.right = (long)this->rectSize.x;
	rect.bottom = (long)this->rectSize.y;
	count = 0;
	reverse = false;
}

AnimationManager::~AnimationManager(void)
{
}

void AnimationManager::initialize(float rectSizeX, float rectSizeY, float actualSizeX, float actualSizeY, float frameRate)
{
	this->rectSize.x = rectSizeX;
	this->rectSize.y = rectSizeY;
	this->actualSize.x = actualSizeX;
	this->actualSize.y = actualSizeY;
	this->frameRate = frameRate;
	rect.left = 0;
	rect.top = 0;
	rect.right = (long)this->rectSize.x;
	rect.bottom = (long)this->rectSize.y;
	count = 0;
	reverse = false;
}

RECT AnimationManager::getRect()
{
	return rect;
}

void AnimationManager::animationGeneration()
{
	rect.top = 0;
	rect.bottom = (long)rectSize.y;
	if(count >= frameRate)
	{
		if(reverse)
		{
			rect.left -= (long)rectSize.x;
			rect.right -= (long)rectSize.x;
			if(rect.left == 0)
			{
				reverse = false;
			}
		}

		else if(!reverse)
		{
			rect.left += (long)rectSize.x;
			rect.right += (long)rectSize.x;
			if(rect.right == (long)actualSize.x)
			{
				reverse = true;
			}
		}

		count = 0.0f;
	}

	count += 0.1f;
}

void AnimationManager::animationGeneration2()
{
	rect.top = (long)rectSize.y;
	rect.bottom = 2*rect.top;

	if(count >= frameRate * 6 && rect.right != actualSize.x)
	{
		rect.left += (long)rectSize.x;
		rect.right += (long)rectSize.x;

		count = 0.0f;
	}

	count += 0.1f;
}

void AnimationManager::resetRect()
{
	rect.left = 0;
	rect.top = 0;
	rect.right = (long)this->rectSize.x;
	rect.bottom = (long)this->rectSize.y;
	count = 0.0f;
	reverse = false;
}