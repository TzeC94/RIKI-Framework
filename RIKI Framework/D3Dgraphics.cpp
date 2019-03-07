#include "D3Dgraphics.h"


D3Dgraphics::D3Dgraphics()
{

}

void D3Dgraphics::Initializes()
{
	g_hWnd = NULL;
	sprite = NULL;
	font = NULL;

	originPos.x = originPos.y = 0;
}

void D3Dgraphics::UpdateWorldMatrix(){

	emptyHeading.x = sin(NULL);
	emptyHeading.y = -cos(NULL);

	emptyCenter = emptyPos;

	D3DXMatrixTransformation2D(&emptyMatrix,
									NULL,
									NULL,
									NULL,
									&emptyPos,
									NULL,
									NULL
									);

}

void D3Dgraphics::D3D_CreateWindow(HINSTANCE hInstance, int windowsPosX, int windowsPosY, int width, int height, bool cursor, string name)
{
	ZeroMemory(&wndClass, sizeof(wndClass));

	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hInstance = GetModuleHandle(NULL);
	wndClass.lpszClassName = "My Window";
	//wndClass.lpfnWndProc = input.WindowProcedure;
	wndClass.lpfnWndProc = Input::instance()->WindowProcedure;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	g_hWnd = CreateWindowEx(0, wndClass.lpszClassName, name.c_str(), WS_OVERLAPPEDWINDOW, windowsPosX, windowsPosY, width, height, NULL, NULL, GetModuleHandle(NULL), NULL);
	ShowWindow(g_hWnd, 1);

	ShowCursor(cursor);
}

bool D3Dgraphics::WindowsIsRunning()
{
	ZeroMemory(&msg, sizeof(msg));

	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT) return false;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return true;
}

void D3Dgraphics::CleanupWindows(HINSTANCE hInstance)
{
	UnregisterClass("My Window", hInstance);
}

void D3Dgraphics::IntiDirectX(bool windowed, int width, int height)
{
	direct3D9 = Direct3DCreate9(D3D_SDK_VERSION);

	ZeroMemory(&d3dPP, sizeof(d3dPP));

	d3dPP.Windowed = windowed;
	d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dPP.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dPP.BackBufferCount = 1;
	d3dPP.BackBufferWidth = width;
	d3dPP.BackBufferHeight = height;
	d3dPP.hDeviceWindow = g_hWnd;

	direct3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dPP, &d3dDevice);

	D3DXCreateSprite(d3dDevice, &sprite);

	CheckHR();
}

void D3Dgraphics::Draw(LPDIRECT3DTEXTURE9 &name, D3DXVECTOR2 Position)
{
	sprite->Draw(name, NULL, NULL, &D3DXVECTOR3(Position.x, Position.y, 0), D3DCOLOR_XRGB(255, 255, 255));
}

void D3Dgraphics::Draw(LPDIRECT3DTEXTURE9 &name, RECT &nameRect)
{
	//sprite->Draw(name, &nameRect, &D3DXVECTOR3(x1, y1, z1), &D3DXVECTOR3(x2, y2, z2), D3DCOLOR_XRGB(255, 255, 255));
	sprite->Draw(name, &nameRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
}

void D3Dgraphics::Draw(LPDIRECT3DTEXTURE9 &name, D3DXVECTOR2 Position, int R, int G, int B)
{
	sprite->Draw(name, NULL, NULL, &D3DXVECTOR3(Position.x, Position.y, 0), D3DCOLOR_XRGB(R, G, B));
}

void D3Dgraphics::Draw(LPDIRECT3DTEXTURE9 &name, RECT &nameRect, D3DXVECTOR2 Position)
{
	//sprite->Draw(name, &nameRect, &D3DXVECTOR3(x1, y1, z1), &D3DXVECTOR3(x2, y2, z2), D3DCOLOR_XRGB(255, 255, 255));
	sprite->Draw(name, &nameRect, NULL, &D3DXVECTOR3(Position.x, Position.y, 0), D3DCOLOR_XRGB(255, 255, 255));
}

void D3Dgraphics::Draw(LPDIRECT3DTEXTURE9 &name, RECT &nameREct, D3DXVECTOR2 Position, int R, int G, int B)
{
	sprite->Draw(name, &nameREct, NULL, &D3DXVECTOR3(Position.x, Position.y, 0), D3DCOLOR_XRGB(R, G, B));
}

void D3Dgraphics::Draw(LPDIRECT3DTEXTURE9 &name, D3DXVECTOR2 Centre, D3DXVECTOR2 Position)
{
	//sprite->Draw(name, &nameRect, &D3DXVECTOR3(x1, y1, z1), &D3DXVECTOR3(x2, y2, z2), D3DCOLOR_XRGB(255, 255, 255));
	sprite->Draw(name, NULL, &D3DXVECTOR3(Centre.x, Centre.y, 0), &D3DXVECTOR3(Position.x, Position.y, 0), D3DCOLOR_XRGB(255, 255, 255));
}

void D3Dgraphics::Draw(LPDIRECT3DTEXTURE9 &name, D3DXVECTOR2 Centre, D3DXVECTOR2 Position, int R, int G, int B)
{
	sprite->Draw(name, NULL, &D3DXVECTOR3(Centre.x, Centre.y, 0), &D3DXVECTOR3(Position.x, Position.y, 0), D3DCOLOR_XRGB(R, G, B));
}

void D3Dgraphics::Draw(LPDIRECT3DTEXTURE9 &name, D3DXVECTOR2 Centre, RECT &nameRect)
{
	sprite->Draw(name, &nameRect, &D3DXVECTOR3(Centre.x, Centre.y, 0), NULL, D3DCOLOR_XRGB(255, 255, 255));
}

void D3Dgraphics::Draw(LPDIRECT3DTEXTURE9 &name, D3DXVECTOR2 Centre, RECT &nameRect, D3DXVECTOR2 Position)
{
	sprite->Draw(name, &nameRect, &D3DXVECTOR3(Centre.x, Centre.y, 0), &D3DXVECTOR3(Position.x, Position.y, 0), D3DCOLOR_XRGB(255, 255, 255));
}

void D3Dgraphics::Draw(LPDIRECT3DTEXTURE9 &name, D3DXVECTOR2 Centre, RECT &nameRect, D3DXVECTOR2 Position, int R, int G, int B)
{
	sprite->Draw(name, &nameRect, &D3DXVECTOR3(Centre.x, Centre.y, 0), &D3DXVECTOR3(Position.x, Position.y, 0), D3DCOLOR_XRGB(R, G, B));
}

void D3Dgraphics::LoadTexture(string locate, LPDIRECT3DTEXTURE9 &name, int x, int y)
{
	hr = D3DXCreateTextureFromFileEx(d3dDevice, locate.c_str(), x, y, 
										D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, 
										D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 255, 255), 
										NULL, NULL, &name);

	if(hr)
	{
		string msg = "Fail to load texture    " + locate;
		MessageBox(NULL, msg.c_str(), "Error", MB_OK);
		
	}
}

void D3Dgraphics::SetRect(RECT &nameRect, int left, int top, int right, int down)
{
	nameRect.bottom = down;
	nameRect.left = left;
	nameRect.top = top;
	nameRect.right = right;
}

void D3Dgraphics::SetPosition(D3DXVECTOR2 &vector2, float x, float y)
{
	vector2.x = x;
	vector2.y = y;
}

void D3Dgraphics::SetCentreAuto(D3DXVECTOR2 &centre, float width, float height)
{
	centre.x = width / 2;
	centre.y = height / 2;
}

void D3Dgraphics::SetCentre(D3DXVECTOR2 &centre, float x, float y)
{
	centre.x = x;
	centre.y = y;
}

void D3Dgraphics::InitializeFont(LPD3DXFONT &fonts,int height, int weight)
{
	hr = D3DXCreateFont(d3dDevice, height, weight, 0, 1, true,
				DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
				DEFAULT_PITCH | FF_DONTCARE, "Arial", &fonts);
}

void D3Dgraphics::DrawFont(LPD3DXFONT &font, string text, RECT &textRect)
{
	font->DrawText(sprite, text.c_str(), -1, &textRect, 0, D3DCOLOR_XRGB(0, 0, 0));
}

bool D3Dgraphics::CheckHR()
{
	if(FAILED(hr))
		return false;

	return true;
}

void D3Dgraphics::DrawBegin()
{
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(63, 143, 210), 1.0f, 0);
	d3dDevice->BeginScene();
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void D3Dgraphics::DrawEnd()
{
	sprite->End();
	d3dDevice->EndScene();
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

D3Dgraphics::~D3Dgraphics()
{
}

string D3Dgraphics::numberToString(float number)
{
	stringstream SS;
	SS << number;
	return SS.str();
}