#include <iostream>
#include <list>
#include <algorithm>
/// @brief 订阅者基类
class Subscribe
{
public:
    virtual void Update() = 0;
};
/// @brief 发布者基类
class Publish
{
private:
    std::list<Subscribe *> m_lstSubscribe;

public:
    /// @brief 添加订阅者
    /// @param sub 订阅者
    virtual void Add(Subscribe *sub)
    {
        m_lstSubscribe.push_back(sub);
    }
    /// @brief 移除订阅者
    /// @param sub 订阅者
    virtual void Remove(Subscribe *sub)
    {
        auto it = std::find(m_lstSubscribe.begin(), m_lstSubscribe.end(), sub);
        if (it != m_lstSubscribe.end())
        {
            m_lstSubscribe.erase(it);
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
};
/// @brief 具体订阅者牛马类型小张
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