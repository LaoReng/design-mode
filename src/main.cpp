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

int main()
{
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


    return 0;
}