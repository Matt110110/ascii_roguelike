#include "Enemy.h"
#include <string>
#include <random>
#include <ctime>

using namespace std;

Enemy::Enemy(string name, char tile, int attack, int defence, int hp, int expVal, int level)
{
	_name = name;
	_tile = tile;
	_attack = attack;
	_defence = defence;
	_hp = hp;
	_expVal = expVal;
	_level = level;
}

void Enemy::getPositionOfEnemy(int & x, int & y)
{
	x = _x;
	y = _y;
}

void Enemy::setPositionOfEnemy(int x, int y)
{
	_x = x;
	_y = y;
}

int Enemy::getEnemyAttack()
{
	static mt19937 randomEngine(time(NULL));
	uniform_int_distribution<int> attack(0, _attack);
	return attack(randomEngine);
}


Enemy::~Enemy()
{
}
