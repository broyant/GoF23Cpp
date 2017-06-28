//
//  RealCommandPattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/7.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "RealCommandPattern.hpp"

void testCommandPattern()
{
    CommandInvoker waitress;
    SPACR receiver(new ReceiverA);
    
    SPAC cmdA(new CommandA);
    SPAC cmdB(new CommandB);
    cmdA->setReceiver(receiver);
    cmdB->setReceiver(receiver);
    
    waitress.addCommand(cmdA);
    waitress.addCommand(cmdB);
    waitress.invoke();
}
