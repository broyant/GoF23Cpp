//
//  FacadePattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/5.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef FacadePattern_hpp
#define FacadePattern_hpp

#include <iostream>
using namespace std;

class SubSystemOne {
    
public:
    SubSystemOne() {cout<<"One Constructor!"<<endl;}
    void methodOne() {cout <<"System One,Method One!"<<endl;}
    
};

class SubSystemTwo {
    
public:
    void methodTwo() {cout <<"System Two,Method Two!"<<endl;}
    
};

class SubSystemThree {
    
public:
    void methodThree() {cout <<"System Three,Method Three!"<<endl;}
    
};

class SubSystemFour {
    
public:
    void methodFour() {cout <<"System Four,Method Four!"<<endl;}
    
};


class Facade
{
public:
    Facade(){cout<<"Facade Constructor!"<<endl;};
    void methodA() {one.methodOne();two.methodTwo();three.methodThree();}
    void methodB() {one.methodOne();two.methodTwo();four.methodFour();}
    void methodC() {one.methodOne();two.methodTwo();three.methodThree();four.methodFour();}
    static void methodS(){getStaticOne().methodOne();}
    static SubSystemOne getStaticOne() {return sOne;}
private:
    static SubSystemOne sOne;
    SubSystemOne one;
    SubSystemTwo two;
    SubSystemThree three;
    SubSystemFour four;
};

//

void testFacadePattern();


#endif /* FacadePattern_hpp */
