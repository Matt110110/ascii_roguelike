#pragma once
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include <string>

using namespace std;
class GameSystem
{
	Player _player;
	Level _level;
	vector<Enemy> _enemies;
	void _playerMovement();
public:
	GameSystem(string levelFile);
	void logic();
	~GameSystem();
};

