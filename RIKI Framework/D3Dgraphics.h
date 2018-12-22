#ifndef D3DGRAPHICS_H
#define D3DGRAPHICS_H

#include <d3dx9.h>
#include <d3d9.h>
#include "Input.h"
#include <string>
#include <sstream>

#define WIN32_LEAD_AND_MEAN

using namespace std;

class D3Dgraphics{

private:
	HWND g_hWnd;
	
	IDirect3D9 * direct3D9;
	D3DPRESENT_PARAMETERS d3dPP;
	WNDCLASS wndClass;
	
	MSG msg;

	bool CheckHR();

protected:
	//sprite
	LPD3DXSPRITE sprite;

	//D3DTEXTURE
	// example LPDIRECT3DTEXTURE9 xxx

	//Font
	LPD3DXFONT font;

	D3DXVECTOR2 originPos;

	IDirect3DDevice9 * d3dDevice;
	HRESULT hr;

public:
	//Matrix
	D3DXMATRIX emptyMatrix;
	D3DXVECTOR2 emptyHeading, emptyPos, emptyCenter;
	void UpdateWorldMatrix();

	//Constructer
	D3Dgraphics();
	~D3Dgraphics();

	//Initialize
	void Initializes();
	void D3D_CreateWindow(HINSTANCE hInstance, int windowsPosX, int windowsPosY, int width, int height, bool cursor, string name);
	bool WindowsIsRunning();
	void CleanupWindows(HINSTANCE hInstance);
	void IntiDirectX(bool windowed, int width, int height);

	//DirectX function
	void DrawTexture();

	//Draw Function
	void DrawBegin();
	void DrawEnd();

	//Simple draw function by passing in the position only
	void Draw(LPDIRECT3DTEXTURE9 &name, D3DXVECTOR2 Position);
	//Simple draw function by passing in the poistion and the color
	void Draw(LPDIRECT3DTEXTURE9 &name, D3DXVECTOR2 Position, int R, int G, int B);
	//draw an object with passing the rectangle of the object
	void Draw(LPDIRECT3DTEXTURE9 &name, RECT &nameRect, D3DXVECTOR2 Position);
	//draw an object with passing the rectangle of the object and the color
	void Draw(LPDIRECT3DTEXTURE9 &name, RECT &nameREct, D3DXVECTOR2 Position, int R, int G, int B);
	//draw an object with passing the centre of the object
	void Draw(LPDIRECT3DTEXTURE9 &name, D3DXVECTOR2 Centre, D3DXVECTOR2 Position);
	//draw an object with passing the centre of the object and the color
	void Draw(LPDIRECT3DTEXTURE9 &name, D3DXVECTOR2 Centre, D3DXVECTOR2 Position, int R, int G, int B);
	//draw an ojbect with passing the centre and rectangle of the object
	void Draw(LPDIRECT3DTEXTURE9 &name, D3DXVECTOR2 Centre, RECT &nameRect, D3DXVECTOR2 Position);
	//draw an object with passing the centre an drectangle of the object and also the color
	void Draw(LPDIRECT3DTEXTURE9 &name, D3DXVECTOR2 Centre, RECT &nameRect, D3DXVECTOR2 Position, int R, int G, int B);

	//Load your texture by passing location of the image, DirectX 3D texture name and size x and y
	void LoadTexture(string locate, LPDIRECT3DTEXTURE9 &name, int x, int y);

	void SetRect(RECT &nameRect, int left, int top, int right, int down);

	//automatic find out the centre of the object by passing in the width and height of the object
	void SetCentreAuto(D3DXVECTOR2 &centre, float width, float height);
	//manually input the centre of the object
	void SetCentre(D3DXVECTOR2 &centre, float x, float y);

	//set the position
	void SetPosition(D3DXVECTOR2 &vector2, float x, float y);

	//Initialize the font size with pass in the height and width
	void InitializeFont(LPD3DXFONT &fontParameter, int height, int width);

	void DrawFont(LPD3DXFONT &font, string text, RECT &textRect);

	//input
	//Input input;

	//Convert number to string
	string numberToString(float number);

};
#endif

