#include "demogData.h"
#include <sstream>
#include <iomanip>

demogData::demogData(string inN, string inS, double in65, double in18, double in5, double inBach, double inHigh, double inPov, int totPop14,
double in1stNation, double inAsian, double inBlack, double inLatinx, double inHIPacificIsle, double inMultiRace, double inWhite, double inWhiteNH) : 
regionData(inN, inS, totPop14), popOver65(in65), popUnder18(in18), popUnder5(in5), popBachelorEduPlus(inBach), popHighSchoolEduPlus(inHigh), popInPoverty(inPov) {
    raceData.addFirstNationCount((in1stNation / 100 * population));
    raceData.addAsianCount((inAsian / 100 * population));
    raceData.addBlackCount((inBlack / 100 * population));
    raceData.addLatinxCount((inLatinx / 100 * population));
    raceData.addHIPacificIsleCount((inHIPacificIsle / 100 * population));
    raceData.addMultiRaceCount((inMultiRace / 100 * population));
    raceData.addWhiteCount((inWhite / 100 * population));
    raceData.addWhiteNHCount((inWhiteNH / 100 * population));
    raceData.addCommunityCount(totPop14);
}

std::ostream& operator<<(std::ostream &out, const demogData &DD) {
    out << "County Demographics Info: " << DD.getRegionName() << ", " << DD.getState();
    out << std::setprecision(2) << std::fixed;
    out << "\nPopulation info: \n(\% over 65): " << DD.popOver65 << " Count: " << DD.getCountOver65();
    out << "\n(\% under 18): " << DD.popUnder18 << " Count: " << DD.getCountUnder18();
    out << "\n(\% under 5): " << DD.popUnder5 << " Count: " << DD.getCountUnder5();
    out << "\nEducation info: ";
    out << "\n(% Bachelor degree or more): " << DD.popBachelorEduPlus << " Count: " << DD.getCountBAPlus();
    out << "\n(% high school or more): " << DD.popHighSchoolEduPlus << " Count: " << DD.getCountHSPlus();
    out << "\npersons below poverty: " << DD.popInPoverty << " Count: " << DD.getCountPoverty();
    return out;
}
