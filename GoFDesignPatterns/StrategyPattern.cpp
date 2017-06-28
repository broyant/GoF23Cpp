//
//  StrategyPattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/2.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "StrategyPattern.hpp"

CashContext::CashContext(CashType type)
{
    switch (type) {
        case CashTypeNormal:
            spcs = make_shared<CashNormal>();
            break;
        case CashTypeRebate:
            spcs = make_shared<CashRebate>(0.6);
            break;
        case CashTypeReturn:
            spcs = make_shared<CashReturn>(40);
            break;
        default:
            break;
    }
}

void testStrategyByClass()
{
    CashNormal csnm;
    CashRebate csrb(0.5);
    CashReturn csrt(40);
    
    double money = 350;
    double result = 0;
    result = CashContext::getResult(money, csnm);
    std::cout<<"the origin price is : "<<money <<" the normal final result is:"<<result<<std::endl;
    
    result = CashContext::getResult(money, csrb);
    std::cout<<"the origin price is : "<<money <<" the discount final result is:"<<result<<std::endl;
    
    result = CashContext::getResult(money, csrt);
    std::cout<<"the origin price is : "<<money <<" the return final result is:"<<result<<std::endl;
    
}

void testStrategyByObject()
{
    CashContext context1;
    double money = 350;
    double result = 0;
    result = context1.getResult(money);
    std::cout<<"the origin price is : "<<money <<" the normal final result is:"<<result<<std::endl;
    
    CashContext context2(CashContext::CashTypeRebate);
    result = context2.getResult(money);
    std::cout<<"the origin price is : "<<money <<" the discount final result is:"<<result<<std::endl;
    
    CashContext context3(CashContext::CashTypeReturn);
    result = context3.getResult(money);
    std::cout<<"the origin price is : "<<money <<" the return final result is:"<<result<<std::endl;
    
}
