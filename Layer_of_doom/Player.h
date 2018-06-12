#pragma once
class Player
{
	int _level;
	int _health;
	int _attack;
	int _defence;
	int _experience;
	int _x;
	int _y;
public:
	Player();
	void init(int level, int health, int attack, int defence, int experience);
	void setPosition(int x, int y);
	void getPosition(int &x, int &y);
	int getPlayerAttack();
	void addExp(int exp);
	void takeDamage(int attack);
	~Player();
};

