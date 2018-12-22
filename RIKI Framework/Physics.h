#pragma once
#include <d3dx9.h>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

class Physics
{
private:
	float x, y;

	D3DXVECTOR2 invisibleBoxPos, size;

	void readConfig();

public:
	Physics(void);
	~Physics(void);

	void getWorldSize(float x, float y);

	//collision detection for world
	//Pass in the object 1 position and the radius of the object to do the collision with the world
	//collision detection for box
	bool worldCollision(D3DXVECTOR2 objectPos, float height, float width, bool centreDraw);
	//collision detection for circle, it may use for box if the height and width are the same
	bool worldCollision(D3DXVECTOR2 objectPos, float radius);

	//pass in object 1 and 2 position and the radius for object 1 and 2 to detect is they collide
	bool circleCollision(D3DXVECTOR2 objectPos, D3DXVECTOR2 object2Pos, int radius1, int radius2);
	bool circleCollision(D3DXVECTOR2 objectPos, D3DXVECTOR2 object2Pos, float radius1, float radius2);

	//collision for box
	//pass in the objct 1 position and the height and width to do the collision with the world
	bool worldColliBox(D3DXVECTOR2 objectPos, int height, int width);

	//pass in the object 1 and object 2 position and object 1 height and width and object 2 height and width to do the collision between 2 object
	bool boxCollision(D3DXVECTOR2 objectPos, D3DXVECTOR2 object2Pos, int height1, int width1, int height2, int width2);
	bool boxCollision(D3DXVECTOR2 objectPos, D3DXVECTOR2 object2Pos, float height1, float width1, float height2, float width2);

	bool circleToBoxCollison(D3DXVECTOR2 circlePos, D3DXVECTOR2 rectPos, float circleRadius,float rectWidth, float rectHeight);

	//suitable for mouse click, by pass in the position of the mouse and the position of the object, height and width to do the collision detection
	bool isPointOn(D3DXVECTOR2 mousePos, D3DXVECTOR2 objectPos, int width, int height);

	//creating a invisible collision box for detection, only allow to create 1 box for each decleration
	//void createCollisionBox(int width, int height, float posX, float posY);
	void createCollisionBox(float width, float height, float posX, float posY);

	//Collision detection for created invisible box only, please use another collision detection to detect object with object
	bool boxCollision(D3DXVECTOR2 objectPos, int width, int height);
	bool boxCollision(D3DXVECTOR2 objectPos, float width, float height);

	//return invisible box position
	D3DXVECTOR2 getBoxPos();

	//return invisible box x and y
	D3DXVECTOR2 getBoxSize();

};

