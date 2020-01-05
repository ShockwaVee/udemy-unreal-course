#include <iostream>

int main()
{
    std::cout << "You are a thief trying to get the gold from a vault!";
    std::cout << std::endl;
    std::cout << "You need to enter the correct codes to get access...";

    const int a = 0;
    const int b = 1;
    const int c = 2;

    const int sum = a + b + c;
    const int product = a * b * c;
    
    std::cout << std::endl;
    std::cout << sum  << std::endl;
    std::cout << product << std::endl;
    
    return 0;
}