#pragma once
#include <d3dx9.h>
#include <string>
#include <dinput.h>
#include <WinUser.h>

using namespace std;

struct keyCode{
	string Enter;
	string Up;
	string Down;
	string Left;
	string Right;
	//select from 0 to 9
	string number[10];
};

class Input{
	
	private:
		WPARAM wParams;

		LPDIRECTINPUT8 dInput;
		LPDIRECTINPUTDEVICE8  dInputKeyboardDevice;

		//record current state of keyboard
		unsigned char m_keyboardState[256];

		HWND g_Hwnd;
		BYTE  diKeys[256];

		static Input* s_instance;

	public:
		Input(void);
		~Input(void);

		void Initialize();

		//Singleton
		static Input* instance();

		keyCode KeyCode;

		static LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

		//arrow key
		bool getKeyUp();
		bool getKeyDown();
		bool getKeyLeft();
		bool getKeyRight();

		//to detect is any key pressed
		bool isKeyDown();
		//to detect which key pressed, not really work still under development
		bool isKeyDown(string Key);
		//Special get key down
		bool isKeyDown(int key);

		//to detect which key pressed
		//suitable for single purpose
		bool isKey(string Key);

		string keyMsg();	//return the key they press

		bool getKeyEnter();

		//other feature
		void exitApplication();

		//mouse feature
		bool mouseLeftDown();
		D3DXVECTOR2 getMousePos();

		//directInput
		void inputUpdate();
		bool DIisKey(int key);
};

