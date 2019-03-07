#include "Transform.h"


Transform::Transform(void)
{
}


Transform::~Transform(void)
{
}

void Transform::Initialize(){

	position = localPosition = center = heading = D3DXVECTOR2(0,0);
	scaling = D3DXVECTOR2(1, 1);
	radian = 0;
	UpdatePosition();
}

void Transform::Update(){

	Matrix();

	UpdatePosition();

	//std::cout<<position.x<<","<<localPosition.x<<"\n";

}

void Transform::UpdatePosition(){

	D3DXVECTOR2 vVector = D3DXVECTOR2(0.0, 0.0);

	if(parent != NULL){
	
		vVector = parent->position;

	}

	position = vVector + localPosition;

}

D3DXVECTOR2 Transform::GetPosition(){

	return position;

}

void Transform::SetPosition(D3DXVECTOR2 vector){

	localPosition = vector - position;
	
}

D3DXVECTOR2 Transform::GetLocalPosition(){

	return localPosition;

}

void Transform::SetLocalPosition(D3DXVECTOR2 vector){

	localPosition = vector;
	position += localPosition;
	UpdatePosition();
}

void Transform::Translate(D3DXVECTOR2 direction){

	SetLocalPosition(GetLocalPosition() + direction);

}

void Transform::Matrix()
{
	heading.x = sin(radian);
	heading.y = -cos(radian);

	mCenter = position;

	D3DXMatrixTransformation2D(&matrix,
									NULL,
									0.0,
									&scaling,
									&center,
									radian,
									&position
									);
}
