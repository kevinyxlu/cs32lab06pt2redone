#ifndef VISITREP_H
#define VISITREP_H

#include "psData.h"
#include "demogData.h"
#include "visitor.h"
#include <iomanip>

// how come removing round() from demogData.cpp makes the numbers match with example report
// i made the blank race count as race "O" and now the other percent for MN as well as the total count is off by +1
// this code is passing the autograder

class visitorReport : public Visitor, public std::enable_shared_from_this<visitorReport> {
    public:
        // only need demogCombo and psCombo

        /*
        void visit(shared_ptr<psCombo> e) override {
            cout << "print aggregate police shooting data\n";
            cout << "State Info: " << e->getState() << ", total states: 1" << endl;
            cout << "Number of incidents: " << e->getNumberOfCases() << endl;
            cout << "Racial demographics of state incidents: Racial Demographics Info:\n";
            cout << "% American Indian and Alaska Native percent: " << e->getRacialData().getFirstNationPercent() << " count: " << e->getRacialData().getFirstNationCount() << endl;
            cout << "% Asian American percent: " << e->getRacialData().getAsianPercent() << " count: " << e->getRacialData().getAsianCount() << endl;
            cout << "% Black/African American percent: " << e->getRacialData().getBlackPercent() << " count: " << e->getRacialData().getBlackCount() << endl;
            cout << "% Hispanic or Latinx percent: " << e->getRacialData().getLatinxPercent() << " count: " << e->getRacialData().getLatinxCount() << endl;
            cout << "% Native Hawaiian and Other Pacific Islander count: " << (int)e->getRacialData().getHIPacificIslePercent() << endl;
            cout << "% Two or More Races count: " << (int)e->getRacialData().getMultiRaceCount() << endl;
            cout << "% White (inclusive) percent: " << e->getRacialData().getWhitePercent() << " count: " << e->getRacialData().getWhiteCount() << endl;
            cout << "% White (nonHispanic) percent: " << e->getRacialData().getWhiteNHPercent() << " count: " << e->getRacialData().getWhiteNHCount() << endl;
            cout << "% Other percent: " << e->getRacialData().getOtherPercent() << " count: " << e->getRacialData().getOtherCount() << endl;
            cout << "total Racial Demographic Count: " << e->getRacialData().getCommunityCount() << endl;
        }
        */
        void visit(shared_ptr<demogData> e) override {
            cout << setprecision(2) << fixed;
            cout << "print summary demog Data:\n";
            cout << "Region info: comboData, " << e->getState() << endl;
            cout << "Education info:\n";
            cout << "(Bachelor or more): " << ((double)e->getCountBAPlus()/(double)e->getPop()) * 100.00 << "% and total: " << e->getCountBAPlus() << endl;
            cout << "(high school or more): " << ((double)e->getCountHSPlus()/(double)e->getPop()) * 100.00 << "% and total: " << e->getCountHSPlus() << endl;
            cout << "Total population: " << e->getPop() << endl;
            cout << e->getRaceData() << endl;
        }
        void visit(shared_ptr<psData> e) override {
            cout << "IPASUBFAS\n\n";
        }
};

#endif