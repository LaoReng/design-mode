#include <iostream>
class CashBase;

/// @brief 现金上下文
class CashContext
{
private:
    CashBase *cb{};

public:
    CashContext(const std::string &op)
    {
        if (op == "正常结算")
        {
            cb = new CashNormal();
        }
        else if (op == "打八折")
        {
            cb = new CashDiscount(0.8);
        }
        else if (op == "满300返30")
        {
            cb = new CashReturn(300, 30);
        }
    }
    double GetResult(double cash)
    {
        return cb->GetResult(cash);
    }
};
/// @brief 现金基类
class CashBase
{
public:
    virtual double GetResult(double cash) = 0;
};
/// @brief 正常结算
class CashNormal : public CashBase
{
public:
    CashNormal() {}
    double GetResult(double cash) override
    {
        return cash;
    }
};
/// @brief 折扣结算
class CashDiscount : public CashBase
{
private:
    double m_discount{};

public:
    CashDiscount(double discount)
        : m_discount(discount)
    {
    }
    double GetResult(double cash) override
    {
        return cash * m_discount;
    }
};
/// @brief 返现结算
class CashReturn : public CashBase
{
private:
    double m_thresholdNum{}; // 返现阈值
    double m_returnNum{};    // 返现金额

public:
    CashReturn(double thresholdNum, double returnNum)
        : m_thresholdNum(thresholdNum), m_returnNum(returnNum)
    {
    }
    double GetResult(double cash) override
    {
        return cash - (cash / m_thresholdNum) * m_returnNum;
    }
};