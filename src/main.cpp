#include <iostream>
#ifdef DECORATOR
#include "Decorator/decorator.h"
#endif
#ifdef PROXY
#include "Proxy/proxy.h"
#endif // PROXY
#ifdef FACTORY_METHOD
#include "FactoryMethod/factorymethod.h"
#endif // FACTORY_METHOD
#ifdef PROTOTYPE
#include "Prototype/prototype.h"
#endif // PROTOTYPE
#ifdef TEMPLATE_METHOD
#include "TemplateMethod/templatemethod.h"
#endif // TEMPLATE_METHOD
#ifdef FACADE
#include "Facade/facade.h"
#endif // FACADE
#ifdef BUILDER
#include "Builder/builder.h"
#endif // BUILDER
#ifdef OBSERVER
#include "Observer/observer.h"
#endif // OBSERVER

int test1(int  a)
{
    std::cout << __FUNCTION__ << " nihao" << a << "   " << std::endl;
    return 1  - a;
}
int test2(int a, int b)
{
    std::cout << "nihao\n";
    return 0;
}

class ClassTest
{
public:
    void TestCall(int  a, int  b) {
        std::cout << m_b << __FUNCTION__ << " nihao\n";
    }
    void TestCall2(ClassTest* a) {
        std::cout << a << __FUNCTION__ << " nihao\n";
    }
public:
    int m_b{};
};


int main()
{
    //ClassTest xx;
    //xx.m_b = 120;
    //CBinder cbind;
    //cbind.MakeBinder(&xx, &ClassTest::TestCall);        // 两个参数的成员函数
    //cbind(1, 2);
    //cbind.MakeBinder( &test1);      // 一个参数的普通函数
    //cbind(1);

    //return 0;


#ifdef DECORATOR
    Person* per = new Person("Mr.Lu");
    SuitPants* sp = new SuitPants;
    SuitJacket* sj = new SuitJacket;
    Sneakers* sk = new Sneakers;

    sp->Decorator(per);
    sj->Decorator(sp);
    sk->Decorator(sj);
    sk->Show();
#endif // DECORATOR
#ifdef PROXY
    OptionProxy proxy("小红");
    proxy.GiveFlowers();
    proxy.GiveDoll();
    proxy.GiveSnacks();
#endif // PROXY
#ifdef FACTORY_METHOD
    OperationFactoryMethod* ofm = new FactoryMethodSub;
    OperationBase* ob = ofm->CreateOperation();
    ob->m_optNum1 = 1;
    ob->m_optNum2 = 2;
    std::cout << ob->m_optNum1 << " - " << ob->m_optNum2 << " = " << ob->GetResult() << std::endl;
#endif // FACTORY_METHOD
#ifdef PROTOTYPE
    CVitae* lu = new CVitae;
    lu->SetName("大鸟");
    lu->SetAge(21);
    lu->SetWorkExp1("2024/7-2024/12", "Neusoft");
    lu->SetWorkExp2("2025/3-2025/6", "zhiyuan");
    CVitae* a = (CVitae*)lu->Clone();
    a->SetWorkExp2("2025/3-2025/6", "ZY");
    CVitae* b = (CVitae*)lu->Clone();
    b->SetName("小菜");
    lu->Display();
    a->Display();
    b->Display();
    delete lu;
    delete a;
    delete b;
#endif // PROTOTYPE
#ifdef TEMPLATE_METHOD
    ExaminationPaperA epA;
    ExaminationPaperB epB;
    epA.Question1();
    epB.Question2();
    epB.Question1();
    epB.Question2();
#endif // TEMPLATE_METHOD
#ifdef FACADE
    CFacade facade;
    facade.MethodA();
    facade.MethodB();
#endif // FACADE
#ifdef BUILDER
    Builder* pBuilderA = new TranslateBuilderA;
    Director d(pBuilderA);
    d.Create();
#endif // BUILDER
#ifdef OBSERVER
    Boss laoLu;
    Effort xiaoZhang(&laoLu);
    Ease xiaoLi(&laoLu);
    laoLu.Add(&xiaoZhang);
    laoLu.Add(&xiaoLi);
    laoLu.Nodify();
    std::cout << "========华丽分割线========\n";
    laoLu.Remove(&xiaoLi);
    laoLu.Nodify();
    std::cout << "========华丽分割线========\n";
    Effort2 xw(&laoLu);
    Ease2 xs(&laoLu);
    Ease2 xx(&laoLu);
    laoLu.Add(&xw, &Effort2::Effort2Update);
    laoLu.Add(&xs, &Ease2::Ease2Update);    // 消息订阅不能为函数重载
    laoLu.Add(&xx, &Ease2::Ease2Update);
    laoLu.Nodify();
    std::cout << "========华丽分割线========\n";
    laoLu.Remove(&xx, &Ease2::Ease2Update);
    laoLu.Nodify();
#endif // OBSERVER

    return 0;
}