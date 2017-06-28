//
//  FlyWeightPattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/7.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "FlyWeightPattern.hpp"

void testFlyWeightPattern()
{
    FlyWeightFactory f;
    int exState = 20;
    SPFW spfw1 = f.getFlyWeight("one");
    spfw1->operation(exState--);
    
    SPFW spfw2 = f.getFlyWeight("two");
    spfw2->operation(exState--);
    
    SPFW spfw3 = f.getFlyWeight("three");
    spfw3->operation(exState--);
}
