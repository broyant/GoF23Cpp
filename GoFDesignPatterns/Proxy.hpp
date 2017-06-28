//
//  Proxy.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/2.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef Proxy_hpp
#define Proxy_hpp

#include <iostream>
using namespace std;

class IGiveGift {
protected:
    virtual void GiveDolls() = 0;
    virtual void GiveFlowers() = 0;
    virtual void GiveChocolate() = 0;
    virtual ~IGiveGift() = default;
};

class SchoolGirl
{
public:
    SchoolGirl(string n = "unknown"):name(n){}
    string getName() const {return name;}
private:
    string name;
};

class Pursuit:public IGiveGift
{
public:
    Pursuit(SchoolGirl girl):sg(girl){}
    void GiveDolls() override {cout<<sg.getName()<<", Give U Dolls"<<endl;}
    void GiveFlowers() override {cout<<sg.getName()<<", Give U Flowers"<<endl;}
    void GiveChocolate() override {cout<<sg.getName()<<", Give U Chocolate"<<endl;}
private:
    SchoolGirl sg;
};
        
class Proxy:public IGiveGift
{
public:
    Proxy(SchoolGirl girl):spp(make_shared<Pursuit>(girl)){}
    void GiveDolls() override {spp->GiveDolls();}
    void GiveFlowers() override {spp->GiveFlowers();}
    void GiveChocolate() override {spp->GiveChocolate();}
private:
//    Pursuit ps;
    shared_ptr<Pursuit> spp;
};
        
void testProxyPattern();

#endif /* Proxy_hpp */
