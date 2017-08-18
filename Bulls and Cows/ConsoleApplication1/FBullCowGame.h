#pragma once
#include <string>

// To make it look like unreal engine code
using int32 = int;
using FString = std::string;

// All values initialiased to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame(); // Constructor

	void Reset();
	bool CheckGuessValidity(FString Guess);
	int32 GetMaxTries()const;
	int32 GetCurrentTry()const;
	int32 GetHiddenWordLength()const;
	bool IsGameWon()const;
	
	// Counts bulls and cows, and increases turn number
	FBullCowCount SubmitGuess(FString Guess);

private:
	// See constructor for initialiasation
	int32 MaxTries;
	int32 CurrentTry;
	FString MyHiddenWord;
};