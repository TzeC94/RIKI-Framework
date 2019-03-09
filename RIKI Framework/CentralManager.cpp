#include "CentralManager.h"


CentralManager::CentralManager(void){

	readConfig();

	TM.readTileMap("Configure File/map.txt");

	tile[0] = NULL;
	tile[1] = NULL;

}

void CentralManager::initialize(){

	//input = new Input();

	SetPosition(tilePos, 0, 0);
	SetCentre(centerTile, 45, 45);

	playerP.Initialize();

	player.Initialize();
	player.SetMovement(false);
	player.transform.parent = &playerP.transform;
	player.transform.SetLocalPosition(D3DXVECTOR2(50, 50));
	playerAnimation.InitNewAnimationSheet(D3DXVECTOR2(128.0f, 128.0f), D3DXVECTOR2(1024.0f, 128.0f), 0.25f, 0);

	scroll_mountain.initialize(600, 500, 1800, 600, 10);

}

void CentralManager::loadPicture() 
{
	LoadTexture("Texture/Tile.png", tile[0], 90, 90);
	LoadTexture("Texture/Tile2.png", tile[1], 90, 90);
	LoadTexture("Texture/PlayerIDLE.png", playerTexture, D3DX_DEFAULT, D3DX_DEFAULT);
	LoadTexture("Texture/BGmountain.png", mountain, D3DX_DEFAULT, D3DX_DEFAULT);

}

void CentralManager::setRectsAndCenter(){
	
	SetCentre(mountainCenter, 600, 140);

}

void CentralManager::drawTexture(){

	//System Update
	sprite->SetTransform(&emptyMatrix);

	//Scrolling
	Draw(mountain, mountainCenter, scroll_mountain.getPosition());
	Draw(mountain, mountainCenter, scroll_mountain.getPosition2());

	//Draw Tile
	int count = 0;

	for(int y = 0; y < TM.getTileSize().y; y++){

		for(int x = 0; x < TM.getTileSize().x;x++){

			int tileType = TM.getTileType(count);

			if(tileType != 0){
			
				Draw(tile[TM.getTileType(count) - 1], TM.tilePos(tilePos, x, y, 90, 90));

			}
			
			count++;

		}

	}

	//Draw player
	sprite->SetTransform(&playerP.transform.matrix);
	Draw(playerTexture, playerP.transform.center, playerAnimation.GetRect());

	sprite->SetTransform(&player.transform.matrix);
	Draw(playerTexture, player.transform.center, playerAnimation.GetRect());

	//System Update
	sprite->SetTransform(&emptyMatrix);

}

void CentralManager::updateLogic(){

	//DirectX Update
	UpdateWorldMatrix();

	//System update delta time
	Time::instance()->update();

	//Update Animation
	playerAnimation.AnimationUpdate();

	//Update player login
	playerP.Update();
	player.Update();

	scroll_mountain.update();

}

void CentralManager::checkKey(){

}

void CentralManager::release(){
	tile[0]->Release();
	tile[1]->Release();
	playerTexture->Release();
}

void CentralManager::readConfig(){
	
}

CentralManager::~CentralManager(void)
{
	
}
