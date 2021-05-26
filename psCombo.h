#ifndef POLICECOMBODATA_H
#define POLICECOMBODATA_H

#include "raceDemogData.h"
#include "psData.h"
#include "regionData.h"
#include "visitor.h"
#include <memory>
#include <cassert>

using namespace std;

class psCombo : public regionData  {
public:
    //write psCombo constructor
    psCombo(string inS, vector<shared_ptr<psData>> inPSData);
    psCombo(string inS, shared_ptr<psData> inPSData);

    void addPSData(shared_ptr<psData> obj);

    //complete these
    int getNumMentalI() const { return numMentalIllness; }
    int getFleeingCount() const { return fleeingCount; }
    int getCasesOver65() const { return casesOver65; }
    int getCasesUnder18() const { return casesUnder18; }
    raceDemogData getRacialData() const { return racialData; }
    int getnumMales() const { return numMales; }
    int getnumFemales() const { return numFemales; }
    int getNumberOfCases() const { return numCases; }

    void toString(ostream& os) const {};
    friend std::ostream& operator<<(std::ostream &out, const psCombo& PD);

    void accept(Visitor &v){
        // v.visit(this);
    }

protected:
    string state;
    int numMentalIllness = 0;
    int fleeingCount = 0;
    int casesOver65 = 0;
    int casesUnder18 = 0;
    int numMales = 0;
    int numFemales = 0;
    int numCases = 0;

    raceDemogData racialData;
};

#endif