//
//  StatePattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/5.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "StatePattern.hpp"

void SleepState::handle(Context* context){
    if (context->getHour()>8&&context->getHour()<12) {
        context->setState(new WorkStateMorning);
        context->proceedWork();
    }
    else{
        cout<<"Sleeping time!"<<endl;
    }
}

void WorkStateMorning::handle(Context* context){
    if (context->getHour()>12) {
        context->setState(new WorkStateAfternoon);
        context->proceedWork();
    }else{
         cout<<"Morning work time!"<<endl;
    }
}

void WorkStateAfternoon::handle(Context* context){
    if (context->getHour()>20 && context->getWorkFinished()) {
        context->setState(new SleepState);
        context->proceedWork();
    }else if(context->getHour()>20){
        context->setState(new ExtraWorkState);
        context->proceedWork();
    }else{
        cout<<"Afternoon work time!"<<endl;
    }
    
}

void ExtraWorkState::handle(Context* context){
    if (context->getHour()>23) {
        context->setState(new SleepState);
        context->proceedWork();
    }else{
        cout<<"Extra work time!"<<endl;
    }
}

void testStatePattern()
{
    Context cxt(new SleepState,0,false);
    cxt.proceedWork();
    cxt.setHour(9);
    cxt.proceedWork();
    cxt.setHour(13);
    cxt.proceedWork();
    cxt.setHour(21);
    cxt.setFinished(true);
    cxt.proceedWork();
}
