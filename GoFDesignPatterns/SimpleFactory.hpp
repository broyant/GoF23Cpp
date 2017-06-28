//
//  SimpleFactory.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/2.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef SimpleFactory_hpp
#define SimpleFactory_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

void testSimpleFactory();
void testMethodFactory();


class Operation
{
public:
    Operation(double l,double r):lhs(l),rhs(r){}
    virtual double calculate() = 0;
    virtual ~Operation(){std::cout<<"Operation Destructor"<<std::endl;}
protected:
    double lhs;
    double rhs;
};

class AddOperation:public Operation
{
public:
    AddOperation(double l = 0,double r = 0):Operation(l,r){}
    double calculate() override;
    ~AddOperation() {std::cout<<"AddOperation Destructor"<<std::endl;}
};

class MinusOperation:public Operation
{
 public:
    MinusOperation(double l = 0,double r = 0):Operation(l,r){}
    double calculate() override;
    ~MinusOperation() {std::cout<<"MinusOperation Destructor"<<std::endl;}
};

class MultiplyOperation:public Operation
{
public:
    MultiplyOperation(double l = 0,double r = 0):Operation(l,r){}
    double calculate() override;
    ~MultiplyOperation() {std::cout<<"MultiplyOperation Destructor"<<std::endl;}
};

class DivideOperation:public Operation
{
public:
    DivideOperation(double l = 0,double r = 1):Operation(l,r){}
    double calculate() override;
    ~DivideOperation() {std::cout<<"DivideOperation Destructor"<<std::endl;}
};


class OperationFactory
{
public:
    static shared_ptr<Operation> getOperation(double lhs,double rhs,char oper);
};

class MethodFactory
{
protected:
    virtual shared_ptr<Operation> getOperation(double lhs,double rhs) = 0;
};

class AddFactory:public MethodFactory
{
public:
    shared_ptr<Operation> getOperation(double lhs = 0,double rhs = 0) override;
};

class MinusFactory:public MethodFactory
{
public:
    shared_ptr<Operation> getOperation(double lhs = 0,double rhs = 0) override;
};

class MultiplyFactory:public MethodFactory
{
public:
    shared_ptr<Operation> getOperation(double lhs = 0,double rhs = 0) override;
};

class DivideFactory:public MethodFactory
{
public:
    shared_ptr<Operation> getOperation(double lhs = 0,double rhs = 1) override;
};



#endif /* SimpleFactory_hpp */
