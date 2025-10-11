/// @brief 运算基类
class OperationBase
{
public:
    double m_optNum1{};
    double m_optNum2{};

public:
    virtual double GetResult() = 0;
};
/// @brief 加法运算
class AddOperation : public OperationBase
{
public:
    virtual double GetResult() override
    {
        return m_optNum1 + m_optNum2;
    }
};
/// @brief 减法运算
class SubOperation : public OperationBase
{
public:
    virtual double GetResult() override
    {
        return m_optNum1 - m_optNum2;
    }
};
/// @brief 乘法运算
class MultOperation : public OperationBase
{
public:
    virtual double GetResult() override
    {
        return m_optNum1 * m_optNum2;
    }
};
/// @brief 除法运算
class DivOperation : public OperationBase
{
public:
    virtual double GetResult() override
    {
        if (m_optNum2 == 0)
            return 0;
        return m_optNum1 / m_optNum2;
    }
};
/// @brief 创建运算工厂方法基类
class OperationFactoryMethod
{
public:
    virtual OperationBase *CreateOperation() = 0;
};
/// @brief 加法工厂方法
class FactoryMethodAdd : public OperationFactoryMethod
{
public:
    virtual OperationBase *CreateOperation() override
    {
        return new AddOperation;
    }
};
/// @brief 减法工厂方法
class FactoryMethodSub : public OperationFactoryMethod
{
public:
    virtual OperationBase *CreateOperation() override
    {
        return new SubOperation;
    }
};
/// @brief 乘法工厂方法
class FactoryMethodMult : public OperationFactoryMethod
{
public:
    virtual OperationBase *CreateOperation() override
    {
        return new MultOperation;
    }
};
/// @brief 除法工厂方法
class FactoryMethodDiv : public OperationFactoryMethod
{
public:
    virtual OperationBase *CreateOperation() override
    {
        return new DivOperation;
    }
};