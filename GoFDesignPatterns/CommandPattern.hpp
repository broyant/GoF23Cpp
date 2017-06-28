//
//  CommandPattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/7.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef CommandPattern_hpp
#define CommandPattern_hpp

#include <iostream>
#include <vector>
using namespace std;



class ICommand{
public:
    virtual ~ICommand() {cout<<"Destruction ICommand"<<endl;}
    virtual void executeCommand() = 0;
};

typedef shared_ptr<ICommand> SPIC;

class ConcreteCommandA:public ICommand
{
public:
    void executeCommand() {cout <<"executing ConcreteCommandA"<<endl;}
};

class ConcreteCommandB:public ICommand
{
public:
    void executeCommand() {cout <<"executing ConcreteCommandB"<<endl;}
};

class Executor
{
public:
    virtual ~Executor() {cout<<"Destruction Executor"<<endl;};
    virtual void execute(const vector<SPIC>& commands);
};

class ConcreteExecutorA:public Executor
{
public:
    void execute(const vector<SPIC>& commands) override
    {
        cout<<"ConcreteExecutor A execute"<<endl;
        Executor::execute(commands);
    }
};
        
class ConcreteExecutorB:public Executor
{
public:
    void execute(const vector<SPIC>& commands) override
    {
        cout<<"ConcreteExecutor B execute"<<endl;
        Executor::execute(commands);
    }
};
        
typedef shared_ptr<Executor> SPETR;

class Invoker
{
public:
    void addCommand(const SPIC& cmd) {commands.push_back(cmd);}
    void removeCommand(const SPIC& cmd) {commands.erase(find(commands.begin(), commands.end(), cmd));}
    void invoke() {realExecutor->execute(commands);}
    void setExecutor(const SPETR& executor) {realExecutor.reset();realExecutor = executor;}
private:
    SPETR realExecutor;
    vector<SPIC> commands;
};
        
//---------------above is wrong about Command Pattern------------
        
void testFakeCommandPattern();
#endif /* CommandPattern_hpp */
