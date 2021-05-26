#include <iomanip>
#include "psCombo.h"

psCombo::psCombo(string inS, vector<shared_ptr<psData>> inPSData) : regionData(inS, inS) {
    int whiteCount = 0;
    for (auto entry : inPSData) {
        if (entry->getState() == inS) {
            if (entry->getSignsMIll()) numMentalIllness++;
            if (entry->getFlee() != "Not fleeing" && entry->getFlee().length()) fleeingCount++;
            if (entry->getAge() >= 65) casesOver65++;
            else if (entry->getAge() <= 18) casesUnder18++;
            if (entry->getGender() == 'M') numMales++;
            else if (entry->getGender() == 'F') numFemales++;
            
            if(entry->getRace() != '\0' && entry->getRace() != ')')
            {
                if (entry->getRace() == 'W') { 
                    racialData.addWhiteCount(1);
                    racialData.addWhiteNHCount(1);
                    whiteCount = whiteCount + 1;
                }
                else if (entry->getRace() == 'A') racialData.addAsianCount(1);
                else if (entry->getRace() == 'B') racialData.addBlackCount(1);
                else if (entry->getRace() == 'H') racialData.addLatinxCount(1);
                else if (entry->getRace() == 'N') racialData.addFirstNationCount(1);
                else racialData.addOtherCount(1);
                numCases++;
            }
        }
    }
    racialData.addCommunityCount(numCases + whiteCount);
}

psCombo::psCombo(string inS, shared_ptr<psData> inPSData) : regionData(inS, inS)
{
        if (inPSData->getState() == inS) {
            if (inPSData->getSignsMIll()) numMentalIllness++;
            if (inPSData->getFlee() != "Not fleeing" && inPSData->getFlee().length()) fleeingCount++;
            if (inPSData->getAge() >= 65) casesOver65++;
            else if (inPSData->getAge() <= 18) casesUnder18++;
            if (inPSData->getGender() == 'M') numMales++;
            else if (inPSData->getGender() == 'F') numFemales++;
            
            if(inPSData->getRace() != '\0' && inPSData->getRace() != ')')
            {
                if (inPSData->getRace() == 'W') { 
                    racialData.addWhiteCount(1);
                    racialData.addWhiteNHCount(1);
                }
                else if (inPSData->getRace() == 'A') racialData.addAsianCount(1);
                else if (inPSData->getRace() == 'B') racialData.addBlackCount(1);
                else if (inPSData->getRace() == 'H') racialData.addLatinxCount(1);
                else if (inPSData->getRace() == 'N') racialData.addFirstNationCount(1);
                else racialData.addOtherCount(1);
                numCases++;
            }
        }
}

// function add data to psCombo
void psCombo::addPSData(shared_ptr<psData> obj)
{
    if(obj->getSignsMIll()) {numMentalIllness = numMentalIllness + 1;}
    if(obj->getFlee() != "Not fleeing" && obj->getFlee().length()) { fleeingCount = fleeingCount + 1; }
    if(obj->getAge() >= 65) {casesOver65 = casesOver65 + 1;}
    if(obj->getAge() <= 18) {casesUnder18 = casesUnder18 + 1;}
    if (obj->getGender() == 'M') {numMales = numMales + 1;}
    if (obj->getGender() == 'F') {numFemales = numFemales + 1;}
    numCases = numCases + 1;
}

/* print state data - as aggregate of all incidents in this state */
std::ostream& operator<<(std::ostream &out, const psCombo& PD) {
    out << "State Info: " << PD.printState();
    out << "\nNumber of incidents: " << PD.getNumberOfCases();
    out << std::setprecision(2) << std::fixed;
    out << "\nIncidents with age \n(over 65): " << PD.getCasesOver65();
    out << "\n(19 to 64): " << PD.getNumberOfCases() - PD.getCasesOver65() - PD.getCasesUnder18();
    out << "\n(under 18): " << PD.getCasesUnder18();
    out << "\nIncidents involving fleeing: " << PD.getFleeingCount();
    out << "\nIncidents involving mental illness: " << PD.getNumMentalI();
    out << "\nMale incidents: " <<  PD.getnumMales() << " female incidents: " << PD.getnumFemales();
    out << "\nRacial demographics of state incidents: " << PD.getRacialData();
    return out;
}