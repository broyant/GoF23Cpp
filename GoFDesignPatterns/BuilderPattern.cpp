//
//  BuilderPattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/5.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "BuilderPattern.hpp"

void PersonBuilderDirector::createPerson()
{
    spBuilder->buildHead();
    spBuilder->buildBody();
    spBuilder->buildLeftArm();
    spBuilder->buildRightArm();
    spBuilder->buildLeftLeg();
    spBuilder->buildRightLeg();
}

void Director::createProduct()
{
    spBuilder->buildPartA();
    spBuilder->buildPartB();
    spBuilder->getResult();
}

void testBuilderPattern()
{
    ThinPersonBuilder *thinBuilder = new ThinPersonBuilder;
    PersonBuilderDirector director(thinBuilder);
    director.createPerson();
}



void testBuilderPattern2()
{
    ConcreteBuilderA *builderA = new ConcreteBuilderA;
    Director director(builderA);
    director.createProduct();
    
}
