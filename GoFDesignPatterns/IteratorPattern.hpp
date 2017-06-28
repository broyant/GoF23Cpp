//
//  IteratorPattern.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/6.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef IteratorPattern_hpp
#define IteratorPattern_hpp

#include <iostream>

using namespace std;

//abstract iterator
template <typename T>
class IIterator {
public:
    virtual ~IIterator() = default;
    virtual T next() = 0;
    virtual bool hasNext() = 0;
};

//interface for collection
template <typename T>
class ICollection {
public:
    virtual ~ICollection() = default;
    virtual auto_ptr<IIterator<T>> getIterator() = 0;
};

template <typename T>
class ConcreteIterator;

template <typename T>
class ConcreteCollection {
public:
    ConcreteCollection():current(0){innerData = new T[10];}
    ~ConcreteCollection() {delete[] innerData;}
    void push_back(T item) {innerData[current++] = item;}
    T getItem(size_t idx) {return innerData[idx];}
    size_t getSize() {return current;}
    auto_ptr<IIterator<T>> getIterator() {
        return auto_ptr<IIterator<T>>(new ConcreteIterator<T>(this));
    }
private:
    size_t current;
    T* innerData;
};

template <typename T>
class ConcreteIterator:public IIterator<T>
{
public:
    ConcreteIterator(ConcreteCollection<T> *iterable):current(0)
    {pCollection = dynamic_cast<ConcreteCollection<T> *>(iterable);}
    
    bool hasNext() {
        if(pCollection->getSize()==0){return false;}
        if(current<pCollection->getSize()){return true;}
        else {return false;}
    }
    
    T next()
    {
        return pCollection->getItem(current++);
    }
private:
    size_t current;
    ConcreteCollection<T> *pCollection;
};

void testIteratorPattern();

#endif /* IteratorPattern_hpp */
