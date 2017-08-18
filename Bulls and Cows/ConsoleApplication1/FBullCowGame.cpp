#include "FBullCowGame.h"

using int32 = int;
using FString = std::string;

FBullCowGame::FBullCowGame(){Reset();}
int32 FBullCowGame::GetMaxTries()const {return MaxTries;}
int32 FBullCowGame::GetCurrentTry()const {return CurrentTry;}
int32 FBullCowGame::GetHiddenWordLength() const{return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() { return bIsGameWon; }

void FBullCowGame::Reset()
{
	CurrentTry = 1;

	constexpr int32 MAX_TRIES = 10;
	MaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess)
{
	if (false) // If the guess isn't an isogram, return an error
	{
		return EGuessStatus::Not_Isogram;
	}
	else if(false) // If the guess isn't all lowercase, return an error
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) // If the guess length is wrong. return an error
	{
		return EGuessStatus::Wrong_Length;
	}
	else 	// Otherwise, return OK
	{
		return EGuessStatus::OK;
	}
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
					bIsGameWon = true;
					BullCowCount.Bulls++;
				}
				else
				{
					bIsGameWon = false;
					BullCowCount.Cows++;
				}
			}
		}
	}
		
	return BullCowCount;
}
