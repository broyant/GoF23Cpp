//
//  CompositePattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/6.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "CompositePattern.hpp"

void Composite::removeComponent(SPI& cpt) {
    auto iter = find(components.begin(), components.end(), cpt);
    components.erase(iter);
}
void Composite::display(int depth)
{
    cout<<string(depth,'-')<<"Composite "<<name<<endl;
    for (auto iter = components.begin(); iter!=components.end(); ++iter) {
        (*iter)->display(depth+2);
    }
}

void testCompositePattern()
{
    IComponent::SPI headerQuarter = IComponent::SPI(new Composite("Beijing Header Quarter"));
    
    IComponent::SPI hqHR = IComponent::SPI(new Leaf("Beijing HQ HR"));
    IComponent::SPI hqRD = IComponent::SPI(new Leaf("Beijing HQ RD"));
    IComponent::SPI hqFN = IComponent::SPI(new Leaf("Beijing HQ FN"));
    
    IComponent::SPI shanghaiBranch = IComponent::SPI(new Composite("Shanghai Branch"));
    IComponent::SPI chengduBranch = IComponent::SPI(new Composite("Chengdu Branch"));
    
    IComponent::SPI shHR = IComponent::SPI(new Leaf("Shanghai BH HR"));
    IComponent::SPI shRD = IComponent::SPI(new Leaf("Shanghai BH RD"));
    IComponent::SPI shFN = IComponent::SPI(new Leaf("Shanghai BH FN"));
    
    IComponent::SPI cdHR = IComponent::SPI(new Leaf("Chengdu BH HR"));
    IComponent::SPI cdRD = IComponent::SPI(new Leaf("Chengdu BH RD"));
    IComponent::SPI cdFN = IComponent::SPI(new Leaf("Chengdu BH FN"));
    
    headerQuarter->addComponent(hqHR);
    headerQuarter->addComponent(hqRD);
    headerQuarter->addComponent(hqFN);
    headerQuarter->addComponent(shanghaiBranch);
    headerQuarter->addComponent(chengduBranch);
    
    shanghaiBranch->addComponent(shHR);
    shanghaiBranch->addComponent(shRD);
    shanghaiBranch->addComponent(shFN);
    
    chengduBranch->addComponent(cdHR);
    chengduBranch->addComponent(cdRD);
    chengduBranch->addComponent(cdFN);
    
//    shanghaiBranch->display(1);
//    chengduBranch->display(1);
    headerQuarter->display(1);

    
}

