#include "rotation.h"


rotation::rotation(void)
{
}

void rotation::emptyMatrix(LPD3DXSPRITE &sprite)
{

	D3DXMatrixTransformation2D(&matrix,NULL,0.0f,NULL,NULL,NULL,NULL);
	sprite->SetTransform(&matrix);

}

void rotation::moveMatrix(D3DXVECTOR2 pos, float rotation, LPD3DXSPRITE &sprite)
{
	D3DXMatrixTransformation2D(&matrix, NULL, NULL, NULL, &pos, rotation,NULL);
	sprite->SetTransform(&matrix);

	rotationVar = rotation;
}

D3DXVECTOR2 rotation::moveDirection(D3DXVECTOR2 &pos, float velocity)
{
	pos.x += sin(rotationVar) * velocity;
	pos.y -= cos(rotationVar) * velocity;

	return pos;
}

float rotation::getFaceRadian(D3DXVECTOR2 ownObject, D3DXVECTOR2 targetObject)
{
	return atan2(-(ownObject.x - targetObject.x), (ownObject.y - targetObject.y));
}


rotation::~rotation(void)
{
	
}
