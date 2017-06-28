//
//  VisitorPattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/8.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "VisitorPattern.hpp"
#include <regex>

string getClassName(string className)
{
    string pattern = "\\d+";
    regex re(pattern);
    smatch results;
    regex_search(className, results,re);
    string resultStr = results.str();
    className = className.substr(resultStr.size());
    return className;
}

string getPersonClassName(Person& p)
{
    string clsName = typeid(p).name();
    return getClassName(clsName);
}

string getStateClassName(State& st)
{
    string clsName = typeid(st).name();
    return getClassName(clsName);
}

void Success::getManReaction(Person& p)
{
    cout<<getPersonClassName(p)<<" "<<getStateClassName(*this)<<" reaction Like this!!!"<<endl;
}

void Success::getWomanReaction(Person& p)
{
     cout<<getPersonClassName(p)<<" "<<getStateClassName(*this)<<" reaction Like that!!!"<<endl;
}

void Failure::getManReaction(Person& p)
{
    cout<<getPersonClassName(p)<<" "<<getStateClassName(*this)<<" reaction Like this..."<<endl;
}

void Failure::getWomanReaction(Person& p)
{
     cout<<getPersonClassName(p)<<" "<<getStateClassName(*this)<<" reaction Like that..."<<endl;
}

void Happy::getManReaction(Person& p)
{
    cout<<getPersonClassName(p)<<" "<<getStateClassName(*this)<<" reaction,laugh hahaha..."<<endl;
}

void Happy::getWomanReaction(Person& p)
{
    cout<<getPersonClassName(p)<<" "<<getStateClassName(*this)<<" reaction,dancing yeah yeah..."<<endl;
}

void Sad::getManReaction(Person& p)
{
    cout<<getPersonClassName(p)<<" "<<getStateClassName(*this)<<" reaction drink some alcohol..."<<endl;
}

void Sad::getWomanReaction(Person& p)
{
    cout<<getPersonClassName(p)<<" "<<getStateClassName(*this)<<" reaction buy buy buy..."<<endl;
}


void testVisitorPattern()
{
    Man tom;
    Success yeah;
    Failure noooh;
    
    tom.accept(yeah);
    tom.accept(noooh);
}

void testVisitorPattern2()
{
    ObjectStructure os;
    os.addPerson(SPP(new Man));
    os.addPerson(SPP(new Woman));
    
    Success yeah;
    Failure noooah;
    Happy smile;
    Sad cry;
    
//    os.display(yeah);
//    cout<<endl;
    
    vector<State *> states;
    states.push_back(&yeah);
    states.push_back(&noooah);
    states.push_back(&smile);
    states.push_back(&cry);
    
    for (auto iter = states.begin() ; iter!= states.end(); ++iter) {
        os.display(*(*iter));
        cout<<endl;
    }
}




