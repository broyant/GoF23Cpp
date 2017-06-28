//
//  TemplatePattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/2.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "TemplatePattern.hpp"

void testTemplatePattern()
{
    concreteClassA cca;
    cca.templateMethod();
    
    concreteClassB ccb;
    ccb.templateMethod();
}
