//
//  ResponsibilityChainPattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/7.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "ResponsibilityChainPattern.hpp"
#include <random>

void Manager::handle(Request& req)
{
    unsigned int amount = req.getAmount();
    switch (req.getType()) {
        case Request::RequestTypeLeave:
            if (amount<=1) {
                cout<<"Manager:have permission of 1 Day Leave,Take a rest!"<<endl;
            }else{
                cout<<"Manager:do not have permission of more than 2 Days Leave,submit to superior!"<<endl;
                superior->handle(req);
            }
            break;
        case Request::RequestTypeSalary:
            if (amount<=1000) {
                cout<<"Manager:have permission of 1000 salary rise,Congratulation!"<<endl;
            }else{
                cout<<"Manager:do not have permission of more than 500 salary rise,submit to superior!"<<endl;
                superior->handle(req);
            }
            break;
        default:
            break;
    }
}

void Director::handle(Request& req)
{
    unsigned int amount = req.getAmount();
    switch (req.getType()) {
        case Request::RequestTypeLeave:
            if (amount<=3) {
                cout<<"Director:have permission of 3 Days Leave,Take a rest!"<<endl;
            }else{
                cout<<"Director:do not have permission of more than 4 Days Leave,submit to superior!"<<endl;
                superior->handle(req);
            }
            break;
        case Request::RequestTypeSalary:
            if (amount<=3000) {
                cout<<"Director:have permission of 3000 salary rise,Congratulation!"<<endl;
            }else{
                cout<<"Director:do not have permission of more than 3000 salary rise,submit to superior!"<<endl;
                superior->handle(req);
            }
            break;
        default:
            break;
    }
}

void CEO::handle(Request& req)
{
    unsigned int amount = req.getAmount();
    switch (req.getType()) {
        case Request::RequestTypeLeave:
            if (amount<=7) {
                cout<<"CEO:OK,you had a very busy month,Take a rest!"<<endl;
            }else{
                cout<<"CEO:I do not think you have a persuasive reason to take a rest of "<<amount<<" days."<<endl;
//                superior->handle(req);
            }
            break;
        case Request::RequestTypeSalary:
            if (amount<=6000) {
                cout<<"CEO:Your hard working earns you the salary rise,Congratulation!"<<endl;
            }else{
                uniform_int_distribution<unsigned> u(1,100);
                default_random_engine dre;
                unsigned count =0;
                for(int i=0;i<100;++i){
                    if (u(dre)>50) {
                        count++;
                    }
                }
                if (count>50) {
                    cout<<"CEO:OK,After a consideration, you get the salary rise,Congratulation!"<<endl;
                }else{
                    cout<<"CEO:I do not think your work is worthy of such a huge salary rise.Sorry!"<<endl;
                }
//                superior->handle(req);
            }
            break;
        default:
            break;
    }
}

void testReponsibilityChainPattern()
{
    Request req(Request::RequestTypeSalary,8000);
    
    Position::SPPT director(new Director);
    Position::SPPT manager(new Manager);
    Position::SPPT ceo(new CEO);
    
    manager->setSuperior(director);
    director->setSuperior(ceo);
    
    manager->handle(req);
}
