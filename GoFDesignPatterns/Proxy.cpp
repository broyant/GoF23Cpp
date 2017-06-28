//
//  Proxy.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/2.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "Proxy.hpp"


void testProxyPattern()
{
    SchoolGirl sg("Lucy");
    Proxy p(sg);
    p.GiveDolls();
    p.GiveFlowers();
    p.GiveChocolate();
}
