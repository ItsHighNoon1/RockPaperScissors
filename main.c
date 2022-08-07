#include <stdio.h> // getc
#include <stdlib.h> // rand and srand
#include <time.h> // clock

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int main(int argv, char** argc) {
	// Seed the random number generator
	srand(clock());

	// Get the user's choice
	int option = 0;
	do {
		// Prompt the user
		printf("Pick [r]ock, [p]aper, or [s]cissors: ");

		// Get the user's input
		int charIn = getc(stdin);

		// Figure out which option that is
		switch(charIn) {
			case 'r':
			case 'R':
				option = ROCK;
				break;
			case 'p':
			case 'P':
				option = PAPER;
				break;
			case 's':
			case 'S':
				option = SCISSORS;
				break;
			default:
				// If the user didn't type r, p, or s, tell them it's invalid
				printf("Invalid option\n");
		}

		// Ditch the rest of stdin
		while (charIn != '\n') charIn = getc(stdin);
	} while (!option);

	// Get the computer's choice
	int aiOption = rand() % 3 + 1;
	switch (aiOption) {
		case ROCK:
			printf("Computer chose rock\n");
			break;
		case PAPER:
			printf("Computer chose paper\n");
			break;
		case SCISSORS:
			printf("Computer chose scissors\n");
			break;
	}

	// Results
	if (option == ROCK && aiOption == SCISSORS 
			|| option == PAPER && aiOption == ROCK
			|| option == SCISSORS && aiOption == PAPER) {
		printf("You win!\n");
	} else if (option == aiOption) {
		printf("It's a tie\n");
	} else {
		printf("You lose...\n");
	}

	return EXIT_SUCCESS;
}
