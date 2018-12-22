#include "Physics.h"


Physics::Physics(void)
{
	readConfig();
}

bool Physics::worldCollision(D3DXVECTOR2 object, float height, float width, bool centreDraw)
{
	if(centreDraw == true)
	{
		if(object.x - width/2 <= 0)
			return true;
		else if(object.x + width/2 >= x )
			return true;
		else if(object.y - height/2 <= 0)
			return true;
		else if(object.y + height/2 >= y)
			return true;
		else
			return false;
	}
	else
	{
		if(object.x - width <= 0)
			return true;
		else if(object.x + width >= x )
			return true;
		else if(object.y - height <= 0)
			return true;
		else if(object.y + height >= y)
			return true;
		else
			return false;
	}
}

bool Physics::worldCollision(D3DXVECTOR2 object, float radius)
{
	if(object.x - radius <= 0)
		return true;
	else if(object.x + radius>= x )
		return true;
	else if(object.y - radius<= 0)
		return true;
	else if(object.y + radius >= y)
		return true;
	else
		return false;
}

bool Physics::circleCollision(D3DXVECTOR2 object, D3DXVECTOR2 object2, int radius1, int radius2)
{
	if(sqrt(pow((object2.x - object.x), 2) + pow((object2.y - object.y),2)) < (radius1 + radius2))
		return true;
	else
		return false;
}

bool Physics::circleCollision(D3DXVECTOR2 object, D3DXVECTOR2 object2, float radius1, float radius2)
{
	if(sqrt(pow((object2.x - object.x), 2) + pow((object2.y - object.y),2)) < (radius1 + radius2))
		return true;
	else
		return false;
}

bool Physics::worldColliBox(D3DXVECTOR2 object, int height, int width)
{
	if(object.x + width / 2 >= x)
		return true;
	else if(object.x - width / 2 <= 0)
		return true;
	else if(object.y + height / 2 >= y)
		return true;
	else if(object.y - height / 2 <= 0)
		return true;
	else
		return false;
}

bool Physics::boxCollision(D3DXVECTOR2 object, D3DXVECTOR2 object2, int height1, int width1, int height2, int width2)
{
	if(object.x + width1 / 2 >= object2.x - width2 / 2 && object.x - width1 / 2 <= object2.x + width2 / 2
		&& object.y + height1 / 2 >= object2.y - height2 / 2 && object.y - height1 / 2 <= object2.y + height2 / 2)
		return true;
	else
		return false;
}

bool Physics::boxCollision(D3DXVECTOR2 object, D3DXVECTOR2 object2, float height1, float width1, float height2, float width2)
{
	if(object.x + width1 / 2.0 >= object2.x - width2 / 2.0 && object.x - width1 / 2.0 <= object2.x + width2 / 2.0
		&& object.y + height1 / 2.0 >= object2.y - height2 / 2.0 && object.y - height1 / 2.0 <= object2.y + height2 / 2.0)
		return true;
	else
		return false;
}

bool Physics::circleToBoxCollison(D3DXVECTOR2 circlePos, D3DXVECTOR2 rectPos, float circleRadius, float rectWidth, float rectHeight)
{
	D3DXVECTOR2 circleDistance;

	circleDistance.x = abs(circlePos.x - rectPos.x);
    circleDistance.y = abs(circlePos.y - rectPos.y);

    if (circleDistance.x > (rectWidth/2 + circleRadius)) { return false; }
    if (circleDistance.y > (rectHeight/2 + circleRadius)) { return false; }

    if (circleDistance.x <= (rectWidth/2)) { return true; } 
    if (circleDistance.y <= (rectHeight/2)) { return true; }

    float cornerDistance_sq = pow((circleDistance.x - rectWidth/2), 2) + pow((circleDistance.y - rectHeight/2),2);

    return (cornerDistance_sq <= pow(circleRadius, 2));
}

bool Physics::isPointOn(D3DXVECTOR2 mousePos, D3DXVECTOR2 objectPos, int width, int height)
{
	if(objectPos.x - width / 2 < mousePos.x && objectPos.x + width / 2 > mousePos.x 
		&& objectPos.y - height / 2 < mousePos.y && objectPos.y + height / 2 > mousePos.y)
		return true;
	else
		return false;
}

//get
void Physics::getWorldSize(float x, float y)
{
	this->x = x;
	this->y = y;
}

/*void Collision::createCollisionBox(int width, int height, float posX, float posY)
{
	size.x = width;
	size.y = height;
	invisibleBoxPos.x = posX;
	invisibleBoxPos.y = posY;
}*/

void Physics::createCollisionBox(float width, float height, float posX, float posY)
{
	size.x = width;
	size.y = height;
	invisibleBoxPos.x = posX;
	invisibleBoxPos.y = posY;
}

bool Physics::boxCollision(D3DXVECTOR2 objectPos, int width, int height)
{
	if(objectPos.x + width / 2 >= invisibleBoxPos.x - size.x / 2 && objectPos.x - width / 2 <= invisibleBoxPos.x + size.x / 2
		&& objectPos.y + height / 2 >= invisibleBoxPos.y - size.y / 2 && objectPos.y - height / 2 <= invisibleBoxPos.y + size.y / 2)
		return true;
	else
		return false;
}

bool Physics::boxCollision(D3DXVECTOR2 objectPos, float width, float height)
{
	if(objectPos.x + width / 2 >= invisibleBoxPos.x - size.x / 2 && objectPos.x - width / 2 <= invisibleBoxPos.x + size.x / 2
		&& objectPos.y + height / 2 >= invisibleBoxPos.y - size.y / 2 && objectPos.y - height / 2 <= invisibleBoxPos.y + size.y / 2)
		return true;
	else
		return false;
}

void Physics::readConfig()
{
	ifstream configs("Configure File/windows.txt");

	string ignore;

	configs >> ignore;
	configs >> x;

	configs >> ignore;
	configs >> y;

	configs.close();
}

D3DXVECTOR2 Physics::getBoxSize()
{
	return size;
}

D3DXVECTOR2 Physics::getBoxPos()
{
	return invisibleBoxPos;
}

Physics::~Physics(void)
{
}
