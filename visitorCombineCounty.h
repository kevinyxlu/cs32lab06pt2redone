#ifndef VCOMBOC_H
#define VCOMBOC_H

#include "psData.h"
#include "psCombo.h"
#include "demogData.h"
#include "demogCombo.h"
#include "visitorCombine.h"
#include "parse.h"
#include <memory>
#include <fstream>
#include <cassert>

class visitorCombineCounty : public visitorCombine {
public:
    visitorCombineCounty() {
    }

    //store demographic data by county name
	void visit(shared_ptr<demogData> obj) {
        //fill in
        string county = obj->getRegionName();
        if(allComboDemogData.count(county)) // if the state exists in the map already, then aggregate
        {
            allComboDemogData[county]->addDemogData(obj);
        }
        else { allComboDemogData[county] = std::make_shared<demogCombo>(county, obj); } // otherwise, add the state data
    }
    
    //aggregate police shooting data by county
    void visit(shared_ptr<psData> obj) {
        string county = obj->getRegionName();
        if(allComboPoliceData.count(county)) // if the state exists in the map already, then aggregate
        {
            allComboPoliceData[county]->addPSData(obj);
        }
        else { allComboPoliceData[county] = std::make_shared<psCombo>(county, obj); }
    }

    private:
        //only inherited data at this point
};

#endif
