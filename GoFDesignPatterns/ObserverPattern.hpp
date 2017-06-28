//
//  ObserverPattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/5.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef ObserverPattern_hpp
#define ObserverPattern_hpp

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class IObserver
{
public:
    void virtual update() = 0;
    virtual ~IObserver() = default;
};

class ISubject
{
public:
    virtual ~ISubject() { for(auto iter = observers.begin();iter != observers.end();++iter) delete *iter; };
    virtual void attachObserver(shared_ptr<IObserver> observer) = 0;
    virtual void removeObserver(shared_ptr<IObserver> observer) = 0;
    virtual void attachObserver(IObserver* observer) = 0;
    virtual void removeObserver(IObserver* observer) = 0;
    void Notify() {for_each(observers.begin(), observers.end(),mem_fn(&IObserver::update));}
    void spNotify();

protected:
//    vector<shared_ptr<IObserver>>& getObservers() {return observers;}
    vector<weak_ptr<IObserver>> spObservers;
    vector<IObserver* > observers;
};


class NBAObserver:public IObserver
{
public:
    void update() {cout<<"NBA Observer update!"<<endl;}
    ~NBAObserver() {cout<<"NBA Observer Destuction;"<<endl;}
};

class StockObserver:public IObserver
{
public:
    void update() {cout<<"Stock Observer update!"<<endl;}
    ~StockObserver() {cout<<"Stock Observer Destuction;"<<endl;}
};

class Secretery:public ISubject
{
public:
    virtual void attachObserver(shared_ptr<IObserver> observer) {spObservers.push_back(observer);}
    virtual void removeObserver(shared_ptr<IObserver> observer) ;
    virtual void attachObserver(IObserver *observer) {observers.push_back(observer);}
    virtual void removeObserver(IObserver *observer) ;
};

class ISubjectPro
{
public:
    virtual ~ISubjectPro()=default;
    virtual void attachObserver(shared_ptr<IObserver>& observer) = 0;
    virtual void removeObserver(shared_ptr<IObserver>& observer) = 0;
    void Notify() {for_each(observers.begin(), observers.end(),mem_fn(&IObserver::update));}
protected:
    vector<shared_ptr<IObserver>> observers;

};

class SecreteryPro:public ISubjectPro
{
public:
    virtual void attachObserver(shared_ptr<IObserver>& observer) {observers.push_back(observer);}
    virtual void removeObserver(shared_ptr<IObserver>& observer) {observers.erase(find(observers.begin(), observers.end(), observer));}
};

void testObserverPattern();

void testObserverPattern2();

#endif /* ObserverPattern_hpp */
