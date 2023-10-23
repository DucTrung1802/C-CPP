/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <thread>

void function1(char symbol) {
    for (int i = 0; i < 200; i++)
    {
        std::cout << symbol;
    }
}

void function2() {
    for (int i = 0; i < 200; i++)
    {
        std::cout << "-";
    }
}

int main()
{
    std::thread worker1(function1, '#');
    std::thread worker2(function2);

    system("pause>nul");

    return 0;
}
