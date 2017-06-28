//
//  MementoPattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/6.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "MementoPattern.hpp"

void testMomentoPattern()
{
    GameRoleInfo gri(1000,100,200);
    Originator ognt(gri);
    cout<<"==========initial state=========="<<endl;
    ognt.showCurrentState();
    
    cout<<"==========take fight1=========="<<endl;
    ognt.takeAFight();
    ognt.showCurrentState();
    
    Momento mmt(ognt.getInfo());
    CareTaker ct(mmt);
    
    cout<<"==========take fight2=========="<<endl;
    ognt.takeAFight();
    ognt.showCurrentState();
    
    cout<<"==========restore to after fight1=========="<<endl;
    ognt.setMemento(ct.getMomento());
    ognt.showCurrentState();
    
}
