#ifndef VCOMBO_H
#define VCOMBO_H

#include "psData.h"
#include "psCombo.h"
#include "demogData.h"
#include "demogCombo.h"
#include "visitor.h"
#include <memory>
#include <map>

//The shared combo data
class visitorCombine : public Visitor {
public:
    visitorCombine() {}

    //just a helper to print out various fields
    void printAllCombo(int (demogData::*f1)() const, int (psCombo::*f2)() const) {
        //stay tuned may be provided
    }

    shared_ptr<demogCombo> getComboDemogData(string regionName) { return allComboDemogData[regionName]; } //fill in
    shared_ptr<psCombo> getComboPoliceData(string regionName) { return allComboPoliceData[regionName]; } //fill in

	std::map<string, shared_ptr<demogCombo> >& getComboDemog()  { return allComboDemogData; } //fill in
    std::map<string, shared_ptr<psCombo> > & getComboPolice() { return allComboPoliceData; } //fill in

    protected:
    	//combo maps
        std::map<string, shared_ptr<demogCombo> > allComboDemogData;
        std::map<string, shared_ptr<psCombo> > allComboPoliceData;

        //store aggregated data here
};

#endif
