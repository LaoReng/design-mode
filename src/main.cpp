#include <iostream>
#ifdef DECORATOR
#include "Decorator/decorator.h"
#endif
#ifdef PROXY
#include "Proxy/proxy.h"
#endif // PROXY

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

    std::cout << "hello world\n";
    return 0;
}