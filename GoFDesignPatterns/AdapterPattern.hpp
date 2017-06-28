//
//  AdapterPattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/6.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef AdapterPattern_hpp
#define AdapterPattern_hpp

#include <iostream>
using namespace std;

void testAdapterPattern();

class Target
{
public:
    virtual void request()= 0;
    virtual ~Target() = default;
};


class Adaptee
{
public:
    void specificRequest() {cout<<"Adaptee can finished specific Request!"<<endl;}
    ~Adaptee() {cout<<"Adaptee Destruction!"<<endl;}
};

class Adapter:public Target{
public:
    Adapter(Adaptee *pa):spAdaptee(shared_ptr<Adaptee>(pa)) {}
    void request() {cout<<"do nothing but call adaptee specific request!"<<endl;
        spAdaptee->specificRequest();}
    ~Adapter() {cout<<"Adapter Destruction!"<<endl;}
private:
    shared_ptr<Adaptee> spAdaptee;
};

#endif /* AdapterPattern_hpp */
