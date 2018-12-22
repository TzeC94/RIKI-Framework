#include "Transform.h"


Transform::Transform(void)
{
}


Transform::~Transform(void)
{
}

void Transform::Initialize(){

	position = center = heading = D3DXVECTOR2(0,0);
	scaling = D3DXVECTOR2(1, 1);
	radian = 0;

}

void Transform::Update(){

	Matrix(matrix, radian, scaling, heading, position);

}

void Transform::Matrix(D3DXMATRIX &matri, float Radian1, D3DXVECTOR2 &scaling, D3DXVECTOR2 &headings, D3DXVECTOR2 Pos)
{
	headings.x = sin(Radian1);
	headings.y = -cos(Radian1);

	mCenter = Pos;

	D3DXMatrixTransformation2D(&matri,
									NULL,
									NULL,
									&scaling,
									&Pos,
									Radian1,
									NULL
									);
}
