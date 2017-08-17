#include <iostream>
#include <string>

// To make it like unreal engine code
using FString  = std::string;
using int32 = int;

// Declare the functions
void IntroduceGame();
FString GetGuess();
void PlayGame();

int main() 
{ 
	IntroduceGame();
	PlayGame();
	return 0;
}

void IntroduceGame() 
{
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to bulls and cows a fun word game.\n";
	std::cout << "Can you guess the "<< WORD_LENGTH<<" letter isogram I'm thinking of\n\n";

	return;
}

void PlayGame() 
{
	// Loop through for the number of turns asking for guesses
	constexpr int32 NUMBER_OF_TURNS = 8;
	for (int32 i = 1; i <= NUMBER_OF_TURNS; i++)
	{
		FString Guess = GetGuess();
		// Print the guess back to the player
		std::cout << "Your guess was " << Guess;
		std::cout << "\n\n";
	}
}

FString GetGuess()
{
	// Get a guess from the player
	FString Guess = "";
	std::cout << "Enter your guess:";
	std::getline(std::cin, Guess);
	return Guess;
}