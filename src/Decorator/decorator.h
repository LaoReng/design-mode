#include <iostream>

/// @brief 人类 ConcreteComponent具体部分
class Person
{
private:
    std::string m_strName;

public:
    Person() {}
    Person(const std::string& name)
        : m_strName(name)
    {
    }
    virtual void Show()
    {
        std::cout << "装饰的" << m_strName << std::endl;
    }
};
/// @brief 装饰类 Decorator修饰抽象类
class Costume : public Person
{
protected:
    Person* m_component{};

public:
    // 打扮装饰
    void Decorator(Person* component)
    {
        m_component = component;
    }
    virtual void Show() override
    {
        if (m_component)
        {
            m_component->Show();
        }
    }
};
/// @brief 皮鞋 ConcreteDecorator具体修饰类
class LeatherShoes : public Costume
{
public:
    virtual void Show() override
    {
        std::cout << "皮鞋 ";
        Costume::Show();
    }
};
/// @brief 西裤
class SuitPants : public Costume
{
public:
    virtual void Show() override
    {
        std::cout << "西裤 ";
        Costume::Show();
    }
};
/// @brief 西装外套
class SuitJacket : public Costume
{
public:
    virtual void Show() override
    {
        std::cout << "西装外套 ";
        Costume::Show();
    }
};
/// @brief 短袖
class ShortSleeve : public Costume
{
public:
    virtual void Show() override
    {
        std::cout << "短袖 ";
        Costume::Show();
    }
};
/// @brief 喇叭裤
class BellBottoms : public Costume
{
public:
    virtual void Show() override

    {
        std::cout << "喇叭裤 ";
        Costume::Show();
    }
};
/// @brief 运动鞋
class Sneakers : public Costume
{
public:
    virtual void Show() override
    {
        std::cout << "运动鞋 ";
        Costume::Show();
    }
};
