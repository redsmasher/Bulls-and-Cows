#include <iostream>
#include <string>
#include "FBullCowGame.h"

// To make it like unreal engine code
using FString  = std::string;
using int32 = int;

// Declare the functions
void IntroduceGame();
FString GetGuess();
void PlayGame();
bool bAskToPlayAgain();

FBullCowGame BCGame; // Instantiate a new class

// The entry point for the application
int main() 
{ 
	bool bPlayAgain = false;
	do
	{
		IntroduceGame();
		PlayGame();
		bPlayAgain = bAskToPlayAgain();
	} 
	while (bPlayAgain);
	return 0; // Exit the application
}

void IntroduceGame() 
{
	std::cout << "Welcome to bulls and cows a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of\n\n";

	return;
}

void PlayGame() 
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	// Loop through for the number of turns asking for guesses
	// TODO Change from for to while loop once we are validating tries
	for (int32 i = 1; i <= MaxTries; i++)
	{
		FString Guess = GetGuess(); // TODO Make loop checking valid

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// Print number of bulls and cows
		std::cout << "Bulls " << BullCowCount.Bulls << " Cows " << BullCowCount.Cows<<"\n";
		std::cout << "\n";
	}

	// TODO Summarise game
}

FString GetGuess()
{
	// Get a guess from the player
	int32 CurrentTry = BCGame.GetCurrentTry();
	FString Guess = "";
	std::cout << "Try "<< CurrentTry <<" Enter your guess:";
	std::getline(std::cin, Guess);
	return Guess;
}

// Ask the player if he wants to play again
bool bAskToPlayAgain() 
{
	std::cout << "Do you want to play again?(y/n)";
	FString Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}