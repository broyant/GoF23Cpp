//
//  BridgePattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/7.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "BridgePattern.hpp"

Abstraction::~Abstraction()
{
    cout<<"Abstraction Destruction"<<endl;
    cout<<"===use count5 "<<realImpl.use_count()<<endl;
}

void testBridgePattern()
{
    Abstraction::SPImplementor spi = Abstraction::SPImplementor(new ConcreteImplementorA);
    {
    cout<<"===use count1 "<<spi.use_count()<<endl;
    RefineAbstraction ra(spi);
    cout<<"===use count4 "<<spi.use_count()<<endl;
    ra.operation();
    }
    cout<<"===use count6 "<<spi.use_count()<<endl;
}
