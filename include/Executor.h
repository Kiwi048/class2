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
    Executor(int x = 0, int y = 0, char heading = 'N') : position_(x, y), heading_(heading)
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
        std::cout << "Current Position: (" << x << ", " << y << ") Heading: " << heading << std::endl;
    }

private:
    Position position_;
    Heading heading_;

    // 执行单个控制指令
    void executeCommand(char command)
    {
        switch (command) {
        case 'M':
            moveForward();
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

    // 前进一格
    void moveForward()
    {
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
};
