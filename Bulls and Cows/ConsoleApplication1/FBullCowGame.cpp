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
