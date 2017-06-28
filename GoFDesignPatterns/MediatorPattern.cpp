//
//  MediatorPattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/7.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "MediatorPattern.hpp"

void ConcreteMediator::removeColleague(const SPColleague& col)
{
    for (auto iter = colleagues.begin(); iter!= colleagues.end();) {
        if ((*iter).expired()) {
            iter = colleagues.erase(iter);
        }else{
            if ((*iter).lock() == col) {
                iter = colleagues.erase(iter);
            }else{
                ++iter;
            }
        }
    }
}

void testMediatorPattern()
{
    SPMD mediator(new ConcreteMediator);
    cout<<"mediator use count "<< mediator.use_count()<<endl;
    SPColleague colA(new ConcreteColleagueA(mediator));
    cout<<"mediator use count "<< mediator.use_count()<<endl;
    SPColleague colB(new ConcreteColleagueB(mediator));
    cout<<"mediator use count "<< mediator.use_count()<<endl;
    SPColleague colC(new ConcreteColleagueC(mediator));
    cout<<"mediator use count "<< mediator.use_count()<<endl;
    
    cout<<"col a use count "<< colA.use_count()<<endl;
    cout<<"col b use count "<< colB.use_count()<<endl;
    cout<<"col c use count "<< colC.use_count()<<endl;
    
    typedef shared_ptr<ConcreteMediator> SPCMD;
    
    SPCMD spCnctMediator = dynamic_pointer_cast<ConcreteMediator>(mediator);
    spCnctMediator->addColleague(colA);
    spCnctMediator->addColleague(colB);
    spCnctMediator->addColleague(colC);
    
    cout<<"col a use count "<< colA.use_count()<<endl;
    cout<<"col b use count "<< colB.use_count()<<endl;
    cout<<"col c use count "<< colC.use_count()<<endl;
    
    colA->sendMessage("Message From A!");
    colC->sendMessage("Message From C!");
    
    spCnctMediator->removeColleague(colB);
    colA->sendMessage("Message From A Again;");
    
}
