#include "Player.h"
#include <stdio.h>
#include <iostream>

using namespace std;

void Player::_generageDef(int def)
{
	// Player defence does not decrease gradually because he is the main player and the game will become really hard.
	_defence = def;
}

Player::Player()
{
	_x = 0;
	_y = 0;
}

void Player::init(int level, int health, int attack, int defence, int experience)
{
	_level = level;
	_health = health;
	_attack = attack;
	_defence = defence;
	_experience = experience;
}

void Player::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

void Player::getPosition(int & x, int & y)
{
	x = _x;
	y = _y;
}

int Player::getPlayerAttack()
{
	return _attack;
}

void Player::addExp(int exp)
{
	_experience += exp;
	while (_experience > 50)
	{
		printf("Leveled up!\n");
		_experience -= 50;
		_attack += 10;
		_health += 10;
		_defence += 20;
		_level++;
		system("PAUSE");
	}
}

int Player::takeDamage(int attack)
{
	int originalDef = _defence;
	int temp = attack;
	attack -= _defence;
	if (attack <= 0)
	{
		_defence -= temp;
		return 0;
	}
	_health -= attack;
	if (_health > 0)
	{
		return 0;
	}
	else
		return 1;
}


Player::~Player()
{
}
