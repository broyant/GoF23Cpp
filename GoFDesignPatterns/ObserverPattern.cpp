//
//  ObserverPattern.cpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/5.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#include "ObserverPattern.hpp"

void ISubject::spNotify()
{
    for(auto iter = spObservers.begin(); iter != spObservers.end(); )
    {
        if ((*iter).expired()) {
            iter = spObservers.erase(iter);
        }else{
            shared_ptr<IObserver> observer = (*iter).lock();
            observer->update();
            ++iter;
        }
    }
}

void Secretery::removeObserver(shared_ptr<IObserver> observerToRemove)
{
    for(auto iter = spObservers.begin(); iter != spObservers.end(); )
    {
        if ((*iter).expired()) {
            iter = spObservers.erase(iter);
        }else{
            shared_ptr<IObserver> observer = (*iter).lock();
            if (observerToRemove == observer) {
                spObservers.erase(iter);
                break;
            }
        }
    }
}

void Secretery::removeObserver(IObserver* observer)
{
    auto iterBegin = remove(observers.begin(), observers.end(), observer);
    observers.erase(iterBegin, observers.end());
}

void testObserverPattern()
{
    Secretery sec;
    
    shared_ptr<IObserver> spNBAObserver = shared_ptr<IObserver>(new NBAObserver);
    shared_ptr<IObserver> spStockObserver = shared_ptr<IObserver>(new StockObserver);
    
//    sec.attachObserver(nbaOb);
//    sec.attachObserver(stockOb);
//    
//    sec.Notify();
//    
//    sec.removeObserver(nbaOb);
//    delete nbaOb;
//    sec.Notify();
    
    sec.attachObserver(spNBAObserver);
    sec.attachObserver(spStockObserver);
    
    sec.spNotify();
    
    sec.removeObserver(spNBAObserver);
    sec.spNotify();
}

void testObserverPattern2()
{
    SecreteryPro secPro;

    shared_ptr<IObserver> spNBAObserver = shared_ptr<IObserver>(new NBAObserver);
    shared_ptr<IObserver> spStockObserver = shared_ptr<IObserver>(new StockObserver);
    
    secPro.attachObserver(spNBAObserver);
    secPro.attachObserver(spStockObserver);
    
    secPro.Notify();
    
    secPro.removeObserver(spNBAObserver);
    secPro.Notify();
}
