#include <iostream>

/// @brief 原型类（提供克隆接口）
class CCloneInterface
{
public:
    virtual CCloneInterface *Clone() = 0;
};
/// @brief 工作经验类
class WorkExperience : public CCloneInterface
{
private:
    std::string m_timeBucket{}; // 时间段
    std::string m_company{};    // 所在公司
public:
    void SetTimeBucket(const std::string &timeBucket)
    {
        m_timeBucket = timeBucket;
    }
    void SetCompany(const std::string &company)
    {
        m_company = company;
    }
    void Display()
    {
        std::cout << m_timeBucket << " : " << m_company << std::endl;
    }
    virtual CCloneInterface *Clone() override
    {
        return new WorkExperience(*this);
    }
};
/// @brief 简历类
class CVitae : public CCloneInterface
{
private:
    std::string m_name{};          // 姓名
    int m_age{};                   // 年龄
    WorkExperience m_workExp1{};   // 工作经验1
    WorkExperience *m_pWorkExp2{}; // 工作经验2
public:
    virtual ~CVitae()
    {
        if (m_pWorkExp2)
            delete m_pWorkExp2;
    }
    void SetName(const std::string &name)
    {
        m_name = name;
    }
    void SetAge(int age)
    {
        m_age = age;
    }
    void SetWorkExp1(const std::string &timeBucket, const std::string &company)
    {
        m_workExp1.SetTimeBucket(timeBucket);
        m_workExp1.SetCompany(company);
    }
    void SetWorkExp2(const std::string &timeBucket, const std::string &company)
    {
        if (m_pWorkExp2 == nullptr)
            m_pWorkExp2 = new WorkExperience;
        m_pWorkExp2->SetTimeBucket(timeBucket);
        m_pWorkExp2->SetCompany(company);
    }
    void Display()
    {
        std::cout << "姓名：" << m_name << " 年龄：" << m_age << std::endl;
        m_workExp1.Display();
        if (m_pWorkExp2)
            m_pWorkExp2->Display();
    }
    virtual CCloneInterface *Clone() override
    {
        CVitae *clone = new CVitae(*this);
        if (m_pWorkExp2)
            clone->m_pWorkExp2 = (WorkExperience *)m_pWorkExp2->Clone();
        return clone;
    }
};