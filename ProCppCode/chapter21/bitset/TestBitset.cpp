#include "CableCompany.h"
#include <iostream>
using namespace std;

int main(int argc, char**argv)
{
    CableCompany myCC;

    string basic_pkg = "1111000000";
    string premium_pkg = "1111111111";
    string sport_pkg = "0000100111";

    myCC.addPackage("basic", bitset<kNumChannels>(basic_pkg));
    myCC.addPackage("premium", bitset<kNumChannels>(premium_pkg));
    myCC.addPackage("sports", bitset<kNumChannels>(sport_pkg));

    myCC.newCustomer("HanMeiMei", "basic");
    myCC.addPackageToCustomer("HanMeiMei", "sports");
    cout << myCC.getCustomerChannels("HanMeiMei") << endl;

    return 0;
}