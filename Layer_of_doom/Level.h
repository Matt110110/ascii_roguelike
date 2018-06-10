#pragma once
#include <string>
#include <vector>
#include "Player.h"

using namespace std;

class Level
{
	vector<string> _levelData;
public:
	Level();
	void loadLevel(string fileName, Player &player);
	void printLevel();
	void setTile(int x, int y, char tile);
	void tryMovePlayer(char dir, Player &player);
	char getTile(int x, int y);
	void movePlayer(char tile, int x, int y, Player & player);
	~Level();
};

