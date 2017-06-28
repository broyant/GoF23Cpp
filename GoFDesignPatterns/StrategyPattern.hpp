//
//  StrategyPattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/2.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef StrategyPattern_hpp
#define StrategyPattern_hpp

#include <iostream>
#include <math.h>
using namespace std;


void testStrategyByClass();
void testStrategyByObject();

//base class
class CashSuper
{
public:
    virtual double acceptedCash(double origin) = 0;
};

class CashNormal:public CashSuper
{
public:
    virtual double acceptedCash(double origin) {return origin;}
};

class CashRebate:public CashSuper
{
public:
    CashRebate(double dsct = 0.8):discount(dsct) {}
    virtual double acceptedCash(double origin) {return origin*discount;}
    double getDiscount() const {return discount;}
    void setDiscount(double dsct) {discount = dsct;}
private:
    double discount;
};

class CashReturn:public CashSuper
{
public:
    CashReturn(double rtcnt = 30):returnCnt(rtcnt) {}
    virtual double acceptedCash(double origin) {return origin - (floor(origin/100))*returnCnt; }
    double getReturnCnt() const {return returnCnt;}
    void setReturnCnt(double recnt) {returnCnt = recnt;}
private:
    double returnCnt;
};

//Combine with Simple Method;
class CashContext
{
public:
    enum CashType {CashTypeNormal =0,CashTypeRebate=1,CashTypeReturn=2};
    CashContext(CashType type = CashTypeNormal);
    
    static double getResult(double origin,CashSuper& cs)
    {
        return cs.acceptedCash(origin);
    }
    double getResult(double origin)
    {
        return spcs->acceptedCash(origin);
    }
private:
    shared_ptr<CashSuper> spcs;
};

#endif /* StrategyPattern_hpp */
