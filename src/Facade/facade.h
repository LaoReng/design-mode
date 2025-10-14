#include <iostream>

/// @brief 子系统一
class SubSystemOne
{
public:
    void MethodOne()
    {
        std::cout << "方法一\n";
    }
};
/// @brief 子系统二
class SubSystemTwo
{
public:
    void MethodTwo()
    {
        std::cout << "方法二\n";
    }
};
/// @brief 子系统三
class SubSystemThree
{
public:
    void MethodThree()
    {
        std::cout << "方法三\n";
    }
};
/// @brief 外观类
class CFacade
{
private:
    SubSystemOne one;
    SubSystemTwo two;
    SubSystemThree three;

public:
    void MethodA()
    {
        one.MethodOne();
        three.MethodThree();
    }
    void MethodB()
    {
        one.MethodOne();
        two.MethodTwo();
        three.MethodThree();
    }
};