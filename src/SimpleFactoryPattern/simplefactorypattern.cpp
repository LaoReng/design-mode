#include "simplefactorypattern.h"

OperationFactory::OperationFactory(/* args */)
{
}

OperationFactory::~OperationFactory()
{
}

Operation *OperationFactory::CreateOperation(std::string strOperation)
{
    Operation *op = nullptr;
    if (strOperation == "+")
    {
        op = new OperationAdd;
    }
    else if (strOperation == "-")
    {
        op = new OperationSub;
    }
    else if (strOperation == "*")
    {
        op = new OperationMult;
    }
    else if (strOperation == "/")
    {
        op = new OperationDiv;
    }
    return op;
}
