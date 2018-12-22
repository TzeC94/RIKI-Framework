#pragma once

#include <d3dx9math.h>

class Transform
{
private:
	void Matrix(D3DXMATRIX &matri, float Radian1, D3DXVECTOR2 &scaling, D3DXVECTOR2 &headings, D3DXVECTOR2 Pos);
	D3DXVECTOR2 mCenter;
public:
	Transform(void);
	~Transform(void);

	//Poition
	D3DXVECTOR2 position, center, heading, scaling;
	D3DXMATRIX matrix;
	float radian;

	void Initialize();
	void Update();

};

