//
//  SingletonPattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/7.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "SingletonPattern.hpp"

Singleton Singleton::getInstance()
{
    static Singleton instance;
    return instance;
}

shared_ptr<Singleton> Singleton::getPtInstance()
{
    static shared_ptr<Singleton> spSgt(new Singleton);
    return spSgt;
}

void testSingletonPattern()
{
    Singleton* ps1 = static_cast<Singleton *>(Singleton::getPtInstance().get());
    Singleton* ps2 = static_cast<Singleton *>(Singleton::getPtInstance().get());
    
    if (ps1 == ps2) {
        cout<<"just one instance!"<<endl;
    }else{
        cout<<"not only one instance!"<<endl;
    }
    
    
}
