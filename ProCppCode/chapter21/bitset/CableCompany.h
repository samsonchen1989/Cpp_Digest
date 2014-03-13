#include <bitset>
#include <map>
#include <string>
#include <stdexcept>

using std::map;
using std::bitset;
using std::string;
using std::out_of_range;

const int kNumChannels = 10;

class CableCompany
{
public:
    CableCompany() {}

    void addPackage(const string& packageName,
        const bitset<kNumChannels>& channels);
    void removePackage(const string& packagename);

    void newCustomer(const string& name, const string& package)
        throw (out_of_range);

    void newCustomer(const string& name, const bitset<kNumChannels>& channels);

    void addChannel(const string& name, int channel);

    void removeChannel(const string& name, int channel);

    void addPackageToCustomer(const string& name, const string& package);

    void deleteCustomer(const string& name);

    bitset<kNumChannels>& getCustomerChannels(const string& name)
        throw (out_of_range);

protected:
    typedef map<string, bitset<kNumChannels> > MapType;
    MapType mPackages, mCustomers;
};