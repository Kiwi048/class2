#include <iostream>
#include <string>

#include "executor.h"

int main()
{
    Executor executor;
    std::string commands;

    std::cout << "输入指令, M: 前进, L: 左转, R: 右转, F: 切换加速状态, Q: 退出: " << std::endl;

    while (true) {
        std::cout << "> ";
        std::cin >> commands;
        if (commands == "Q" || commands == "q") {
            std::cout << "程序结束。" << std::endl;
            break;
        }
        executor.executeCommands(commands);
        executor.printPosition();
    }

    return 0;
}
