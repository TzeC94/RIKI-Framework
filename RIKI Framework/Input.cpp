#include "Input.h"

bool upArrow, downArrow, leftArrow, rightArrow, one, two, three, four, five, mouseLeft, firstMouseLeft, KeyDown, firstDown;

string keyIn, otherKeyMsg;

D3DXVECTOR2 mousePos;

//Initialize outside
Input* Input::s_instance = NULL;

bool Input::DIisKey(int key){

	dInputKeyboardDevice->GetDeviceState(sizeof(m_keyboardState), diKeys);

	if(diKeys[key])
	{
		return true;
	}
	else
		return false;

}

Input::Input(void){

	dInput = 0;
	dInputKeyboardDevice = 0;

	firstMouseLeft = KeyDown = firstDown = false;

	KeyCode.Enter = VK_RETURN;
	KeyCode.Left = VK_LEFT;
	KeyCode.Down = VK_DOWN;
	KeyCode.Right = VK_RIGHT;
	KeyCode.Up = VK_UP;

	for(int i = 0; i < 10; i++)
		KeyCode.number[i] = i;

	//direct Input initialize
	g_Hwnd=NULL;

	DirectInput8Create(GetModuleHandle(NULL), 0x0800, IID_IDirectInput8, (void**)&dInput, NULL);
	
	dInput->CreateDevice(GUID_SysKeyboard, &dInputKeyboardDevice, NULL);
	dInputKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
	dInputKeyboardDevice->SetCooperativeLevel(g_Hwnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE);
	dInputKeyboardDevice->Acquire();

}

Input::~Input(void)
{
	//	Release keyboard device.
	dInputKeyboardDevice->Unacquire();
	dInputKeyboardDevice->Release();
	dInputKeyboardDevice = NULL;

	//	Release DirectInput.
	dInput->Release();
	dInput = NULL;
}

//Initialize instance
Input* Input::instance(){
	
	if(!s_instance)
		s_instance = new Input;

	return s_instance;

}

LRESULT CALLBACK Input::WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_MOUSEMOVE:
		mousePos.x = LOWORD(lParam);
		mousePos.y = HIWORD(lParam);
		break;
	case WM_LBUTTONDOWN:
		mouseLeft = true;
		firstMouseLeft = true;
		mousePos.x = LOWORD(lParam);
		mousePos.y = HIWORD(lParam);
		break;
	case WM_LBUTTONUP:
		mouseLeft = false;
		break;
	case WM_KEYUP:
		firstDown = false;
		keyIn = "";
		KeyDown = false;
		switch(wParam)
		{
		case VK_LEFT:
			leftArrow = false;
			break;
		case VK_RIGHT:
			rightArrow = false;
			break;
		case VK_UP:
			upArrow = false;
			break;
		case VK_DOWN:
			downArrow = false;
			break;
		}
		break;
	case WM_KEYDOWN:
		firstDown = true;
		KeyDown = true;
		keyIn = wParam;
		switch(wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		case VK_LEFT:
			leftArrow = true;
			break;
		case VK_RIGHT:
			rightArrow = true;
			break;
		case VK_UP:
			upArrow = true;
			break;
		case VK_DOWN:
			downArrow = true;
			break;
		}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

bool Input::isKeyDown()
{
	if(firstDown == true)
	{
		firstDown = false;
		return true;
	}
	else
		return false;
}

bool Input::isKeyDown(string Key)
{
	if(KeyDown == true)
	{
		KeyDown = false;
		if(keyIn == Key)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Input::isKeyDown(int key){

	if(GetKeyState(key) && 0x8000){

		return true;

	}

	return false;

}

bool Input::isKey(string key)
{
	if(keyIn == key)
		return true;
	else
		return false;
}

string Input::keyMsg()
{
	return keyIn;
}

bool Input::getKeyUp()
{
	return upArrow;
}

bool Input::getKeyDown()
{
	return downArrow;
}

bool Input::getKeyLeft()
{
	return leftArrow;
}

bool Input::getKeyRight()
{
	return rightArrow;
}

bool Input::mouseLeftDown()
{
	if(firstMouseLeft == true)
	{
		firstMouseLeft = false;
		return mouseLeft;
	}
	else
	{
		return false;
	}
}

D3DXVECTOR2 Input::getMousePos()
{
	return mousePos;
}

void Input::exitApplication()
{
	PostQuitMessage(0);
}

