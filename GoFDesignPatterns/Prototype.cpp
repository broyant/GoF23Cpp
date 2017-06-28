//
//  Prototype.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/2.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "Prototype.hpp"


void testPrototypePattern()
{
    Resume r("Tom","Male","30","1999-2008","Microsoft");
    cout<<r;
    cout<<endl;
    
    shared_ptr<ICloneable> pr1 = r.clone();
    std::shared_ptr<Resume> spr = std::dynamic_pointer_cast<Resume> (pr1);
    spr->setTimeRange("2005-2015");
    spr->setWorkCompany("Apple");
    
    cout<<*spr;
    
}
