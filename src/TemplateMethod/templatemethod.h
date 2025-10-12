#include <iostream>
/// @brief 试卷类
class ExaminationPaper
{
public:
    /// @brief 试题1
    void Question1()
    {
        std::cout << "作用域区分符（::）的功能是[ ] ａ、标识作用域的级别 b、标识成员属于哪个类 ｃ、限定成员的作用范围 d、指出作用域的范围\n";
        std::cout << "做答答案：" << Answer1() << std::endl;
    }
    /// @brief 试题2
    void Question2()
    {
        std::cout << "有关类的说法不正确的是[ ] ａ、类是一种用户自定义的数据类型 ｂ、只有类中的成员函数才能存取类中的私有数据 ｃ、在类中，如果不作特别说明，所有的数据均为私有类型 ｄ、在类中，如果不作特别说明，所有的数据均为公有类型\n";
        std::cout << "做答答案：" << Answer2() << std::endl;
    }

protected:
    /// @brief 试题1答案
    /// @return 返回做答答案
    virtual std::string Answer1() { return ""; }
    /// @brief 试题2答案
    /// @return 做答答案
    virtual std::string Answer2() { return ""; }
};
/// @brief 学生A抄的试卷
class ExaminationPaperA : public ExaminationPaper
{
protected:
    virtual std::string Answer1() override { return "a"; }
    virtual std::string Answer2() override { return "b"; }
};
/// @brief 学生B抄的试卷
class ExaminationPaperB : public ExaminationPaper
{
protected:
    virtual std::string Answer1() override { return "c"; }
    virtual std::string Answer2() override { return "d"; }
};