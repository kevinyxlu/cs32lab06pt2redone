#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include "demogData.h"
#include "psData.h"
#include "parse.h"
#include "dataAQ.h"
#include "raceDemogData.h"
#include "stats.h"
#include "visitorCombineCounty.h"
#include "visitorCombineState.h"
#include "statTool.h"


using namespace std;

int main() {
 std::vector<shared_ptr<regionData>> pileOfData;

  //read police shooting data
  read_csv(pileOfData, "police_shootings_cleaned.csv", POLICE);
   
  //read in the demographic data
  read_csv(pileOfData, "county_demographics.csv", DEMOG); 

 //create a visitor to combine the state data
    visitorCombineState theStates;
    statTool::createStateData(pileOfData, theStates);
    theStates.printAllCombo(&demogData::getBelowPovertyCount, &psCombo::getNumberOfCases);

    //create a visitor to combine the county data
    visitorCombineCounty theCounties;
    statTool::createCountyData(pileOfData, theCounties);
    theCounties.printAllCombo(&demogData::getBelowPovertyCount, &psCombo::getNumberOfCases);

    //Do stats work here
    cout << "State data Pop under 5 and BA up: " << endl;
   // statTool::computeStatsDemogRegionData(&theCounties, &demogData::getBelowPoverty, &demogData::getHSup,
  //      &demogData::getBelowPovertyCount, &demogData::getHSupCount);

  //statTool::computeStatsRaceProportion(&theStates,&raceDemogData::getAsianCount,&raceDemogData::getAsianCount);

    return 0;
}

