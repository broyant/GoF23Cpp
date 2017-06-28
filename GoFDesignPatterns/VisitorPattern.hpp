//
//  VisitorPattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/8.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef VisitorPattern_hpp
#define VisitorPattern_hpp

#include <iostream>
#include <vector>
using namespace std;

class Person;

class State
{
public:
    virtual ~State() = default;
    virtual void getManReaction(Person& ) = 0;
    virtual void getWomanReaction(Person& ) = 0;
};

class Success:public State
{
public:
    virtual void getManReaction(Person& p);
    virtual void getWomanReaction(Person& p);
};

class Failure:public State
{
public:
    virtual void getManReaction(Person& p);
    virtual void getWomanReaction(Person& p);
};

class Happy:public State
{
public:
    virtual void getManReaction(Person& p);
    virtual void getWomanReaction(Person& p);
};

class Sad:public State
{
public:
    virtual void getManReaction(Person& p);
    virtual void getWomanReaction(Person& p);
};


class Person
{
public:
    virtual ~Person() = default;
    virtual void accept(State& st) = 0;
};

class Man:public Person{
public:
    void accept(State& st)
    {
        st.getManReaction(*this);
    }
};

class Woman:public Person{
public:
    void accept(State& st)
    {
        st.getWomanReaction(*this);
    }
};

typedef shared_ptr<Person> SPP;

class ObjectStructure
{
public:
    void addPerson(const SPP& per) {persons.push_back(per);}
    void display(State& st){
        for (auto iter = persons.begin(); iter!= persons.end(); ++iter) {
            (*iter)->accept(st);
        }
    }
private:
    vector<SPP> persons;
};

void testVisitorPattern();
void testVisitorPattern2();


#endif /* VisitorPattern_hpp */
