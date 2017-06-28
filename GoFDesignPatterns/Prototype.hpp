//
//  Prototype.hpp
//  GoFDesignPatterns
//
//  Created by broyant on 2017/6/2.
//  Copyright © 2017年 pwrd. All rights reserved.
//

#ifndef Prototype_hpp
#define Prototype_hpp

#include <iostream>
using namespace std;

class ICloneable
{
public:
    virtual shared_ptr<ICloneable> clone() = 0;
};

class Resume:public ICloneable
{
public:
    Resume(string n,string sex,string age,string time,string company):name(n),sex(sex),age(age),timeRange(time),workCompany(company) {}
    Resume(const Resume&) = default;
    ostream& print(ostream& os) const{
        os<<"name: "<<name<<endl;
        os<<"age: "<<age<<endl;
        os<<"sex: "<<sex<<endl;
        os<<"in year "<<timeRange<<endl;
        os<<"worked in "<<workCompany<<endl;
        return os;
    }
    
    void setTimeRange(string time) {timeRange = time;}
    void setWorkCompany(string company) {workCompany = company;}
    shared_ptr<ICloneable> clone() {return shared_ptr<Resume>(new Resume(*this));}
    
private:
    string name;
    string sex;
    string age;
    
    string timeRange;
    string workCompany;
};

inline ostream& operator<<(ostream& os,const Resume& r)
{
    r.print(os);
    return os;
}

void testPrototypePattern();

#endif /* Prototype_hpp */
