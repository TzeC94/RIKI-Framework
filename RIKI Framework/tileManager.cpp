#include "tileManager.h"


tileManager::tileManager(void)
{
	tileSize.x = 4;
	tileSize.y = 4;
}

void tileManager::setTileSize(float x, float y)
{
	tileSize.x = x;
	tileSize.y = y;
}

void tileManager::readTileMap(string destinationOfFile)
{
	string ignore;
	int mapInfo;

	int count = 0;

	ifstream mapFile(destinationOfFile);

	mapFile >> ignore;
	mapFile >> tileSize.x;

	mapFile >> ignore;
	mapFile >> tileSize.y;

	tileType = new int[getAreaTile()];

	while(!mapFile.eof())
	{
		mapFile >> mapInfo;
		//tileType.push_back(mapInfo);
		tileType[count] = mapInfo;
		cout<<tileType[count]<<" ";
		count++;
	}
	cout<<"Tile x: " << tileSize.x <<" Tile y: "<<tileSize.y<<endl<<"Total Tile : " << getAreaTile();

	mapFile.close();
}

int tileManager::getTileType(int counter)
{
	return tileType[counter];
}

int tileManager::getAreaTile()
{
	return (int)(tileSize.x * tileSize.y);
}

D3DXVECTOR2 tileManager::getTileSize()
{
	return tileSize;
}

D3DXVECTOR2 tileManager::tilePos(D3DXVECTOR2 firstPos, int x, int y, int width, int height)
{
	firstPos.x = firstPos.x + (width * x);
	firstPos.y = firstPos.y + (height * y);

	return firstPos;
}



tileManager::~tileManager(void)
{
}
