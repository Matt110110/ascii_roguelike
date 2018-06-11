#pragma once
#include <string>
#include <vector>
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Level
{
	vector<string> _levelData;
	vector<Enemy> _enemies;
	void battleEnemy(Player & player, int targetX, int targetY);
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

