#include <iostream>
#include <string>

#include "executor.h"

int main()
{
    Executor executor;
    std::string commands;

    std::cout << "Enter commands (M to move, L to turn left, R to turn right, Q to quit): " << std::endl;
    while (true) {
        std::cout << "> ";
        std::cin >> commands;
        if (commands == "Q" || commands == "q") {
            break;
        }
        executor.executeCommands(commands);
        executor.printPosition();
    }

    return 0;
}
