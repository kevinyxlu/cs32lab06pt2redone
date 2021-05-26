#ifndef POLICE_H
#define POLICE_H

#include "regionData.h"
#include "visitor.h"
#include <string>
#include <iostream>
#include <utility>


using namespace std;

/*
  class to represent police shooting data
  from CORGIS
*/
class psData : public regionData, public std::enable_shared_from_this<psData> {
  public:
    //add appropriate function paramaters to constructor once you add data
    psData(string inName, int inAge, char inGender, char inRace, string inCounty, string inState, bool inMIllness, string inFlee) : 
    regionData(inCounty, inState), name(inName), age(inAge), gender(inGender), race(inRace), signs_of_mental_illness(inMIllness), flee(inFlee) {}

    //add getters
    string getName() const { return name; }
    int getAge() const { return age; }
    char getGender() const { return gender; }
    char getRace() const { return race; }
    bool getSignsMIll() const { return signs_of_mental_illness; }
    string getFlee() const { return flee; }

    void toString(ostream& os) const {}
    friend std::ostream& operator<<(std::ostream &out, const psData &PD);

    void accept(Visitor &v){
        v.visit(shared_from_this());
    }

private:
    const string name;
    const int age;
    const char gender;
    const char race;
    const bool signs_of_mental_illness;
    const string flee;
};

#endif
