//
//  InterpretPattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/8.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "InterpretPattern.hpp"
#include <istream>
#include <sstream>

void Expression::interpret(PlayContext& ctx)
{
    string playText = ctx.getPlayText();
    if (playText.empty()) {
        return ;
    }
    else{
        string playKey = playText.substr(0,1);
        playText = playText.substr(2);
        double playValue = stod(playText.substr(0,playText.find(" ")));
        playText = playText.substr(playText.find(" ")+1);
        ctx.setPlayText(playText);
        execute(playKey, playValue);
    }
}


void testInterpreterPattern()
{
    PlayContext playCtx;
    string playText = "O 2 E 0.5 G 0.5 A 3 E 0.5 G 0.5 D 3 ";
    playCtx.setPlayText("O 2 E 0.5 G 0.5 A 3 E 0.5 G 0.5 D 3 ");

    SPEPSN spExp;
    
    FlyweightExpressionFactory fwExpFactory;
    

//    std::istringstream iss(playText);
//    
//    std::istream_iterator<string> ittBegin(iss);
//    std::istream_iterator<string> ittEnd;
//    for (; ittBegin!=ittEnd ;) {
//        cout<<(*ittBegin++)<<"\t";
//        cout<<(*ittBegin++)<<endl;
//    }
//    
//    
//    string first_on_line;
//    double second_on_line;
//    while (iss>>first_on_line>>second_on_line) {
//        cout<<first_on_line << "\t"<<second_on_line<<endl;
//    }
    
    while (!playCtx.getPlayText().empty()) {
        const string& curPlayText = playCtx.getPlayText();
        char key = curPlayText.substr(0,1)[0];
        switch (key) {
            case 'O':
//                spExp = SPEPSN(new Scale);
                spExp = fwExpFactory.getFlyweightExpression("Scale");
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
//                spExp = SPEPSN(new Note);
                spExp = fwExpFactory.getFlyweightExpression("Note");
            default:
                break;
        }
        spExp->interpret(playCtx);
    }
    
    cout<<endl;
}
