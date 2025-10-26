#ifndef __BINDER_H__
#define __BINDER_H__

#include "function.h"

/// @brief 函数绑定器
class CBinder
{
public:
    CBinder() = default;

    // INFO: 之前不能写成构造函数的原因是，我们需要模板类传归来所封装函数的参数列表，而我们现在还不需要这个可变参数所以不用在函数列表里面写但是需要在模板上写，这就造成了必须通过其他函数的形式把函数的模板类型显示的给出来
    template <typename _OBJ, typename _FUNC>
    void MakeBinder(_OBJ *sub, _FUNC func)
    {
        m_pObj = sub;
        m_pFunc = *(void **)&func;
        if (m_func)
            delete m_func;
        m_func = FuncType<_FUNC>::MakeFunc(func);
        // m_func = new CFunction<_FUNC, _OBJ*, Args...>(func);
    }

    template <typename _FUNC>
    void MakeBinder(_FUNC func)
    {
        m_pFunc = *(void **)&func;
        if (m_func)
            delete m_func;
        m_func = FuncType<_FUNC>::MakeFunc(func);
        // m_func = new CFunction<_FUNC, Args...>(func);
    }

    template <typename... Args>
    void operator()(Args... args)
    {
        if (m_pObj)
        {
            auto tupleArgs = std::make_tuple(m_pObj, std::forward<Args>(args)...);
            m_func->Invoke(&tupleArgs);
        }
        else
        {
            auto tupleArgs = std::make_tuple(std::forward<Args>(args)...);
            m_func->Invoke(&tupleArgs);
        }
    }
    bool operator==(const CBinder &other)
    {
        if (m_pObj == other.m_pObj && m_pFunc == other.m_pFunc)
            return true;
        return false;
    }

private:
    CFunctionBase *m_func{}; // 函数包装器
    void *m_pObj{};          // this指针 可以为空
    void *m_pFunc{};         // 函数指针
};

#endif