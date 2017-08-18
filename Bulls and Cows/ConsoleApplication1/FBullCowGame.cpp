#include "FBullCowGame.h"

using int32 = int;
using FString = std::string;

FBullCowGame::FBullCowGame(){Reset();}
int32 FBullCowGame::GetMaxTries()const {return MaxTries;}
int32 FBullCowGame::GetCurrentTry()const {return CurrentTry;}

void FBullCowGame::Reset()
{
	CurrentTry = 1;

	constexpr int32 MAX_TRIES = 10;
	MaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;

	return;
}

bool FBullCowGame::CheckGuessValidity(FString Guess)
{
	return false;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

// Receives a VALID guess, and increases the turn number
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// Increase the turn number
	CurrentTry++;
	// Setup a return value
	FBullCowCount BullCowCount;
	// Loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 HWChar = 0; HWChar < HiddenWordLength; HWChar++) 
	{
		// Compare letters against the hidden word
		for (int32 GuessCHAR = 0; GuessCHAR < HiddenWordLength; GuessCHAR++) 
		{
			// If they match then
			if (Guess[GuessCHAR] == MyHiddenWord[HWChar])
			{
				if (HWChar == GuessCHAR) 
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
		
	return BullCowCount;
}
