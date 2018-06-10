#include "GameSystem.h"
#include <string>

using namespace std;

GameSystem::GameSystem()
{
}

GameSystem::GameSystem(string levelFile)
{
	_level.loadLevel(levelFile);
	_level.printLevel();

	system("PAUSE");
}

void GameSystem::logic()
{

}


GameSystem::~GameSystem()
{
}
