//
//  AbstractFactory.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/5.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "AbstractFactory.hpp"

void testAbstractFactoryPattern()
{
    AbstractFactory* factory = new AccessFactory;
    factory->createUser();
    factory->createDepartment();
    
    delete factory;
    factory = nullptr;
    
}
