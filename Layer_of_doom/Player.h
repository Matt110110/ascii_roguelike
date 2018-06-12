#pragma once
class Player
{
	int _level, _health, _attack, _defence, _experience, _x, _y;
	void _generageDef(int def);
public:
	Player();
	void init(int level, int health, int attack, int defence, int experience);
	void setPosition(int x, int y);
	void getPosition(int &x, int &y);
	int getPlayerAttack();
	void addExp(int exp);
	int takeDamage(int attack);

	~Player();
};

