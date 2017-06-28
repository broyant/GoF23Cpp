//
//  SimpleFactory.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/2.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "SimpleFactory.hpp"

double AddOperation::calculate()
{
    return lhs+rhs;
}

double MinusOperation::calculate()
{
    return lhs-rhs;
}

double MultiplyOperation::calculate()
{
    return lhs*rhs;
}

double DivideOperation::calculate()
{
    if (rhs == 0) {
        throw logic_error("dividor can not be zero!");
    }
    return lhs/rhs;
}

shared_ptr<Operation> OperationFactory::getOperation(double lhs, double rhs, char oper)
{
    switch (oper) {
        case '+':
            //return shared_ptr<AddOperation>(new AddOperation(lhs,rhs));
            return make_shared<AddOperation>(lhs,rhs);
        case '-':
            return shared_ptr<MinusOperation>(new MinusOperation(lhs,rhs));
        case '*':
            return shared_ptr<MultiplyOperation>(new MultiplyOperation(lhs,rhs));
        case '/':
            return shared_ptr<DivideOperation>(new DivideOperation(lhs,rhs));
        default:
            break;
    }
    return nullptr;
}

shared_ptr<Operation> AddFactory::getOperation(double lhs,double rhs)
{
    return make_shared<AddOperation>(lhs,rhs);
}

shared_ptr<Operation> MinusFactory::getOperation(double lhs,double rhs)
{
    return make_shared<MinusOperation>(lhs,rhs);
}

shared_ptr<Operation> MultiplyFactory::getOperation(double lhs,double rhs)
{
    return make_shared<MultiplyOperation>(lhs,rhs);
}

shared_ptr<Operation> DivideFactory::getOperation(double lhs,double rhs)
{
    return make_shared<DivideOperation>(lhs,rhs);
}

void testSimpleFactory()
{
    shared_ptr<Operation> spOperation = OperationFactory::getOperation(15, 10, '+');
    std::cout<<"the add result is:"<<spOperation->calculate()<<std::endl;
    
    spOperation = OperationFactory::getOperation(15, 10, '-');
    std::cout<<"the substract result is:"<<spOperation->calculate()<<std::endl;
    
    spOperation = OperationFactory::getOperation(15, 10, '*');
    std::cout<<"the multiply result is:"<<spOperation->calculate()<<std::endl;
    
    spOperation = OperationFactory::getOperation(15, 10, '/');
    std::cout<<"the divide result is:"<<spOperation->calculate()<<std::endl;
}

void testMethodFactory()
{
    AddFactory addFactory;
    shared_ptr<Operation> spOperation = addFactory.getOperation(15, 10);
    std::cout<<"the add result is:"<<spOperation->calculate()<<std::endl;
    
    MinusFactory minusFactory;
    spOperation = minusFactory.getOperation(15, 10);
    std::cout<<"the minus result is:"<<spOperation->calculate()<<std::endl;
    
    MultiplyFactory multiplyFactory;
    spOperation = multiplyFactory.getOperation(15, 10);
    std::cout<<"the multiply result is:"<<spOperation->calculate()<<std::endl;
    
    DivideFactory divideFactory;
    spOperation = divideFactory.getOperation(15, 10);
    std::cout<<"the divide result is:"<<spOperation->calculate()<<std::endl;
}
