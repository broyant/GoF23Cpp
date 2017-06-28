//
//  IteratorAgain.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/8.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef IteratorAgain_hpp
#define IteratorAgain_hpp

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class AbsIterator {
public:
    virtual ~AbsIterator() {cout<<"Destruction Iterator"<<endl;};
    virtual T& next() = 0;
    virtual bool has_next() = 0;
};



template <typename T>
class AbsCollection {
public:
    virtual ~AbsCollection() = default;
    virtual shared_ptr<AbsIterator<T>> getIterator() = 0;
};

template <typename T>
class PositiveSeqIterator;

template <typename T>
class NegativeSeqIterator;

template <typename T>
class VectorCollection:public AbsCollection<T> {
public:
    shared_ptr<AbsIterator<T>> getIterator()
    {
        //return shared_ptr<AbsIterator<T>> (new PositiveSeqIterator<T> (this) );
        return shared_ptr<AbsIterator<T>> (new NegativeSeqIterator<T> (this) );
    }
    void addItem(T item) {innerData.push_back(item);}
    size_t size() const {return innerData.size();}
    T& getItem(size_t idx) {return innerData[idx];}
    ~VectorCollection() {cout<<"Destruction Vector Collection!"<<endl;}
private:
    vector<T> innerData;
};

template <typename T>
class PositiveSeqIterator:public AbsIterator<T> {
public:
    PositiveSeqIterator(AbsCollection<T> *pc):pCollection(pc),current(0){}
    T& next();
    bool has_next();
private:
    AbsCollection<T> *pCollection;
    size_t current;
};

template <typename T>
T& PositiveSeqIterator<T>::next()
{
    VectorCollection<T> *pVC = dynamic_cast<VectorCollection<T>* >(pCollection);
    return pVC->getItem(current++);
}

template <typename T>
bool PositiveSeqIterator<T>::has_next() {
    VectorCollection<T> *pVC = dynamic_cast<VectorCollection<T>* >(pCollection);
    return current<pVC->size();
}

template <typename T>
class NegativeSeqIterator:public AbsIterator<T> {
public:
    NegativeSeqIterator(VectorCollection<T> *pvc):pCollection(pvc),current(pvc->size()){}
    T& next() {return pCollection->getItem(--current);}
    bool has_next() {return current>0;}
private:
    VectorCollection<T> *pCollection;
    size_t current;
};

void testIteratorPatternWithSmartPointer();

#endif /* IteratorAgain_hpp */
