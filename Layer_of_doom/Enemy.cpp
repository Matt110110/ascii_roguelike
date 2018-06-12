#include "Enemy.h"
#include <string>
#include <random>
#include <ctime>

using namespace std;

void Enemy::_regenerateDefence(int defence)
{
	_defence = (int)(defence - ((20 / 100)*defence));
}

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

int Enemy::takeDamage(int attack)
{
	int originalDef = _defence;
	int temp = attack;
	attack -= _defence;
	if (attack <= 0)
	{
		_defence -= temp;
		return 0;
	}
	if (_defence <= 0)
	{
		_regenerateDefence(originalDef);
	}
	_hp -= attack;
	if (_hp > 0)
	{
		return 0;
	}
	return _expVal;
}


Enemy::~Enemy()
{
}
