//
//  IteratorAgain.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/8.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "IteratorAgain.hpp"

void testIteratorPatternWithSmartPointer()
{
    VectorCollection<int> iCollection;
    iCollection.addItem(1);
    iCollection.addItem(2);
    iCollection.addItem(3);
    
    shared_ptr<AbsIterator<int> > iter = iCollection.getIterator();
    while (iter->has_next()) {
        cout<<iter->next()<<"\t";
    }
    cout<<endl;
}
