#include "Level.h"
#include <iostream>
#include <fstream>


Level::Level()
{

}

void Level::loadLevel(string fileName)
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
}

void Level::printLevel()
{
	for (int i = 0; i < _levelData.size(); i++)
	{
		printf("%s\n", _levelData[i].c_str());
	}
	cout << endl;
}


Level::~Level()
{
}
