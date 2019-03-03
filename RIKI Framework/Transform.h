#pragma once

#include <d3dx9math.h>
#include <iostream>

class Transform
{
private:
	void Matrix();
	D3DXVECTOR2 mCenter;

	//Poition
	D3DXVECTOR2 position, localPosition;

	void UpdatePosition();

public:
	Transform(void);
	~Transform(void);

	//Poition
	//D3DXVECTOR2 position, localPosition;
	D3DXVECTOR2 GetPosition();
	D3DXVECTOR2 GetLocalPosition();
	
	void SetPosition(D3DXVECTOR2 vector);
	void SetLocalPosition(D3DXVECTOR2 vector);

	//Move
	void Translate(D3DXVECTOR2 direction);

	//Center
	D3DXVECTOR2 center;
	
	//Direction
	D3DXVECTOR2 heading;
	
	//Scaling/Size
	D3DXVECTOR2 scaling;
	
	//Parent
	Transform *parent;

	D3DXMATRIX matrix;
	
	float radian;

	void Initialize();
	void Update();

};

