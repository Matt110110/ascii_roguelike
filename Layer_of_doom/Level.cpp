#include "Level.h"
#include "Player.h"
#include <iostream>
#include <fstream>


Level::Level()
{

}

void Level::loadLevel(string fileName, Player & player)
{
	ifstream file;
	file.open(fileName);

	// Check if the file is open correctly or not
	if (file.fail())
	{
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}

	string line;
	while (getline(file, line))
	{
		_levelData.push_back(line);
	}

	file.close();

	char tile;
	for (int i = 0; i < _levelData.size(); i++)
	{
		for (int j = 0; j < _levelData[i].size(); j++)
		{
			tile = _levelData[i][j];

			switch (tile)
			{
			case '@':
				player.setPosition(j, i);
				break;
			default:
				break;
			}
		}
	}
}

void Level::printLevel()
{
	// Clear screen before loading a level.
	system("cls"); // Use clear instead when using Unix based system like some Linux distro or MacOS. 

	for (int i = 0; i < _levelData.size(); i++)
	{
		printf("%s\n", _levelData[i].c_str()); // May require a header file for this function. Visual studio runs fine but other IDEs or OS might not give same result.
	}
	cout << endl;
}

void Level::setTile(int x, int y, char tile)
{
	_levelData[y][x] = tile;
}

void Level::tryMovePlayer(char dir, Player & player)
{
	char moveTile;
	int playerX, playerY; // X and Y coordinates of the Player
	player.getPosition(playerX, playerY);
	switch (dir)
	{
	case 'w': // up
	case 'W':
		movePlayer(getTile(playerX, playerY - 1), playerX, playerY - 1, player);
		break;
	case 's': // down
	case 'S':
		movePlayer(getTile(playerX, playerY + 1), playerX, playerY + 1, player);
		break;
	case 'a': // left
	case 'A':
		movePlayer(getTile(playerX - 1, playerY), playerX - 1, playerY, player);
		break;
	case 'd': // right
	case 'D':
		movePlayer(getTile(playerX + 1, playerY), playerX + 1, playerY, player);
		break;
	default:
		cout << "\nINVALID INPUT!\n";
		system("PAUSE");
		break;
	}
}

char Level::getTile(int x, int y)
{
	return _levelData[y][x];
}

void Level::movePlayer(char tile, int x, int y, Player & player)
{
	int pX, pY;
	player.getPosition(pX, pY);
	switch (tile)
	{
	case '#':
		cout << "\nYou ran into a wall!\n";
		system("PAUSE");
		break;
	case '.':
		player.setPosition(x, y);
		setTile(pX, pY, '.');
		setTile(x, y, '@');
		break;
	case 'M':
		break;
	default:
		break;
	}
}


Level::~Level()
{
}
