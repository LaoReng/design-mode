// 抽象工厂

/// @brief 用户表
class User
{
};
/// @brief 部门表
class Department
{
};

/// @brief 操作用户表 抽象产品类
class IUser
{
public:
    virtual void Insert() = 0;
    virtual User *GetUser() = 0;
};
/// @brief MYSql操作用户便 具体产品类
class MYSqlUser : public IUser
{
public:
    virtual void Insert() override
    {
        std::cout << "MYSQL:向用户表里插入数据\n";
    }
    virtual User *GetUser() override
    {
        std::cout << "MYSQL:返回查询的数据\n";
        return new User;
    }
};
/// @brief Sqlite操作用户便 具体产品类
class SqliteUser : public IUser
{
public:
    virtual void Insert() override
    {
        std::cout << "Sqlite:向用户表里插入数据\n";
    }
    virtual User *GetUser() override
    {
        std::cout << "Sqlite:返回查询的数据\n";
        return new User;
    }
};
/// @brief 操作部门表 抽象产品类
class IDepartment
{
public:
    virtual void Insert() = 0;
    virtual Department *GetDepartment() = 0;
};
/// @brief MYSql操作部门便 具体产品类
class MYSqlDepartment : public IDepartment
{
public:
    virtual void Insert() override
    {
        std::cout << "MYSQL:向部门表里插入数据\n";
    }
    virtual Department *GetDepartment() override
    {
        std::cout << "MYSQL:返回查询的数据\n";
        return new Department;
    }
};
/// @brief Sqlite操作部门便 具体产品类
class SqliteDepartment : public IDepartment
{
    virtual void Insert() override
    {
        std::cout << "Sqlite:向部门表里插入数据\n";
    }
    virtual Department *GetDepartment() override
    {
        std::cout << "Sqlite:返回查询的数据\n";
        return new Department;
    }
};

/// @brief 数据库抽象工厂类
class DataBase
{
public:
    static std::string DBType;
    static IUser *CreateUser()
    {
        if (DBType == "MYSql")
        {
            return new MYSqlUser;
        }
        else if (DBType == "Sqlite")
        {
            return new SqliteUser;
        }
        return nullptr;
    }
    static IDepartment *CreateDepartment()
    {
        if (DBType == "MYSql")
        {
            return new MYSqlDepartment;
        }
        else if (DBType == "Sqlite")
        {
            return new SqliteDepartment;
        }
        return nullptr;
    }
};

std::string DataBase::DBType{"MYSql"};