#include <iostream>
#include <list>
#include "base/binder.h"

/// @brief 订阅者基类
class Subscribe
{
public:
    virtual void Update() = 0;
};

/// @brief 发布者基类
class Publish
{
protected:
    std::list<Subscribe *> m_lstSubscribe;
    std::list<CBinder *> m_lstSubs;

public:
    /// @brief 添加订阅者
    /// @param sub 订阅者
    virtual void Add(Subscribe *sub)
    {
        m_lstSubscribe.push_back(sub);
    }
    /// @brief 添加订阅者
    /// @tparam _OBJ 订阅者类型
    /// @tparam _FUNC 订阅者触发成员函数类型
    /// @param sub 订阅者
    /// @param func 发布者所触发的订阅者对象的函数
    template <typename _OBJ, typename _FUNC>
    void Add(_OBJ *sub, _FUNC func)
    {
        CBinder *pBinder = new CBinder(sub, func);
        //pBinder->MakeBinder(sub, func);
        m_lstSubs.push_back(pBinder);
    }
    /// @brief 移除订阅者
    /// @param sub 订阅者
    virtual void Remove(Subscribe *sub)
    {
        if (sub == nullptr)
        {
            std::cout << "bind调用" << std::endl;
            return;
        }
        auto it = std::find(m_lstSubscribe.begin(), m_lstSubscribe.end(), sub);
        if (it != m_lstSubscribe.end())
        {
            m_lstSubscribe.erase(it);
        }
    }
    /// @brief 移除订阅者
    /// @tparam _OBJ 订阅者类型
    /// @tparam _FUNC 订阅者触发成员函数类型
    /// @param sub 订阅者
    /// @param func 发布者所触发的订阅者对象的函数
    template <typename _OBJ, typename _FUNC>
    void Remove(_OBJ *sub, _FUNC func)
    {
        CBinder bindData(sub, func);
        //bindData.MakeBinder(sub, func);
        for (auto it = m_lstSubs.begin(); it != m_lstSubs.end(); it++)
        {
            if (**it == bindData)
            {
                m_lstSubs.erase(it);
                break;
            }
        }
    }

    virtual void Nodify()
    {
        for (auto it : m_lstSubscribe)
        {
            it->Update();
        }
    }
};
/// @brief 具体发布者类
class Boss : public Publish
{
private:
    std::string m_name{"Boss"};

public:
    std::string GetName() const
    {
        return m_name;
    }
    virtual void Nodify() override
    {
        if (m_lstSubs.empty())
        {
            Publish::Nodify();
            return;
        }
        for (auto it : m_lstSubs)
        {
            (*it)();
        }
    }
};
/// @brief 具体订阅者牛马类型
class Effort : public Subscribe
{
private:
    Boss *m_boss{};

public:
    Effort(Boss *boss)
        : m_boss(boss)
    {
    }
    virtual void Update()
    {
        std::cout << m_boss->GetName() << "来了，继续工作！！！\n";
    }
    int Test1(int a)
    {
        std::cout << a;
        return 0;
    }
};
/// @brief 具体订阅者摆烂类型
class Ease : public Subscribe
{
private:
    Boss *m_boss{};

public:
    Ease(Boss *boss)
        : m_boss(boss)
    {
    }
    virtual void Update()
    {
        std::cout << m_boss->GetName() << "来了，快去请假！！！\n";
    }
};
/// @brief 具体订阅者牛马类型[初步优化(实现支持不同函数名的调用)]
class Effort2
{
private:
    Boss *m_boss{};

public:
    Effort2(Boss *boss)
        : m_boss(boss)
    {
    }
    void Effort2Update()
    {
        std::cout << "[" << __FUNCTION__ << "]:" << m_boss->GetName() << "来了，继续工作！！！\n";
    }
};
/// @brief 具体订阅者摆烂类型[初步优化(实现支持不同函数名的调用)]
class Ease2
{
private:
    Boss *m_boss{};

public:
    Ease2(Boss *boss)
        : m_boss(boss)
    {
    }
    void Ease2Update()
    {
        std::cout << "[" << __FUNCTION__ << "]:" << m_boss->GetName() << "来了，快去请假！！！\n";
    }
    void EaseValueChaned(int a, double b)
    {
    }
};