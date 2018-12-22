#include "Player.h"


void Player::Initialize(){

	transform.Initialize();
	transform.center = D3DXVECTOR2(64,64);
	transform.position = D3DXVECTOR2(50, 50);
	transform.scaling = D3DXVECTOR2(1, 1);

	speed = 20;

}

void Player::Update(){

	transform.Update();
	KeyInput();
}


void Player::KeyInput(){

	float deltaTime = Time::instance()->deltaTime();

	if(Input::instance()->DIisKey(DIK_D)){
	
		transform.position += D3DXVECTOR2(1, 0) * speed * deltaTime;

	}

	if(Input::instance()->DIisKey(DIK_A)){
	
		transform.position += D3DXVECTOR2(-1, 0) * speed * deltaTime;

	}

	if(Input::instance()->DIisKey(DIK_W)){
	
		transform.position += D3DXVECTOR2(0, -1) * speed * deltaTime;

	}

	if(Input::instance()->DIisKey(DIK_S)){
	
		transform.position += D3DXVECTOR2(0, 1) * speed * deltaTime;

	}

}