#pragma once
#include "Player.h"
#include "Level.h"
#include <string>

using namespace std;
class GameSystem
{
	Player _player;
	Level _level;
public:
	GameSystem();
	GameSystem(string levelFile);
	void logic();
	~GameSystem();
};

