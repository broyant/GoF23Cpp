//
//  BridgePattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/7.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef BridgePattern_hpp
#define BridgePattern_hpp

#include <iostream>
using namespace std;

class Implementor
{
public:
    virtual ~Implementor() = default;
    virtual void operationImpl() = 0;
};

class Abstraction
{
public:
    typedef shared_ptr<Implementor> SPImplementor;
    Abstraction(SPImplementor spi):realImpl(spi){cout<<"===use count3 "<<spi.use_count()<<endl;}
    virtual ~Abstraction() = 0;
    void operation() {cout<<"do nothing but call realImpl"<<endl;realImpl->operationImpl();}
private:
    SPImplementor realImpl;
};


class RefineAbstraction:public Abstraction
{
public:
    RefineAbstraction(SPImplementor spi):Abstraction::Abstraction(spi) {cout<<"===use count2 "<<spi.use_count()<<endl;}
    ~RefineAbstraction() {cout<<"RefineAbstraction Destruction"<<endl;}
};

class ConcreteImplementorA:public Implementor
{
public:
    ~ConcreteImplementorA() {cout<<"ConcreteImplementorA Destruction"<<endl;}
    void operationImpl() {cout<<"A is Doing real Implemention things!"<<endl;}
};

class ConcreteImplementorB:public Implementor
{
public:
    ~ConcreteImplementorB() {cout<<"ConcreteImplementorB Destruction"<<endl;}
    void operationImpl() {cout<<"B is Doing real Implemention things!"<<endl;}
};

void testBridgePattern();



#endif /* BridgePattern_hpp */
