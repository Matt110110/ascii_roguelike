#include "Player.h"
#include <stdio.h>
#include <iostream>

using namespace std;

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

void Player::takeDamage(int attack)
{
}


Player::~Player()
{
}
