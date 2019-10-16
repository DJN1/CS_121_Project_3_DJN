#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0)); // seed random with current time

	int ranInt = rand() % 100 + 1;
	cout << rand() % 100 << endl;

	return 0;
}

int getRandInt()
{
	int randInt = rand() % 100 + 1;
	return randInt;
}