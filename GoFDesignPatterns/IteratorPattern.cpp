//
//  IteratorPattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/6.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "IteratorPattern.hpp"

void testIteratorPattern()
{
    shared_ptr<ConcreteCollection<int>> spCC(new ConcreteCollection<int>);
    spCC->push_back(1);
    spCC->push_back(2);
    spCC->push_back(3);
    spCC->push_back(4);
    
    auto_ptr<IIterator<int>> spIt = spCC->getIterator();
    while (spIt->hasNext()) {
        cout<<spIt->next()<<"\t";
    }
    cout<<endl;
}
