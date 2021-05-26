#include "demogCombo.h"
#include "demogData.h"
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>

//add member functions here
demogCombo::demogCombo(string inS, std::vector<shared_ptr<demogData>> inDemogData) : demogData(inS, inS) {
    numData = inDemogData.size();

    for (auto entry : inDemogData) {
        setPop(population + entry->getPop());
        countOver65 += entry->getCountOver65();
        countUnder18 += entry->getCountUnder18();
        countUnder5 += entry->getCountUnder5();
        countBAPlus += entry->getCountBAPlus();
        countHSPlus += entry->getCountHSPlus();
        countPoverty += entry->getCountPoverty();
        raceData += entry->getRaceData();

        popOver65 = (countOver65 / double(population)) * 100; 
        popUnder18 = (countUnder18 / double(population)) * 100; 
        popUnder5 = (countUnder5 / double(population)) * 100; 
        popBachelorEduPlus = (countBAPlus / double(population)) * 100; 
        popHighSchoolEduPlus = (countHSPlus / double(population)) * 100; 
        popInPoverty = (countPoverty / double(population)) * 100; 
    }
}

demogCombo::demogCombo(string inS, shared_ptr<demogData> inDemogData) : demogData(inS, inS)
{
    numData = 1; //set number of counties to 1
    setPop(population + inDemogData->getPop());
    countOver65 += inDemogData->getCountOver65();
    countUnder18 += inDemogData->getCountUnder18();
    countUnder5 += inDemogData->getCountUnder5();
    countBAPlus += inDemogData->getCountBAPlus();
    countHSPlus += inDemogData->getCountHSPlus();
    countPoverty += inDemogData->getCountPoverty();
    raceData += inDemogData->getRaceData();
    
    popOver65 = (countOver65 / double(population)) * 100; 
    popUnder18 = (countUnder18 / double(population)) * 100; 
    popUnder5 = (countUnder5 / double(population)) * 100; 
    popBachelorEduPlus = (countBAPlus / double(population)) * 100; 
    popHighSchoolEduPlus = (countHSPlus / double(population)) * 100; 
    popInPoverty = (countPoverty / double(population)) * 100; 
}

// function add more demogData and combine the two
void demogCombo::addDemogData(shared_ptr<demogData> obj)
{
    numData = numData + 1;
    countOver65 = countOver65 + obj->getCountOver65();
    countUnder18 = countUnder18 + obj->getCountUnder18();
    countUnder5 = countUnder5 + obj->getCountUnder5();
    countBAPlus = countBAPlus + obj->getCountBAPlus();
    countHSPlus = countHSPlus + obj->getCountHSPlus();
    countPoverty = countPoverty + obj->getCountPoverty();
    population = population + obj->getPop();
}


/* print state data - as aggregate of all the county data */
std::ostream& operator<<(std::ostream &out, const demogCombo& ComboD) {
    out << std::setprecision(2) << std::fixed;
    out << "State Demographic Info: State Info: " << ComboD.getState() << endl; 
    out << "Number of Counties: " << ComboD.numData << endl; 
    out << "Population Info:\n";
    out << "(over 65): " << ComboD.popOver65 << "% and total: " << ComboD.countOver65 << endl;
    out << "(under 18): " << ComboD.popUnder18 << "% and total: " << ComboD.countUnder18 << endl; 
    out << "(under 5): " << ComboD.popUnder5 << "% and total: " << ComboD.countUnder5 << endl; 
    out << "Education info:\n"; 
    out << "(Bachelor or more): " << ComboD.popBachelorEduPlus << "% and total: " << ComboD.countBAPlus << endl; 
    out << "(high school or more): " << ComboD.popHighSchoolEduPlus << "% and total: " << ComboD.countHSPlus << endl;
    out << "persons below poverty: " << ComboD.popInPoverty << "% and total: " << ComboD.countPoverty << endl;
    
    out << "community racial demographics: ";
    out << ComboD.raceData << endl;
    out << "Total population: " << ComboD.population;
    return out;
}
