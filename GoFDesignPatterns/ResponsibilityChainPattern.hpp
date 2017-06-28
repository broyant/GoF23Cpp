//
//  ResponsibilityChainPattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/7.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef ResponsibilityChainPattern_hpp
#define ResponsibilityChainPattern_hpp

#include <iostream>
using namespace std;

class Request
{
public:
    enum RequestType{RequestTypeLeave = 0,RequestTypeSalary=1};
    Request(RequestType t = RequestTypeLeave,int amt =0):type(t),amount(amt) {}
    RequestType getType() const {return type;}
    unsigned int getAmount() const {return amount;}
private:
    RequestType type;
    unsigned int amount;
};

class Position
{
public:
    virtual ~Position() = default;
    typedef shared_ptr<Position> SPPT;
    void setSuperior(const SPPT& sp){superior = sp;}
    virtual void handle(Request&) = 0;
protected:
    SPPT superior;
};

class Manager:public Position
{
public:
    void handle(Request&) override;
};

class Director:public Position
{
public:
    void handle(Request&) override;
};

class CEO:public Position
{
public:
    void handle(Request&) override;
};

void testReponsibilityChainPattern();

#endif /* ResponsibilityChainPattern_hpp */
