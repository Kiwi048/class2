#include <iostream>
#include <string>

class Position
{
public:
    Position(int x = 0, int y = 0) : x_(x), y_(y)
    {
    }

    void moveNorth()
    {
        ++y_;
    }
    void moveSouth()
    {
        --y_;
    }
    void moveEast()
    {
        ++x_;
    }
    void moveWest()
    {
        --x_;
    }

    int getX() const
    {
        return x_;
    }
    int getY() const
    {
        return y_;
    }

private:
    int x_, y_;
};

class Heading
{
public:
    Heading(char direction = 'N') : direction_(direction)
    {
    }

    void turnLeft()
    {
        switch (direction_) {
        case 'N':
            direction_ = 'W';
            break;
        case 'W':
            direction_ = 'S';
            break;
        case 'S':
            direction_ = 'E';
            break;
        case 'E':
            direction_ = 'N';
            break;
        }
    }

    void turnRight()
    {
        switch (direction_) {
        case 'N':
            direction_ = 'E';
            break;
        case 'E':
            direction_ = 'S';
            break;
        case 'S':
            direction_ = 'W';
            break;
        case 'W':
            direction_ = 'N';
            break;
        }
    }

    char getDirection() const
    {
        return direction_;
    }

private:
    char direction_;
};

class Executor
{
public:
    // 初始化接口，设置初始位置和朝向
    Executor(int x = 0, int y = 0, char heading = 'N') : position_(x, y), heading_(heading), isAccelerated_(false)
    {
    }

    // 批量执行控制指令
    void executeCommands(const std::string& commands)
    {
        for (char command : commands) {
            executeCommand(toupper(command));
        }
    }

    // 查询当前坐标位置和朝向
    void getPosition(int& x, int& y, char& heading) const
    {
        x = position_.getX();
        y = position_.getY();
        heading = heading_.getDirection();
    }

    // 打印当前坐标位置和朝向
    void printPosition() const
    {
        int x, y;
        char heading;
        getPosition(x, y, heading);
        std::cout << "Current Position: (" << x << ", " << y << ") Heading: " << heading
                  << (isAccelerated_ ? " [Accelerated]" : "") << std::endl;
    }

private:
    Position position_;
    Heading heading_;
    bool isAccelerated_;  // 加速状态标志

    // 执行单个控制指令
    void executeCommand(char command)
    {
        if (command == 'F') {
            toggleAcceleration();
        } else {
            if (isAccelerated_) {
                executeAcceleratedCommand(command);
            } else {
                executeNormalCommand(command);
            }
        }
    }

    // 切换加速状态
    void toggleAcceleration()
    {
        isAccelerated_ = !isAccelerated_;
    }

    // 执行普通状态下的指令
    void executeNormalCommand(char command)
    {
        switch (command) {
        case 'M':
            moveForward(1);
            break;
        case 'L':
            heading_.turnLeft();
            break;
        case 'R':
            heading_.turnRight();
            break;
        default:
            break;
        }
    }

    // 执行加速状态下的指令
    void executeAcceleratedCommand(char command)
    {
        switch (command) {
        case 'M':
            moveForward(2);
            break;
        case 'L':
            moveForward(1);
            heading_.turnLeft();
            break;
        case 'R':
            moveForward(1);
            heading_.turnRight();
            break;
        default:
            break;
        }
    }

    // 前进若干格
    void moveForward(int steps)
    {
        for (int i = 0; i < steps; ++i) {
            switch (heading_.getDirection()) {
            case 'N':
                position_.moveNorth();
                break;
            case 'S':
                position_.moveSouth();
                break;
            case 'E':
                position_.moveEast();
                break;
            case 'W':
                position_.moveWest();
                break;
            }
        }
    }
};
