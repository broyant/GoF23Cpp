//
//  MediatorPattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/7.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef MediatorPattern_hpp
#define MediatorPattern_hpp

#include <iostream>
#include <vector>
using namespace std;


class Colleague;
typedef shared_ptr<Colleague> SPColleague;
typedef weak_ptr<Colleague> WPColleague;
class Mediator
{
public:
    virtual ~Mediator() = default;
    virtual void sendMessage(string msg,Colleague* collegue) = 0;
};

typedef shared_ptr<Mediator> SPMD;
class Colleague
{
public:
    Colleague() = default;
    Colleague(SPMD mdt):mediator(mdt){}
    virtual ~Colleague() = default;
    void setMediator(const SPMD& med) {mediator = med;}
    virtual void sendMessage(string msg) = 0;
    virtual void notify(string msg) = 0;
protected:
    SPMD mediator;
};

class ConcreteColleagueA:public Colleague
{
public:
    ConcreteColleagueA() = default;
    ConcreteColleagueA(SPMD mdt):Colleague::Colleague(mdt){}
    void sendMessage(string msg) {
        cout<<"Colleague A send Message: "<<msg<<endl;
        mediator->sendMessage(msg, this);
    }
    void notify(string msg) {cout<<"Colleague A get Message: "<<msg<<endl;}
    ~ConcreteColleagueA() {cout<<"Destruction ConcreteColleagueA"<<endl;}
};

class ConcreteColleagueB:public Colleague
{
public:
    ConcreteColleagueB() = default;
    ConcreteColleagueB(SPMD mdt):Colleague::Colleague(mdt){}
    void sendMessage(string msg) {
        cout<<"Colleague B send Message: "<<msg<<endl;
        mediator->sendMessage(msg, this);
    }
    void notify(string msg) {cout<<"Colleague B get Message: "<<msg<<endl;}
    ~ConcreteColleagueB() {cout<<"Destruction ConcreteColleagueB"<<endl;}
};

class ConcreteColleagueC:public Colleague
{
public:
    ConcreteColleagueC() = default;
    ConcreteColleagueC(SPMD mdt):Colleague::Colleague(mdt){}
    void sendMessage(string msg) {
        cout<<"Colleague C send Message: "<<msg<<endl;
        mediator->sendMessage(msg, this);
    }
    void notify(string msg) {cout<<"Colleague C get Message: "<<msg<<endl;}
    ~ConcreteColleagueC() {cout<<"Destruction ConcreteColleagueC"<<endl;}
};


class ConcreteMediator:public Mediator
{
public:
    void addColleague(const SPColleague& col)
    {
//        cout<<"before push"<<col.use_count()<<endl;
        colleagues.push_back(col);
//        cout<<"after push"<<col.use_count()<<endl;
    }
    void removeColleague(const SPColleague& col); 
    void sendMessage(string msg,Colleague* collegue)
    {
        for (auto iter = colleagues.begin(); iter != colleagues.end(); ++iter) {
            if (!(*iter).expired()) {
                SPColleague spCol = (*iter).lock();
                if (spCol.get()!= collegue) {
                    spCol->notify(msg);
                }
            }
        }
    }
    ~ConcreteMediator() {cout<<"Destruction ConcreteMediator"<<endl;}
private:
    vector<WPColleague> colleagues;
};

void testMediatorPattern();


#endif /* MediatorPattern_hpp */
