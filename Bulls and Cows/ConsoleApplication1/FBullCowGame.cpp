#include "FBullCowGame.h"

using int32 = int;
using FString = std::string;

int32 FBullCowGame::GetMaxTries()const {return MaxTries;}
int32 FBullCowGame::GetCurrentTry() const {return CurrentTry;}

void FBullCowGame::Reset()
{

}

bool FBullCowGame::CheckGuessValidity(FString Guess)
{
	return false;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}
