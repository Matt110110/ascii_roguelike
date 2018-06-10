#pragma once
#include "Player.h"
#include <string>

using namespace std;
class GameSystem
{
	Player _player;
public:
	GameSystem();
	GameSystem(string level);
	void logic();
	~GameSystem();
};

