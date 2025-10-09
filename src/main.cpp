#include <iostream>
#include "Decorator/decorator.h"

int main()
{
    Person* per = new Person("Mr.Lu");
    SuitPants* sp = new SuitPants;
    SuitJacket* sj = new SuitJacket;
    Sneakers* sk = new Sneakers;

    sp->Decorator(per);
    sj->Decorator(sp);
    sk->Decorator(sj);
    sk->Show();
    
    std::cout << "hello world\n";
    return 0;
}