#include <iostream>

int main()
{
    // Print welcome messages
    std::cout << "You are a thief trying to get the gold from a vault!" << std::endl;
    std::cout << "You need to enter the correct codes to get access..." << std::endl;

    const int CodeA = 0;
    const int CodeB = 1;
    const int CodeC = 2;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    std::cout << std::endl;
    std::cout << "There are three numbers in the code." << std::endl;
    std::cout << "The code adds up to: " << CodeSum  << std::endl;
    std::cout << "And multiplying each code gives us: " << CodeProduct << std::endl;

    int PlayerGuess;
    
    return 0;
}