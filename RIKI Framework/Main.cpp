#include "CentralManager.h"
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;


/*
Solved
FMOD error issue, no need open and change the directory again

Improved
Input class mirror improved
more draw option
delta time added
*/

//variable
int width, height;
bool window = true;
bool cursor = true;
string projectName;

//functions
void readConfig();

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	readConfig();

	CentralManager *CM = new CentralManager();

	CM->Initializes();
	CM->D3D_CreateWindow(hInstance,200, 0, width+15, height+35, cursor, projectName);
	CM->IntiDirectX(window, width, height);
	CM->loadPicture();
	CM->setRectsAndCenter();
	CM->initialize();
	while(CM->WindowsIsRunning())
	{
		CM->checkKey();
		CM->updateLogic();
		CM->DrawBegin();
		CM->drawTexture();
		CM->DrawEnd();
	}
	CM->release();
	CM->CleanupWindows(hInstance);

	delete CM;

	return 0;
}

void readConfig()
{
	ifstream configs("Configure File/windows.txt");

	string ignore, windowAns, cursorAns;

	configs >> ignore;
	configs >> width;

	configs >> ignore;
	configs >> height;

	configs >> ignore;
	configs >> windowAns;

	configs >> ignore;
	configs >> cursorAns;

	configs >>ignore;
	getline(configs, projectName);

	configs.close();

	if(windowAns == "true")
		window = true;
	else
		window = false;

	if(cursorAns == "true")
		cursor = true;
	else
		cursor = false;
}