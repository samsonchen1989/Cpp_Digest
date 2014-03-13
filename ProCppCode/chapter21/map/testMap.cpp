#include <map>
#include <iostream>

using namespace std;

class Data
{
public:
    Data(int val = 0) { mVal = val; }
    int getVal() const { return mVal; }
    void setVal(int val) { mVal = val; }

protected:
    int mVal;
};

int main(int argc, char** argv)
{
    map<int, Data> dataMap;
    dataMap[0] = Data(1);
    dataMap[1] = Data(2);
    dataMap[1] = Data(3);

    pair<map<int, Data>::iterator, bool> ret;
    ret = dataMap.insert(make_pair(2, Data(4)));
    if (ret.second) {
        cout << "Insert succeeded!\n";
    } else {
        cout << "Insert failed!\n";
    }

    //if key already exists, insert() will not
    //overwrite and return <key, false>
    ret = dataMap.insert(make_pair(2, Data(5)));
    if (ret.second) {
        cout << "Insert succeeded!\n";
    } else {
        cout << "Insert failed!\n";
    }

    for (map<int, Data>::iterator it = dataMap.begin();
            it != dataMap.end(); ++it) {
        cout << it->first << ":" << it->second.getVal() << endl;
    }

    map<int, Data>::iterator it = dataMap.find(2);
    // Find fails return dataMap.end()
    if (it != dataMap.end()) {
        cout << "Find map, key 2 value:" << it->second.getVal() << endl;
        it->second.setVal(100);
    }

    cout << "After, find map, key 2 value:" << it->second.getVal() << endl;

    return 0;
}