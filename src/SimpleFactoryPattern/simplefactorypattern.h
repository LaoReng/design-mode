#include <iostream>

class Operation;

/// @brief 运算工厂
class OperationFactory
{
private:
    /* data */
public:
    OperationFactory(/* args */);
    ~OperationFactory();
    Operation *CreateOperation(std::string strOperation);
};

class Operation
{
protected:
    /* data */
    double numberA{};
    double numberB{};

public:
    Operation(/* args */) {}
    ~Operation() {}
    virtual double GetResult() = 0;
};
/// @brief 加法运算
class OperationAdd : public Operation
{
public:
    double GetResult() override
    {
        return numberA + numberB;
    }

private:
};
/// @brief 减法运算
class OperationSub : public Operation
{
public:
    double GetResult() override
    {
        return numberA - numberB;
    }
};
/// @brief 乘法运算
class OperationMult : public Operation
{
public:
    double GetResult() override
    {
        return numberA * numberB;
    }
};
/// @brief 除法运算
class OperationDiv : public Operation
{
public:
    double GetResult() override
    {
        if (numberB == 0)
            return 0;
        return numberA / numberB;
    }
};
