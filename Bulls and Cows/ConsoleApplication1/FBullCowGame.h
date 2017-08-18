#pragma once
#include <string>

// To make it look like unreal engine code
using int32 = int;
using FString = std::string;

class FBullCowGame
{
public:
	FBullCowGame(); // Constructor

	void Reset();
	bool CheckGuessValidity(FString Guess);
	int32 GetMaxTries()const;
	int32 GetCurrentTry()const;
	bool IsGameWon()const;

private:
	// See constructor for initialiasation
	int32 MaxTries;
	int32 CurrentTry;
};