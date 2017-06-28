//
//  StatePattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/5.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef StatePattern_hpp
#define StatePattern_hpp

#include <iostream>
using namespace std;


class Context;

class AbstractState
{
public:
    virtual void handle(Context* context) = 0;
    virtual ~AbstractState() = default;
};

class Context
{
public:
    Context(AbstractState *pas,int h = 0,bool finished = false):hour(h),workFinished(finished),innerState(shared_ptr<AbstractState>(pas)){}
    
    void proceedWork() {innerState->handle(this);}
    shared_ptr<AbstractState> getState() const {return innerState;}
    void setState(AbstractState *pState) {innerState.reset();innerState=shared_ptr<AbstractState>(pState);}
    
    void setHour(int h) {hour = h;}
    void setFinished(bool finished) {this->workFinished = finished;}
    
    int getHour() const {return hour;}
    int getWorkFinished() const {return workFinished;}
private:
    int hour;
    bool workFinished;
    shared_ptr<AbstractState> innerState;
};


class WorkStateAfternoon:public AbstractState
{
public:
    void handle(Context* context);
    ~WorkStateAfternoon() {cout<<"Work State Afternoon Destruction!"<<endl;}
};


class WorkStateMorning:public AbstractState
{
public:
    void handle(Context* context);
    ~WorkStateMorning() {cout<<"Work State Morning Destruction!"<<endl;}
};

class SleepState:public AbstractState
{
public:
    void handle(Context* context);
    ~SleepState() {cout<<"Sleep State Destruction!"<<endl;}
};

class ExtraWorkState:public AbstractState
{
public:
    void handle(Context* context);
    ~ExtraWorkState() {cout<<"ExtraWork State Destruction!"<<endl;}
};

void testStatePattern();


#endif /* StatePattern_hpp */
