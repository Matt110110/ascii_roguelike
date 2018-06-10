#pragma once
#include <string>
#include <vector>

using namespace std;

class Level
{
	vector<string> _levelData;
public:
	Level();
	void loadLevel(string fileName);
	~Level();
};

