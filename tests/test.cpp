#include <gtest/gtest.h>

#include "executor.h"

// 测试初始化位置和方向
TEST(ExecutorTest, InitialPositionAndHeading)
{
    Executor executor;
    int x, y;
    char heading;
    executor.getPosition(x, y, heading);

    ASSERT_EQ(x, 0);
    ASSERT_EQ(y, 0);
    ASSERT_EQ(heading, 'N');
}

// 测试自定义初始位置和方向
TEST(ExecutorTest, CustomInitialPositionAndHeading)
{
    Executor executor(5, 10, 'E');
    int x, y;
    char heading;
    executor.getPosition(x, y, heading);

    ASSERT_EQ(x, 5);
    ASSERT_EQ(y, 10);
    ASSERT_EQ(heading, 'E');
}

// 测试单步向前移动
TEST(ExecutorTest, MoveForwardNorth)
{
    Executor executor;
    executor.executeCommands("M");

    int x, y;
    char heading;
    executor.getPosition(x, y, heading);

    ASSERT_EQ(x, 0);
    ASSERT_EQ(y, 1);
    ASSERT_EQ(heading, 'N');
}

// 测试左转
TEST(ExecutorTest, TurnLeft)
{
    Executor executor;
    executor.executeCommands("L");

    int x, y;
    char heading;
    executor.getPosition(x, y, heading);

    ASSERT_EQ(x, 0);
    ASSERT_EQ(y, 0);
    ASSERT_EQ(heading, 'W');
}

// 测试右转
TEST(ExecutorTest, TurnRight)
{
    Executor executor;
    executor.executeCommands("R");

    int x, y;
    char heading;
    executor.getPosition(x, y, heading);

    ASSERT_EQ(x, 0);
    ASSERT_EQ(y, 0);
    ASSERT_EQ(heading, 'E');
}

// 测试一系列复杂指令
TEST(ExecutorTest, ComplexCommands)
{
    Executor executor;
    executor.executeCommands("MMRMMRMLM");

    int x, y;
    char heading;
    executor.getPosition(x, y, heading);

    ASSERT_EQ(x, 3);
    ASSERT_EQ(y, 1);
    ASSERT_EQ(heading, 'E');
}

// 测试多个左转
TEST(ExecutorTest, MultipleTurnsLeft)
{
    Executor executor;
    executor.executeCommands("LLL");

    int x, y;
    char heading;
    executor.getPosition(x, y, heading);

    ASSERT_EQ(x, 0);
    ASSERT_EQ(y, 0);
    ASSERT_EQ(heading, 'E');
}

// 测试多个右转
TEST(ExecutorTest, MultipleTurnsRight)
{
    Executor executor;
    executor.executeCommands("RRRR");

    int x, y;
    char heading;
    executor.getPosition(x, y, heading);

    ASSERT_EQ(x, 0);
    ASSERT_EQ(y, 0);
    ASSERT_EQ(heading, 'N');
}

// 测试加速模式下的前进
TEST(ExecutorTest, AcceleratedMoveForward)
{
    Executor executor;
    executor.executeCommands("FM");

    int x, y;
    char heading;
    executor.getPosition(x, y, heading);

    ASSERT_EQ(x, 0);
    ASSERT_EQ(y, 2);
    ASSERT_EQ(heading, 'N');
}

// 测试加速模式下左转
TEST(ExecutorTest, AcceleratedTurnLeft)
{
    Executor executor;
    executor.executeCommands("FL");

    int x, y;
    char heading;
    executor.getPosition(x, y, heading);

    ASSERT_EQ(x, 0);
    ASSERT_EQ(y, 1);
    ASSERT_EQ(heading, 'W');
}

// 测试加速模式下右转
TEST(ExecutorTest, AcceleratedTurnRight)
{
    Executor executor;
    executor.executeCommands("FR");

    int x, y;
    char heading;
    executor.getPosition(x, y, heading);

    ASSERT_EQ(x, 0);
    ASSERT_EQ(y, 1);
    ASSERT_EQ(heading, 'E');
}

// 测试加速模式切换
TEST(ExecutorTest, ToggleAcceleration)
{
    Executor executor;
    executor.executeCommands("FF");

    int x, y;
    char heading;
    executor.getPosition(x, y, heading);

    ASSERT_EQ(x, 0);
    ASSERT_EQ(y, 0);
    ASSERT_EQ(heading, 'N');  // 加速模式关闭后，位置未变，方向为初始方向
}

// 测试普通模式和加速模式混合
TEST(ExecutorTest, MixedModeCommands)
{
    Executor executor;
    executor.executeCommands("FMMLFMR");

    int x, y;
    char heading;
    executor.getPosition(x, y, heading);

    ASSERT_EQ(x, -1);
    ASSERT_EQ(y, 5);
    ASSERT_EQ(heading, 'N');
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
