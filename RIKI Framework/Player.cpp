#include "Player.h"


void Player::Initialize(){

	move = true;

	transform.Initialize();
	transform.center = D3DXVECTOR2(64,64);
	transform.SetPosition(D3DXVECTOR2(50, 50));
	transform.scaling = D3DXVECTOR2(1, 1);

	speed = 20;

}

void Player::Update(){

	transform.Update();
	KeyInput();
}

void Player::SetMovement(bool canMove){

	move = canMove;

}

void Player::KeyInput(){

	if(move == false)
		return;

	float deltaTime = Time::instance()->deltaTime();

	if(Input::instance()->DIisKey(DIK_D)){
	
		transform.Translate(D3DXVECTOR2(1, 0) * speed * deltaTime);

	}

	if(Input::instance()->DIisKey(DIK_A)){
	
		transform.Translate(D3DXVECTOR2(-1, 0) * speed * deltaTime);

	}

	if(Input::instance()->DIisKey(DIK_W)){
	
		transform.Translate(D3DXVECTOR2(0, -1) * speed * deltaTime);

	}

	if(Input::instance()->DIisKey(DIK_S)){
	
		transform.Translate(D3DXVECTOR2(0, 1) * speed * deltaTime);

	}

	if(Input::instance()->DIisKey(DIK_G)){
	
		//transform.localPosition += D3DXVECTOR2(1, 0) * speed * deltaTime;
		transform.SetPosition(D3DXVECTOR2(50, 50));
	}

}