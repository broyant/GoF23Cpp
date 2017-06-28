//
//  AbstractFactory.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/5.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef AbstractFactory_hpp
#define AbstractFactory_hpp

#include <iostream>
using namespace std;

class IUser
{
public:
    virtual void insertUser() = 0;
    virtual void getUser() = 0;
protected:
    virtual ~IUser() = default;
};

class IDepartment
{
public:
    virtual void insertDepartment() = 0;
    virtual void getDepartment() = 0;
protected:
    virtual ~IDepartment() = default;
};

class AbstractFactory{
public:
    virtual void createUser() = 0;
    virtual void createDepartment() = 0;
    virtual ~AbstractFactory() = default;
};

class SqlServerUser:public IUser
{
public:
    virtual void insertUser() {printInfo(__func__);}
    virtual void getUser() {printInfo(__func__);}
private:
    void printInfo(string funcName){
        string className = typeid(*this).name();
        size_t len = className.length();
        className = className.replace(0,to_string(len).length(),"");
        cout<<className<<"\t"<<funcName<<endl;
    }
};

class AccessUser:public IUser
{
public:
    virtual void insertUser() {printInfo(__func__);}
    virtual void getUser() {printInfo(__func__);}
private:
    void printInfo(string funcName){
        string className = typeid(*this).name();
        size_t len = className.length();
        className = className.replace(0,to_string(len).length(),"");
        cout<<className<<"\t"<<funcName<<endl;
    }
};

class SqlServerDepartment:IDepartment
{
public:
    virtual void insertDepartment() {printInfo(__func__);}
    virtual void getDepartment() {printInfo(__func__);}
private:
    void printInfo(string funcName){
        string className = typeid(*this).name();
        size_t len = className.length();
        className = className.replace(0,to_string(len).length(),"");
        cout<<className<<"\t"<<funcName<<endl;
    }
};

class AccessDepartment:IDepartment
{
public:
    virtual void insertDepartment() {printInfo(__func__);}
    virtual void getDepartment() {printInfo(__func__);}
private:
    void printInfo(string funcName){
        string className = typeid(*this).name();
        size_t len = className.length();
        className = className.replace(0,to_string(len).length(),"");
        cout<<className<<"\t"<<funcName<<endl;
    }
};

class SqlServerFactory:public AbstractFactory
{
public:
    virtual void createUser() {SqlServerUser ssu;ssu.insertUser();}
    virtual void createDepartment() {SqlServerDepartment ssd;ssd.getDepartment();}
};

class AccessFactory:public AbstractFactory
{
public:
    virtual void createUser() {AccessUser au;au.insertUser();}
    virtual void createDepartment() {AccessDepartment ad;ad.getDepartment();}
};


void testAbstractFactoryPattern();


#endif /* AbstractFactory_hpp */
