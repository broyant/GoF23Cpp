//
//  BuilderPattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/5.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef BuilderPattern_hpp
#define BuilderPattern_hpp

#include <iostream>
#include <vector>
using namespace std;

class AbstractPersonBuilder {
public:
    virtual ~AbstractPersonBuilder() = default;
    
    virtual void buildHead() = 0;
    virtual void buildBody() = 0;
    virtual void buildLeftArm() = 0;
    virtual void buildRightArm() = 0;
    virtual void buildLeftLeg() = 0;
    virtual void buildRightLeg() = 0;
};

class ThinPersonBuilder:public AbstractPersonBuilder
{
public:

    virtual void buildHead() {printInfo(__func__);}
    virtual void buildBody() {printInfo(__func__);}
    virtual void buildLeftArm() {printInfo(__func__);}
    virtual void buildRightArm() {printInfo(__func__);}
    virtual void buildLeftLeg() {printInfo(__func__);}
    virtual void buildRightLeg() {printInfo(__func__);}
private:
    void printInfo(string funcName){
        string className = typeid(*this).name();
        size_t len = className.length();
        className = className.replace(0,to_string(len).length(),"");
        cout<<className<<"\t"<<funcName<<endl;
    }
};

class FatPersonBuilder:public AbstractPersonBuilder
{
public:
    
    virtual void buildHead() {printInfo(__func__);}
    virtual void buildBody() {printInfo(__func__);}
    virtual void buildLeftArm() {printInfo(__func__);}
    virtual void buildRightArm() {printInfo(__func__);}
    virtual void buildLeftLeg() {printInfo(__func__);}
    virtual void buildRightLeg() {printInfo(__func__);}
private:
    void printInfo(string funcName){
        string className = typeid(*this).name();
        size_t len = className.length();
        className = className.replace(0,to_string(len).length(),"");
        cout<<className<<"\t"<<funcName<<endl;
    }
};

class PersonBuilderDirector
{
public:
    PersonBuilderDirector(AbstractPersonBuilder* apb):spBuilder(shared_ptr<AbstractPersonBuilder>(apb)) {}
    void createPerson();
private:
    shared_ptr<AbstractPersonBuilder> spBuilder;
};


class Product
{
public:
    void addPart(string part) {product.push_back(part);}
    vector<string> getProduct() const {return product;}
private:
    vector<string> product;
};

class AbstractBuilder{
public:
    virtual ~AbstractBuilder() = default;
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void getResult() = 0;
};

class ConcreteBuilderA:public AbstractBuilder{
    
public:
    void buildPartA() {product.addPart("A partA");}
    void buildPartB() {product.addPart("A partB");}
    void getResult() {
        vector<string> result = product.getProduct();
        for_each(result.cbegin(), result.cend(), [](const string& val){cout<<val<<endl;});
    }
private:
    Product product;
};

class ConcreteBuilderB:public AbstractPersonBuilder{
    
public:
    void buildPartA() {product.addPart("B partA");}
    void buildPartB() {product.addPart("B partB");}
    void getResult() {for_each(product.getProduct().cbegin(), product.getProduct().cend(), [](string val){cout<<val<<endl;});}
private:
    Product product;
};

class Director{
public:
    Director(AbstractBuilder *ab):spBuilder(shared_ptr<AbstractBuilder>(ab)){}
    void createProduct();
private:
    shared_ptr<AbstractBuilder> spBuilder;
};

void testBuilderPattern();
void testBuilderPattern2();

#endif /* BuilderPattern_hpp */
