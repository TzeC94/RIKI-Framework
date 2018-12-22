#pragma once

#include <d3dx9math.h>
#include <iostream>

#include "Transform.h"
#include "Input.h"
#include "Time.h"

using namespace std;

class Player{

private:
	void KeyInput();

	float speed;

public:

	void Initialize();
	void Update();

	Transform transform;

};

