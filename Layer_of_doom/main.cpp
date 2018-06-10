#include <iostream>
#include <string>
#include "GameSystem.h"

using namespace std;

int main()
{
	GameSystem gameSystem("level1.txt");
	gameSystem.logic();
	// End of main
	system("PAUSE");
	return 0;
}