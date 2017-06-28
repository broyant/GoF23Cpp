//
//  RealCommandPattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/7.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef RealCommandPattern_hpp
#define RealCommandPattern_hpp

#include <iostream>
#include <vector>
using namespace std;

class AbsCommandReceiver
{
public:
    virtual ~AbsCommandReceiver() = default;
    virtual void actionForCmdA() = 0;
    virtual void actionForCmdB() = 0;
};

typedef shared_ptr<AbsCommandReceiver> SPACR;

class AbsCommand
{
public:
    virtual ~AbsCommand() = default;
    virtual void executeCommand() = 0;
    void setReceiver(const SPACR& rcv) {receiver = rcv;}
protected:
    SPACR receiver;
};

class CommandA:public AbsCommand
{
public:
    void executeCommand() {receiver->actionForCmdA();}
};

class CommandB:public AbsCommand
{
public:
    void executeCommand() {receiver->actionForCmdB();}
};

class ReceiverA:public AbsCommandReceiver
{
public:
    virtual void actionForCmdA() {cout<<"Receiver A execute action For Command A"<<endl;}
    virtual void actionForCmdB() {cout<<"Receiver A execute action For Command B"<<endl;}
};

class ReceiverB:public AbsCommandReceiver
{
public:
    virtual void actionForCmdA() {cout<<"Receiver B execute action For Command A"<<endl;}
    virtual void actionForCmdB() {cout<<"Receiver B execute action For Command B"<<endl;}
};

typedef shared_ptr<AbsCommand> SPAC;
class CommandInvoker{
public:
    void addCommand(const SPAC& cmd) {commands.push_back(cmd);}
    void removeCommand(const SPAC& cmd) {commands.erase(find(commands.begin(), commands.end(), cmd));}
    void invoke() {for_each(commands.begin(), commands.end(), mem_fn(&AbsCommand::executeCommand));}
private:
    vector<SPAC> commands;
};

void testCommandPattern();

#endif /* RealCommandPattern_hpp */
