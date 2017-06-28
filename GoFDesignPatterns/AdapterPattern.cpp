//
//  AdapterPattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/6.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "AdapterPattern.hpp"

void testAdapterPattern()
{
    Adaptee *adaptee = new Adaptee;
    unique_ptr<Target> upt = unique_ptr<Target>(new Adapter(adaptee));
    upt->request();
}
