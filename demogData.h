#ifndef DEMOG_H
#define DEMOG_H

#include "regionData.h"
#include "raceDemogData.h"
#include "visitor.h"
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class demogData : public regionData, public std::enable_shared_from_this<demogData> {
  public:
    demogData(string inN, string inS)
    : regionData(inN, inS), popOver65(0), popUnder18(0), popUnder5(0), popBachelorEduPlus(0), popHighSchoolEduPlus(0), popInPoverty(0) {}
    
    demogData(string inN, string inS, double in65, double in18, double in5, double inBach, double inHigh, double inPov, int totPop14,
    double in1stNation, double inAsian, double inBlack, double inLatinx, double inHIPacificIsle, double inMultiRace, double inWhite, double inWhiteNH);
    
    //returns counts for the demogData
    virtual int getCountOver65() const { return round(popOver65 / 100 * population); }
    virtual int getCountUnder18() const { return round(popUnder18 / 100 * population); }
    virtual int getCountUnder5() const { return round(popUnder5 / 100 * population); }
    virtual int getCountBAPlus() const { return round(popBachelorEduPlus / 100 * population); }
    virtual int getCountHSPlus() const { return round(popHighSchoolEduPlus / 100 * population); }
    virtual int getCountPoverty() const { return round(popInPoverty / 100 * population); }
    raceDemogData getRaceData() const { return raceData; }

    //same functions, different names as above (to satisfy autograder)
    double getpopUnder5() const { return popUnder5; }
    double getBAup() const { return popBachelorEduPlus; }
    int getpopUnder5Count() const { return round(popUnder5 / 100 * population); }
    int getBAupCount() const { return round(popBachelorEduPlus / 100 * population); }
    int getBelowPovertyCount() const { return round(popInPoverty / 100 * population); }


    void toString(ostream& os) const {}
    friend std::ostream& operator<<(std::ostream &out, const demogData &DD);

    void accept(Visitor &v){
        v.visit(shared_from_this());
    }

protected:
    double popOver65;
    double popUnder18;
    double popUnder5;
    double popBachelorEduPlus;
    double popHighSchoolEduPlus;
    double popInPoverty;
    raceDemogData raceData;
};
#endif
