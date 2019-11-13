/*
File: Source.cpp
Name: David Niederweis
Date: 10/27/2019
Course: CS121-03 - Computer Science I
Description: Random number guessing game. Program generates random number seeded with current time, and user has 20 chances to guess number correctly.
*/

// iostream includes for main functionaility, cstdlib includes the random number function, and ctime includes access to time module
#include <iostream> 
#include <cstdlib>
#include <ctime>

// set namespace
using namespace std;

// function declarations
int checkGuess(int, int);
int genRandom();

// main method
int main()
{
	// get random number
	int randInt = genRandom();
	// inform user of start of game
	cout << "A random number has been generated." << endl;
	cout << "==================================" << endl;
	// set chance variable to keep track of number of guesses made
	int chances = 20;
	// while guesses are greater than zero, postfix so the value is only decremented if the number is still greater than zero
	while (chances-- > 0)
	{
		// create variable to store user guess, resets every iteration
		int guess;
		// prompt the user to enter guess
		cout << "Please enter your integer guess: ";
		// store user guess in guess variable
		cin >> guess;
		// if difference between random number and user guess is 0, user wins
		if (checkGuess(randInt, guess) == 0)
		{
			cout << endl << "###########################################" << endl;
			cout << "#                                         #" << endl;
			cout << "#  Congratulations! You guessed correct!  #" << endl;
			cout << "#                                         #" << endl;
			cout << "###########################################" << endl;
			break;
		}
		// else user guess was incorrect, inform user by how much guess was off and how many guesses remain
		else
		{
			cout << "Sorry, that was incorrect. You were off by: " << checkGuess(randInt, guess)  << ". You have " << chances << " chances remaining." << endl;
		}

	}
	// ensure window doesnt close after program completion
	system("pause");
	return 0;
}

// function returns absolute value of difference between random number and user guess
int checkGuess(int randNum, int guess) {
	int diff = abs(randNum - guess);
	return diff;
}

// function seeds random function with current time and returns a random number between 0 and 100
int genRandom() {
	srand(time(0));
	int randInt = (rand() % 100) + 1;
	return randInt;
}