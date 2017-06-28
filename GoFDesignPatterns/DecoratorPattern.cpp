//
//  DecoratorPattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/2.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "DecoratorPattern.hpp"

void testDecoratorPattern()
{
    shared_ptr<Person> spp(new Person("Tom"));
    shared_ptr<TShirt> spt(new TShirt);
    shared_ptr<SportTrouses> spst(new SportTrouses);
    shared_ptr<SportShoe> spss(new SportShoe);

    spt->setDecoratee(spp);
    spst->setDecoratee(spt);
    spss->setDecoratee(spst);
    spss->show();
}
