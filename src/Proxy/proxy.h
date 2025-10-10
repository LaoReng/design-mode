#include <iostream>

/// @brief 操作接口类
class OptionInterface
{
public:
    // 送鲜花
    virtual void GiveFlowers() = 0;
    // 送玩偶
    virtual void GiveDoll() = 0;
    // 送零食
    virtual void GiveSnacks() = 0;
};
/// @brief 追求者类（真正执行者）
class Pursuer : public OptionInterface
{
private:
    std::string m_mmName{};

public:
    Pursuer(const std::string &mmName)
        : m_mmName(mmName)
    {
    }
    void GiveFlowers() override
    {
        std::cout << m_mmName << "送你鲜花\n";
    }
    void GiveDoll() override
    {
        std::cout << m_mmName << "送你玩偶\n";
    }
    void GiveSnacks() override
    {
        std::cout << m_mmName << "送你零食\n";
    }
};
/// @brief 代理类
class OptionProxy : public OptionInterface
{
private:
    Pursuer *m_pPursuer{}; // 代理类需要保存实际要执行的类
public:
    OptionProxy(const std::string &mmName)
    {
        m_pPursuer = new Pursuer(mmName);
    }
    virtual ~OptionProxy()
    {
        if (m_pPursuer)
        {
            delete m_pPursuer;
            m_pPursuer = nullptr;
        }
    }
    void GiveFlowers() override
    {
        m_pPursuer->GiveFlowers();
    }
    void GiveDoll() override
    {
        m_pPursuer->GiveDoll();
    }
    void GiveSnacks() override
    {
        m_pPursuer->GiveSnacks();
    }
};