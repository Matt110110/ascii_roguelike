#include "GameSystem.h"
#include <string>
#include <conio.h>
#include <iostream>

using namespace std;


void GameSystem::_playerMovement()
{
	char dir;
	cout << "\nEnter direction you want to move in: \n";
	dir = _getch();

	_level.tryMovePlayer(dir, _player);
}

GameSystem::GameSystem(string levelFile)
{
	_player.init(1, 100, 10, 10, 0);

	_level.loadLevel(levelFile, _player);

	system("PAUSE");
}

void GameSystem::logic()
{
	bool isFinished = false;
	while (isFinished != true)
	{
		_level.printLevel();
		_playerMovement();
	}
}


GameSystem::~GameSystem()
{
}
