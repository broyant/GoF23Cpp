//
//  TemplatePattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/2.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef TemplatePattern_hpp
#define TemplatePattern_hpp

#include <iostream>
using namespace std;

class abstractTemplateClass
{
protected:
    virtual void primitiveOperation1() = 0;
    virtual void primitiveOperation2() = 0;

public:
    void templateMethod()
    {
        cout<<"do nothing here but call primitive operations"<<endl;
        primitiveOperation1();
        primitiveOperation2();
    }
    virtual ~abstractTemplateClass() = default;
};


class concreteClassA:public abstractTemplateClass
{
public:
    void primitiveOperation1() override {cout<<"concreteClassA primitiveOperation1"<<endl;}
    void primitiveOperation2() override {cout<<"concreteClassA primitiveOperation2"<<endl;}
};
        
class concreteClassB:public abstractTemplateClass
{
public:
    void primitiveOperation1() override {cout<<"concreteClassB primitiveOperation1"<<endl;}
    void primitiveOperation2() override {cout<<"concreteClassB primitiveOperation2"<<endl;}
};
        
void testTemplatePattern();

#endif /* TemplatePattern_hpp */
