//
//  InterpretPattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/8.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef InterpretPattern_hpp
#define InterpretPattern_hpp

#include <iostream>
using namespace std;
#include <map>


class PlayContext
{
public:
    string getPlayText() const {return playText;}
    void setPlayText(string newText){playText = newText;}
private:
    string playText;
};

class Expression
{
public:
    virtual ~Expression() {cout<<"Destruction Expression!"<<endl;};
    void interpret(PlayContext& ctx);
    virtual void execute(string key,double value) = 0;
};

typedef shared_ptr<Expression> SPEPSN;

class Note:public Expression
{
public:
    void execute(string key,double value)
    {
        int digitKey = ((toupper(key[0]) - 'A') + 5)%7 + 1;
        cout <<digitKey<<" "<<value<<"\t";
    }
};

class Scale:public Expression
{
public:
    void execute(string key,double value)
    {
        string scale;
        switch (static_cast<int>(value)) {
            case 1:
                scale = "低音";
                break;
            case 2:
                scale = "中音";
                break;
            case 3:
                scale = "高音";
                break;
            default:
                break;
        }
        
        cout<<scale<<"\t";
    }
};

class FlyweightExpressionFactory
{
public:
    SPEPSN getFlyweightExpression(string key)
    {
        if (table.find(key) == table.end()) {
            if (key == "Note") {
                table[key] = SPEPSN(new Note);
            }
            else if(key == "Scale")
            {
                table[key] = SPEPSN(new Scale);
            }
        }
        return table[key];
    }
private:
    map<string,SPEPSN> table;
};

void testInterpreterPattern();
#endif /* InterpretPattern_hpp */
