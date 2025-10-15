#include <iostream>

/// @brief 翻译基类（建造者类）
class Builder
{
public:
    virtual void Translate1() = 0;
    virtual void Translate2() = 0;
};
/// @brief 具体翻译类A
class TranslateBuilderA : public Builder
{
public:
    virtual void Translate1() override
    {
        std::cout << __FUNCTION__ << "我是翻译类A\n";
    }
    virtual void Translate2() override
    {
        std::cout << __FUNCTION__ << "我是翻译类A\n";
    }
};
/// @brief 具体翻译类B
class TranslateBuilderB : public Builder
{
public:
    virtual void Translate1() override
    {
        std::cout << __FUNCTION__ << "I'm A translator\n";
    }
    virtual void Translate2() override
    {
        std::cout << __FUNCTION__ << "I'm A translator\n";
    }
};
/// @brief 指挥类
class Director
{
private:
    Builder *m_pBuilder{};

public:
    Director(Builder *pBuilder)
        : m_pBuilder(pBuilder)
    {
    }
    void Create()
    {
        m_pBuilder->Translate1();
        m_pBuilder->Translate2();
    }
};