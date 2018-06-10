#pragma once
#include <string>
#include <vector>
#include "Player.h"

using namespace std;

class Level
{
	vector<string> _levelData;
	char getTile(int x, int y);
	void setTile(int x, int y, char tile);
	void movePlayer(char tile, int x, int y, Player & player);
public:
	Level();
	void loadLevel(string fileName, Player &player);
	void printLevel();
	void tryMovePlayer(char dir, Player &player);
	~Level();
};

