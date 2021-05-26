

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "demogData.h"
#include "parse.h"
#include "regionData.h"
#include "visitorCombineState.h"
#include "visitorCombineCounty.h"
#include "stats.h"
#include "statTool.h"
#include "tddFuncs.h"
using namespace std;

int main() {


  cout << "Testing stats on Data" << endl;

  std::vector<shared_ptr<regionData>> pileOfData;

  //read police shooting data
  read_csv(pileOfData, "police_shootings_cleaned.csv", POLICE);
   
  //read in the demographic data
  read_csv(pileOfData, "county_demographics.csv", DEMOG); 

  //create a visitor to combine the state data
    visitorCombineState theStates;
    //create the state demographic data
    statTool::createStateData(pileOfData, theStates);

    //create a visitor to combine the county data (need aux map city-> county)
    visitorCombineCounty theCounties;
    statTool::createCountyData(pileOfData, theCounties);

  //use the counts to compute mean
  vector<double> dataXcount;
  vector<double> dataYcount;
  //compute stdDev of percent (against percent mean - adjusted in function)
  vector<double> dataXpercent;
  vector<double> dataYpercent;
  int totPop = 0; // FIXME: this total population number is not right
  for (auto entry : theStates.getComboDemog()) { 
    dataYcount.push_back(entry.second->getCountPoverty());
    dataXcount.push_back(entry.second->getCountHSPlus());
    totPop += entry.second->getPop(); 
    dataYpercent.push_back(entry.second->getBelowPoverty());
    dataXpercent.push_back(entry.second->getPopHSPlus());
  }

 // cout << totPop; // for debugging

  double mX = stats::computePopMean(dataXcount, totPop); 
  double mY = stats::computePopMean(dataYcount, totPop); 
  double stdDevX = stats::computeStdDevPop(dataXpercent, mX);
  double stdDevY = stats::computeStdDevPop(dataYpercent, mY);

  ASSERT_EQUALS(mX, 0.859);
  ASSERT_EQUALS(stdDevX, 3.591);
  ASSERT_EQUALS(mY, 0.154);
  ASSERT_EQUALS(stdDevY, 3.177);
  

/*
  ASSERT_EQUALS(0.859, 0.859);
  ASSERT_EQUALS(3.591, 3.591);
  ASSERT_EQUALS(0.154, 0.154);
  ASSERT_EQUALS(3.177, 3.177);
*/

  return 0;
}
