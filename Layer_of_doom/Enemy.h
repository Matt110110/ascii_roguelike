#pragma once
#include <string>

using namespace std;

class Enemy
{
	int _attack, _defence, _hp, _expVal, _level; // stats
	char _tile; // Symbol for these useless things
	string _name; // Every generic villain needs a generic name

	int _x, _y; // Position variables
public:
	Enemy(string name, char tile, int attack, int defence, int hp, int expVal, int level);
	void getPositionOfEnemy(int & x, int & y);
	void setPositionOfEnemy(int x, int y);
	int getEnemyAttack();
	~Enemy();
};

