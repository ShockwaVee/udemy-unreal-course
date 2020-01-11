// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    Isograms = GetValidWords(HiddenWords);

    SetupGame();
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num() - 1)];
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Welcome to the Bull Cow game!"));
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives, so be careful."), Lives);
    PrintLine(TEXT("Type your guess and\npress [ENTER] to continue"));
    PrintLine(TEXT("The hidden word is %s"), *HiddenWord);
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press [ENTER] to play again..."));
}

void UBullCowCartridge::ProcessGuess(const FString &Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("That's the hidden word, you won!"));
        EndGame();
        return;
    }

    Lives--;

    if (Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left."));
        PrintLine(TEXT("The hidden word was %s."), *HiddenWord);
        EndGame();
        return;
    }

    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The word has %i letters!"), HiddenWord.Len());
        PrintLine(TEXT("Wrong guess, try again."), Lives);
        PrintLine(TEXT("You have %i lives left!"), Lives);
        return;
    }

    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating letters!"), Lives);
    }

    PrintLine(TEXT("Wrong guess, try again."), Lives);
    PrintLine(TEXT("You have %i lives left!"), Lives);

    FBullCowCount Count = GetBullCows(Guess);

    PrintLine(TEXT("You have %i bulls and %i cows"), Count.Bulls, Count.Cows);
}

bool UBullCowCartridge::IsIsogram(const FString &Word) const
{
    for (int32 i = 0; i < Word.Len(); i++)
    {
        for (int32 j = i + 1; j < Word.Len(); j++)
        {
            if (Word[i] == Word[j])
            {
                return false;
            }
        }
    }
    return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString> &Words) const
{
    TArray<FString> ValidWords;

    for (FString Word : Words)
    {
        if (Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word))
        {
            ValidWords.Emplace(Word);
        }
    }

    return ValidWords;
}

FBullCowCount UBullCowCartridge::GetBullCows(const FString PlayerGuess) const
{
    FBullCowCount Count;
    for (int32 GuessIndex = 0; GuessIndex < PlayerGuess.Len(); GuessIndex++)
    {
        if (PlayerGuess[GuessIndex] == HiddenWord[GuessIndex])
        {
            Count.Bulls++;
            continue;
        }

        for (int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++)
        {
            if (PlayerGuess[GuessIndex] == HiddenWord[HiddenIndex])
            {
                Count.Cows++;
                break;
            }
        }
    }
    return Count;
}