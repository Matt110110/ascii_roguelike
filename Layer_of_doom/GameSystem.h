#pragma once
#include "Player.h"
#include "Level.h"
#include <string>

using namespace std;
class GameSystem
{
	Player _player;
	Level _level;
	
	void _playerMovement();
public:
	GameSystem(string levelFile);
	void logic();
	~GameSystem();
};

