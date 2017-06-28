//
//  CompositePattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/6.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef CompositePattern_hpp
#define CompositePattern_hpp

#include <iostream>
#include <vector>

using namespace std;

class IComponent
{
public:
    typedef shared_ptr<IComponent> SPI;
    IComponent(string n):name(n){}
    virtual ~IComponent() = default;
    virtual void addComponent(SPI& cpt) = 0;
    virtual void removeComponent(SPI& cpt) = 0;
    virtual void display(int depth) = 0;
protected:
    string name;
};

class Leaf:public IComponent
{
public:
    Leaf(string n):IComponent(n){}
    virtual void addComponent(SPI& cpt) {};
    virtual void removeComponent(SPI& cpt) {};
    virtual void display(int depth)
    {
        cout<<string(depth,'-')<<"Leaf "<<name<<endl;
    }
    ~Leaf() {cout<<"Leaf Destruction!"<<endl;}

};

class Composite:public IComponent
{
public:
    Composite(string n):IComponent(n) {}
    virtual void addComponent(SPI& cpt) {components.push_back(cpt);};
    virtual void removeComponent(SPI& cpt) ;
    virtual void display(int depth);
    ~Composite() {cout<<"Composite Destruction!"<<endl;}
private:
    vector<SPI> components;
};

void testCompositePattern();

#endif /* CompositePattern_hpp */
