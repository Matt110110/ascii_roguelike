#include "Level.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <fstream>

using namespace std;

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
			case '@': // Player
				player.setPosition(j, i);
				break;
			case 'g': // Guard
				_enemies.push_back(Enemy("Henchman", 'g', 1, 3, 1, 10, 1));
				_enemies.back().setPositionOfEnemy(j, i);
				break;
			case 'G': // Chief of guards
				_enemies.push_back(Enemy("Chief", 'G', 10, 10, 20, 50, 1));
				_enemies.back().setPositionOfEnemy(j, i);
				break;
			case 'D': // Don
				_enemies.push_back(Enemy("Don", 'D', 50, 50, 200, 100, 1));
				_enemies.back().setPositionOfEnemy(j, i);
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
		system("PAUSE");
		break;
	}
}

void Level::battleEnemy(Player & player, int targetX, int targetY)
{
	int enemyX, enemyY, attackRoll, attackresult;
	for (int i = 0; i < _enemies.size(); i++)
	{
		_enemies[i].getPositionOfEnemy(enemyX, enemyY);
		if (targetX == enemyX && targetY == enemyY)
		{
			cout << endl << "Player attacked the enemy!" << endl;
			// Let the battle begin
			attackRoll = player.getPlayerAttack();
			attackresult = _enemies[i].takeDamage(attackRoll);
			if (attackresult != 0)
			{
				cout << endl << "Player killed the enemy!" << endl;
				system("PAUSE");
				player.addExp(attackresult);
				setTile(targetX, targetY, '.');
				printLevel();
				return;
			}
			
			// Enemy will fight
			player.getPosition(targetX, targetY);
			_enemies[i].getPositionOfEnemy(enemyX, enemyY);
			if (enemyX == targetX && enemyY == targetY)
			{
				attackRoll = _enemies[i].getEnemyAttack();
				attackresult = player.takeDamage(attackRoll);
				if (attackresult == 0)
				{
					cout << "\nEnemy attack was super effective! Run for your life.\n";
				}
				else
				{
					setTile(targetX, targetY, 'X');
					printLevel();
					cout << "\nYOU DIED!\n";
					system("PAUSE");
					exit(0);
				}
			}
			else
			{
				cout << endl << "Successfully dodged.\n";
				player.addExp(5);
			}
			return;
		}
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
	case '.': // This air
		player.setPosition(x, y);
		setTile(pX, pY, '.');
		setTile(x, y, '@');
		break;
	case '#': // Wall
		break;
	default: // Enemy
		battleEnemy(player, x, y);
		break;
	}
}


Level::~Level()
{
}
