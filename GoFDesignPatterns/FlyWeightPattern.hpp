//
//  FlyWeightPattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/7.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef FlyWeightPattern_hpp
#define FlyWeightPattern_hpp

#include <iostream>
using namespace std;
#include <map>

class FlyWeight
{
public:
    virtual ~FlyWeight() = default;
    virtual void operation(int extrinsicState) = 0;
};

class ConcreteFlyWeight:public FlyWeight
{
public:
    void operation(int extrinsicState) {cout<<"Shareable extrisic state "<<extrinsicState<<endl;}
};

class UnshareableConcreteFlyWeight:public FlyWeight
{
public:
    void operation(int extrinsicState) {cout<<"Unshareable extrisic state "<<extrinsicState<<endl;}
};

typedef shared_ptr<FlyWeight> SPFW;
class FlyWeightFactory
{
public:
    FlyWeightFactory() = default;
//    {
//        table["one"] = SPFW(new ConcreteFlyWeight);
//        table["two"] = SPFW(new ConcreteFlyWeight);
//        table["three"] = SPFW(new ConcreteFlyWeight);
//    }
    const SPFW getFlyWeight(string key){
        if (table.find(key)==table.end()) {
            table[key] = SPFW(new ConcreteFlyWeight);
        }
        return table[key];
    }
private:
    map<string,SPFW> table;
};

void testFlyWeightPattern();

#endif /* FlyWeightPattern_hpp */
