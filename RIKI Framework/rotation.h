#pragma once
#include <d3dx9math.h>
#include <d3dx9.h>
#include <cmath>

class rotation
{
private:
	float rotationVar;
	D3DXMATRIX matrix;

public:
	rotation(void);
	~rotation(void);

	void emptyMatrix(LPD3DXSPRITE &sprite);

	void moveMatrix(D3DXVECTOR2 pos, float rotation, LPD3DXSPRITE &sprite);

	//return the newest position after calculation
	D3DXVECTOR2 moveDirection(D3DXVECTOR2 &pos, float velocity);

	//function used to calculate the radian between objectPos and targetPos, function will return the radian between themselve
	float getFaceRadian(D3DXVECTOR2 ownObject, D3DXVECTOR2 targetObject);

};

