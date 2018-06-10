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
	void tryMovePlayer(char dir);
	~Level();
};

