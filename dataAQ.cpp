/* aggregate data */
#include "dataAQ.h"
#include "demogData.h"
#include "demogCombo.h"
#include "psData.h"
#include "psCombo.h"
#include "visitorReport.h"

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>


bool compPoliceShootings(const shared_ptr<psCombo> &left, const shared_ptr<psCombo> &right) {
  if (left->getNumberOfCases() > right->getNumberOfCases()) return true;
  return false;
}

bool compPoverty(const shared_ptr<demogCombo> &left, const shared_ptr<demogCombo> &right) {
  if (left->getPopPoverty() > right->getPopPoverty()) return true;
  return false;
}

dataAQ::dataAQ() {}

string makeKeyExample(shared_ptr<demogData> theData) {


  string theKey = "Key";

/*
  if (theData->getBelowPoverty() < 10) {
    theKey += "BelowPovLessTenPer";
  } else if (theData->getBelowPoverty() < 20) {
    theKey += "BelowPovLessTwentyPer";
  } else if (theData->getBelowPoverty() < 30) {
    theKey += "BelowPovLessThirtyPer";
  } else {
    theKey += "BelowPovAboveThirtyPer";
  }
*/
  return theKey;
}


string makeKeyExample(shared_ptr<psData> theData) {

  string theKey = "Key";
  /*
  if (theData->getFleeing() == "Foot") {
    theKey += "FleeingOnFoot";
  } else if (theData->getFleeing() == "Car") {
    theKey += "FleeingByCar";

  } else if (theData->getFleeing() == "Other") {
    theKey += "FleeingOtherMeans";
  } else {
    theKey += "NotFleeing";
  }
  */
  return theKey;
}


//swtich to a function parameter
void dataAQ::createComboDemogDataKey(std::vector<shared_ptr<demogData> >& theData) {

//fill in

}

void dataAQ::createComboPoliceDataKey(std::vector<shared_ptr<psData> >& theData) {
//fill in

}

/******************************************/
/* state examples */
void dataAQ::createComboDemogData(std::vector<shared_ptr<demogData> >&  theData) {
  std::string currentState = theData[0]->getState();
  std::vector<shared_ptr<demogData>> stateCounties;
  for (auto entry : theData) {
    if (entry->getState() != currentState) {
      allComboDemogData.insert(std::make_pair(currentState, std::make_shared<demogCombo>(currentState, stateCounties)));
      stateCounties.clear();
      currentState = entry->getState();
    }
    stateCounties.push_back(entry);
  }

  if (stateCounties.size()) {
    allComboDemogData.insert(std::make_pair(currentState, std::make_shared<demogCombo>(currentState, stateCounties)));
    stateCounties.clear();
  }
}

void dataAQ::createComboPoliceData(std::vector<shared_ptr<psData> >& theData) {
  for (auto entry : theData) {
    std::string currentState = entry->getState();
    if (!allComboPoliceData.count(currentState)) {
      allComboPoliceData.insert(std::make_pair(currentState, std::make_shared<psCombo>(currentState, theData)));
    }
  }
}


//sort and report the top ten states in terms of number of police shootings 
void dataAQ::reportTopTenStatesPS() {
  std::vector<shared_ptr<psCombo>> what;
  for (auto entry : allComboPoliceData) what.push_back(entry.second);
  sort(what.begin(), what.end(), compPoliceShootings);
  std::cout << "Top ten states sorted on Below Poverty data & the associated police shooting data:\n";
  std::cout << std::setprecision(2) << std::fixed;
  for (int i = 0; i < 10; i++) {
    if (what[i]) { //Is a psCombo
      shared_ptr<demogCombo> stateDemog = allComboDemogData[what[i]->getState()];
      std::cout << what[i]->getState() << "\n";
      std::cout << "Total population: " << stateDemog->getPop() << "\n";
      std::cout << "Police shooting incidents: " << what[i]->getNumberOfCases() << "\n";
      std::cout << "Percent below poverty: " << stateDemog->getPopPoverty() << "\n";
    }
  }
}


    //sort and report the top ten states with largest population below poverty 
void dataAQ::reportTopTenStatesBP() {
  std::vector<shared_ptr<demogCombo>> what;
  for (auto entry : allComboDemogData) what.push_back(entry.second);
  sort(what.begin(), what.end(), compPoverty);
  //for (auto entry : what) std::cout << entry->getState() << " " << entry->getPoverty() << "\n";
  std::cout << "Top ten states sorted on Below Poverty data & the associated police shooting data:\n";
  std::cout << std::setprecision(2) << std::fixed;
  for (int i = 0; i < 10; i++) {
    if (what[i]) { //Is a demogCombo
      std::cout << what[i]->getState() << "\n";
      std::cout << "Total population: " << what[i]->getPop() << "\n";
      std::cout << "Percent below poverty: " << what[i]->getPopPoverty() << "\n";
      std::cout << "Police shooting incidents: " << allComboPoliceData[what[i]->getState()]->getNumberOfCases() << "\n";
    }
  }

}

/* print all combo data */
std::ostream& operator<<(std::ostream &out, const dataAQ &theAnswers) {
  /*for (auto entry : theAnswers.allComboDemogData) {
    out << *(entry.second) << "\n";
    out << *(theAnswers.allComboPoliceData.at(entry.first)) << "\n";
  }*/
  
  out << "Combo Demographic Info: ";
  for (auto const& entry : theAnswers.allComboDemogData) {
      out << "key: " << entry.first << endl;
      out << *(entry.second) << "\n";

  }

  for (auto const& entry : theAnswers.allComboPoliceData) {
      out << "key: " << entry.first << endl;
      out << *(entry.second) << "\n";

  }
  return out;
}

void dataAQ::comboReport(double thresh)
{
  visitorReport report;
  std::vector<shared_ptr<regionData>> pileData;

  //vector<string> stateNames;

  string tempStateName; //helper to know which policeData to push to pileData
  for(auto const& x : allComboDemogData)
  {
    tempStateName = x.first;
    if(x.second->getPopHSPlus() > thresh)
    {
      pileData.push_back(x.second);
      pileData.push_back(allComboPoliceData[x.second->getState()]);
      //stateNames.push_back(tempStateName);
    }
  }

/*
  for(auto const& x : allComboPoliceData)
  {
    for(int i = 0; i < stateNames.size(); i++)
    {
      if(x.first == stateNames[i])
      {
        pileData.push_back(x.second);
      }
    }
  }
*/

  for(const auto &obj : pileData) {
    obj->accept(report);
  }
}