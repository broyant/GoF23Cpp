//
//  MementoPattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/6.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef MementoPattern_hpp
#define MementoPattern_hpp

#include <iostream>
using namespace std;

class GameRoleInfo{
public:
    GameRoleInfo(int h=0,int m=0,int e=0):hp(h),mp(m),exp(e){}
    int getHp() const {return hp;}
    int getMp() const {return mp;}
    int getExp() const {return exp;}
    
    void setHp(int h) {hp = h;}
    void setMp(int m) {mp = m;}
    void setExp(int e) {exp = e;}
private:
    int hp;
    int mp;
    int exp;
};

class Momento{
public:
    Momento(GameRoleInfo gInfo):gri(gInfo){}
    GameRoleInfo getInfo() {return gri;}
private:
    GameRoleInfo gri;
};

class Originator{
public:
    Originator(GameRoleInfo gInfo):gri(gInfo){}
    void setMemento(Momento m) {gri = m.getInfo();}
    Momento createMemento() {Momento mmt(gri);return mmt;}
    void takeAFight() {gri.setHp(gri.getHp()/2);gri.setMp(gri.getMp()/2);}
    void showCurrentState() {cout<<"hp: "<<gri.getHp()<<"\t"<<"mp: "<<gri.getMp()<<"\t"<<"exp: "<<gri.getExp()<<endl;}
    GameRoleInfo getInfo() const {return gri;}
private:
    GameRoleInfo gri;
};

class CareTaker{
public:
    CareTaker(Momento m):mmt(m){}
    Momento getMomento() {return mmt;}
    void setMemento(Momento m) {mmt = m;}
private:
    Momento mmt;
};

void testMomentoPattern();

#endif /* MementoPattern_hpp */
