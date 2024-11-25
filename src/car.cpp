#include <iostream>
#include <string>

#include "executor.h"

int main()
{
    Executor executor;
    std::string commands;

    std::cout << "输入指令, M前进, L左转, R右转, Q退出: " << std::endl;
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
