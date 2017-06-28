//
//  SingletonPattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/7.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef SingletonPattern_hpp
#define SingletonPattern_hpp

#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton getInstance();
    static shared_ptr<Singleton> getPtInstance();
private:
    Singleton() = default;
};

void testSingletonPattern();

#endif /* SingletonPattern_hpp */
