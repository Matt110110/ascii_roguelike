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

void Level::tryMovePlayer(char dir)
{
	switch (dir)
	{
	case 'w': // up
	case 'W':
		break;
	case 's': // down
	case 'S':
		break;
	case 'a': // left
	case 'A':
		break;
	case 'd': // right
	case 'D':
		break;
	default:
		cout << "\nINVALID INPUT!\n";
		system("PAUSE");
		break;
	}
}


Level::~Level()
{
}
