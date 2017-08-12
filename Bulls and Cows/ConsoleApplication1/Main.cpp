#include <iostream>
#include <string>

// Declare the functions
void IntroduceGame();
void GetGuessAndPrintItBack();

// To make it like unreal engine code
using FString  = std::string;
using int32 = int;

int main() 
{ 
	IntroduceGame();
	GetGuessAndPrintItBack();
	return 0;
}

void IntroduceGame() 
{
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to bulls and cows a fun word game.\n";
	std::cout << "Can you guess the "<< WORD_LENGTH<<" letter isogram I'm thinking of\n\n";
}

void GetGuessAndPrintItBack() // Has a side-effect
{
	// Get a guess from the player
	FString Guess = "";
	std::cout << "Enter your guess:";
	std::getline(std::cin, Guess);

	// Print the guess back to the player
	std::cout << "Your guess was " << Guess;
	std::cout << "\n\n";
}