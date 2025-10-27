#ifndef __FUNCTION_H__
#define __FUNCTION_H__

class CFunctionBase;

template <typename Func> struct FuncType
{
    enum { ArgumentCount = -1, IsClassFunction = false };
};
/// @brief 类成员函数偏特化模板
/// @tparam _OBJ 类类型
/// @tparam _Ret 成员函数返回值类型
/// @tparam ...Args 成员函数参数列表
template <class _OBJ, typename _Ret, typename... Args> struct FuncType<_Ret (_OBJ::*)(Args...)>
{
    typedef _OBJ Object;
    typedef _Ret ReturnType;
    typedef _Ret (_OBJ::*Function)(Args...);
    typedef _Ret(Type)(Args...);
    enum { ArgumentCount = sizeof...(Args), IsClassFunction = true };
    // 通过该函数创建函数包装器可以优化需要在创建是传入函数参数类型的做法，因为这里可以自动推断！！！！
    static CFunctionBase *MakeFunc(Function func)
    {
        return new CFunction<Function, _OBJ *, Args...>(func);
    }
};
/// @brief 普通函数偏特化模板
/// @tparam _Ret 函数返回值类型
/// @tparam ...Args 函数参数列表
template <typename _Ret, typename... Args> struct FuncType<_Ret (*)(Args...)>
{
    typedef _Ret ReturnType;
    typedef _Ret (*Function)(Args...);
    typedef _Ret(Type)(Args...);
    enum { ArgumentCount = sizeof...(Args), IsClassFunction = false };
    // 通过该函数创建函数包装器可以优化需要在创建是传入函数参数类型的做法，因为这里可以自动推断！！！！
    static CFunctionBase *MakeFunc(Function func)
    { 
        return new CFunction<Function, Args...>(func);
    }
};
/// @brief 函数包装器基类（扩展可在容器中使用）
class CFunctionBase
{
    typedef void (*Impl)(CFunctionBase *_this, void *args);
    const Impl impl;

public:
    virtual ~CFunctionBase() {}
    void Invoke(void *args)
    {
        impl(this, args);
    }

protected:
    explicit CFunctionBase(Impl func)
        : impl(func)
    {
    }
};
/// @brief 函数包装器
/// @tparam _FUNC 函数类型指针
/// @tparam ...Args 函数参数列表
template <typename _FUNC, typename... Args>
class CFunction : public CFunctionBase
{
public:
    CFunction(_FUNC func)
        : CFunctionBase(&BaseCall), m_pFunc(func)
    {
    }
    virtual ~CFunction() {}
    static void BaseCall(CFunctionBase *_this, void *args)
    {
        static_cast<CFunction *>(_this)->Call(args);
    }

    void Call(void *args)
    {
        auto &_args = *static_cast<std::tuple<Args...> *>(args);
        std::apply(m_pFunc, _args);
    }

private:
    _FUNC m_pFunc;
};

#endif