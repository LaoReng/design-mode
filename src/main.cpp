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

    std::cout << "hello world\n";
    return 0;
}