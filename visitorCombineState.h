#ifndef VCOMBOS_H
#define VCOMBOS_H


#include "visitorCombine.h"
#include <memory>

class visitorCombineState : public visitorCombine {
public:
    visitorCombineState() {}

    //function to aggregate state demog data
	void visit(shared_ptr<demogData> obj) {
        string state = obj->getState();
        if(allComboDemogData.count(state)) // if the state exists in the map already, then aggregate
        {
            allComboDemogData[state]->addDemogData(obj);
        }
        else { allComboDemogData[state] = std::make_shared<demogCombo>(state, obj); } // otherwise, add the state data
    }
    
    // function to aggregate state police shooting data
    void visit(shared_ptr<psData> obj) {
        string state = obj->getState();
        if(allComboPoliceData.count(state)) // if the state exists in the map already, then aggregate
        {
            allComboPoliceData[state]->addPSData(obj);
        }
        else { allComboPoliceData[state] = std::make_shared<psCombo>(state, obj); } // otherwise, create new state data
    }

    private:
       //inherited
};

#endif
