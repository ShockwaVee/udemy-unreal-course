#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Print welcome messages
    std::cout << "\nYou are a thief trying to get the gold from a level " << Difficulty << " vault!\n";
    std::cout << "You need to enter the correct codes to get access...\n\n";
    std::cout << " .----------------.\n"
                 "|          _       |\n"
                 "|      _.-'|'-._   |\n"
                 "| .__.|    |    |  |\n"
                 "|     |_.-'|'-._|  |\n"
                 "| '--'|    |    |  |\n"
                 "| '--'|_.-'`'-._|  |\n"
                 "| '--'          `  |\n"
                 " '----------------'\n";
}

bool PlayGame(int Difficulty)
{
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    PrintIntroduction(Difficulty);

    std::cout << "There are three numbers in the code.\n";
    std::cout << "The code adds up to: " << CodeSum;
    std::cout << "\nAnd multiplying each code gives us: " << CodeProduct << std::endl;
    std::cout << "\nEnter the three numbers of the code, separated by space\n ";

    int GuessA, GuessB, GuessC;

    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou've cracked the code!\n";
        return true;
    }
    else
    {
        std::cout << "\nYou activated the alarm! Try again!\n";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            LevelDifficulty++;
            if (LevelDifficulty <= MaxLevel) {
                std::cout << "\nGet ready for the next level!\n";
            } else {
                std::cout << "\nCongratulations! You stole everything!\n";
            }
        }
    }
    return 0;
}