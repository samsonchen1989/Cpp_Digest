#include <map>
#include <string>
#include <stdexcept>

using std::map;
using std::string;
using std::pair;
using std::out_of_range;

class BankAccount
{
public:
    BankAccount(int acctNum, const string& name) :
        mAcctNum(acctNum), mClientName(name) {}

    void setAcctNum(int acctNum) { mAcctNum = acctNum; }
    int getAcctNum() const { return mAcctNum; }
    void setClientName(const string& name) { mClientName = name; }
    string getClientName() const { return mClientName; }

protected:
    int mAcctNum;
    string mClientName;
};

class BankDB
{
public:
    BankDB() {}

    //add acct to the bank database. If an account
    //exists already with that number, the new account is
    //not added. Return true if the account is added, false
    // if it's not
    bool addAccount(const BankAccount& acct);

    //remove the account acctNum from database
    void deleteAccount(int acctNum);

    BankAccount& findAccount(int acctNum) throw(out_of_range);
    BankAccount& findAccount(const string& name) throw(out_of_range);

    //add all the accounts from db to this db.
    //remove all accounts in db
    void mergeDatabase(BankDB& db);

protected:
    map<int, BankAccount> mAccounts;
};