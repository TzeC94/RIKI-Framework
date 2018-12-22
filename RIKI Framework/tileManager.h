#pragma once
#include <d3dx9.h>
#include <d3d9.h>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class tileManager
{
private:
	D3DXVECTOR2 tileSize;
	//vector<int> tileType;

	int *tileType;

public:
	tileManager(void);
	~tileManager(void);
	
	//get the tile size
	D3DXVECTOR2 getTileSize();
	//calculate the new or current tile position
	D3DXVECTOR2 tilePos(D3DXVECTOR2 firstPos, int x, int y, int width, int height);

	//custom the tile size
	void setTileSize(float x, float y);
	//get the area of the tile map
	int getAreaTile();
	//read the tile map
	void readTileMap(string destinationOfFile);
	//get the tile type
	int getTileType(int counter);
	
};

