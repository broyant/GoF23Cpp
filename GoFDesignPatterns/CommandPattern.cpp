//
//  CommandPattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/7.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "CommandPattern.hpp"


void Executor::execute(const vector<SPIC>& commands)
{
    for_each(commands.begin(), commands.end(),mem_fn(&ICommand::executeCommand));
}

void testFakeCommandPattern()
{
    Invoker waitress;
    
    waitress.addCommand(SPIC(new ConcreteCommandA));
    waitress.addCommand(SPIC(new ConcreteCommandB));
    waitress.setExecutor(SPETR(new ConcreteExecutorA));
    waitress.invoke();
}
