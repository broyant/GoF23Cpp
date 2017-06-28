//
//  DecoratorPattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/2.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef DecoratorPattern_hpp
#define DecoratorPattern_hpp

#include <iostream>
using namespace std;

class AbstractPerson
{
public:
    AbstractPerson(string n):name(n){}
    virtual void show() = 0;
    virtual ~AbstractPerson() {cout<<"AbstractPerson Destructor"<<endl;}
protected:
    string name;
};

class Person:public AbstractPerson
{
public:
    Person(string name = "unknown"):AbstractPerson(name){}
    void show() {cout<<"Person "<<name<<endl;}
};
        
class Finery:public AbstractPerson
{
public:
    Finery(string name = "finery"):AbstractPerson(name){}
    void setDecoratee(shared_ptr<AbstractPerson> spabp) {spap = spabp;}
    virtual void show() {spap->show(); cout<<"Wear Finery "<<name<<endl;}
protected:
    shared_ptr<AbstractPerson> spap;
};


class TShirt:public Finery
{
public:
    TShirt(string name = "TShirt"):Finery(name){}
};

class SportTrouses:public Finery
{
public:
    SportTrouses(string name = "SportTrouses"):Finery(name){}
};

class Hat:public Finery
{
public:
    Hat(string name = "Hat"):Finery(name){}
};

class Tie:public Finery
{
public:
    Tie(string name = "Tie"):Finery(name){}
};

class Suit:public Finery
{
public:
    Suit(string name = "Suit"):Finery(name){}
};

class LeatherShoe:public Finery
{
public:
    LeatherShoe(string name = "LeatherShoe"):Finery(name){}
};

class SportShoe:public Finery
{
public:
    SportShoe(string name = "SportShoe"):Finery(name){}
};

void testDecoratorPattern();


#endif /* DecoratorPattern_hpp */
