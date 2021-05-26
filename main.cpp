#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include "demogData.h"
#include "psData.h"
#include "parse.h"
#include "dataAQ.h"

using namespace std;

int main() {
    /*//Deboog output
    ofstream myfile;
    myfile.open("output.txt");*/
    //dataAQ theAnswers;

    // create one large shared vector of raw data
    vector<shared_ptr<regionData>> pileOfData;

    // read in the police data
    read_csv(pileOfData, "police_shootings_cleaned.csv", POLICE);

    // read in the demographic data
    read_csv(pileOfData, "county_demographics.csv", DEMOG);
    
    /*//Deboog print 
    for (auto obj : theDemogData) {
        myfile << *dynamic_pointer_cast<demogData>(obj) << std::endl;
    }
    for (auto obj : thePoliceData) {
        myfile << *dynamic_pointer_cast<psData>(obj) << std::endl;
    }
    */


/*


    std::vector<shared_ptr<demogData>> castedDemogData;
    std::vector<shared_ptr<psData>> castedPoliceData;
    for (auto entry : theDemogData) {
        castedDemogData.push_back(static_pointer_cast<demogData>(entry));
    }
    for (auto entry : thePoliceData) {
        castedPoliceData.push_back(static_pointer_cast<psData>(entry));
    }
    theAnswers.createComboDemogData(castedDemogData);
    theAnswers.createComboPoliceData(castedPoliceData);
    //cout << theAnswers << endl;

    theAnswers.comboReport(92);


*/




    //myfile.close();
    /*
    cout << "*** the state that needs the most pre-schools**" << endl;
    string needPK = theAnswers.youngestPop();
    cout << *(theAnswers.getStateData(needPK)) << endl;
    cout << "*** the state that needs the most high schools**" << endl;
    string needHS = theAnswers.teenPop();
    cout << *(theAnswers.getStateData(needHS)) << endl;
    cout << "*** the state that needs the most vaccines**" << endl;
    string needV = theAnswers.wisePop();
    cout << *(theAnswers.getStateData(needV)) << endl;

    cout << "*** the state that needs the most help with education**" << endl;
    string noHS = theAnswers.underServeHS();
    cout << *(theAnswers.getStateData(noHS)) << endl;
    cout << "*** the state with most college grads**" << endl;
    string grads = theAnswers.collegeGrads();
    cout << *(theAnswers.getStateData(grads)) << endl;

    cout << "*** the state with most population below the poverty line**" << endl;
    string belowPov = theAnswers.belowPoverty();
    cout << *(theAnswers.getStateData(belowPov)) << endl;
    */
    return 0;
}

