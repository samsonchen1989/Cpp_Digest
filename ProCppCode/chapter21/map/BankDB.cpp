#include "BankDB.h"

bool BankDB::addAccount(const BankAccount& acct)
{
    pair<map<int, BankAccount>::iterator, bool> ret;
    ret = mAccounts.insert(std::make_pair(acct.getAcctNum(), acct));

    return ret.second;
}

void BankDB::deleteAccount(int acctNum)
{
    mAccounts.erase(acctNum);
}

BankAccount& BankDB::findAccount(int acctNum) throw(out_of_range)
{
    map<int, BankAccount>::iterator it = mAccounts.find(acctNum);
    if (it != mAccounts.end()) {
        return (it->second);
    } else {
        throw (out_of_range("No account with that number."));
    }
}

BankAccount& BankDB::findAccount(const string& name) throw(out_of_range)
{
    map<int, BankAccount>::iterator it;
    for (it = mAccounts.begin(); it != mAccounts.end(); ++it) {
        if (it->second.getClientName() == name) {
            return it->second;
        }
    }

    throw (out_of_range("No account with that name."));
}

void BankDB::mergeDatabase(BankDB& db)
{
    mAccounts.insert(db.mAccounts.begin(), db.mAccounts.end());
    db.mAccounts.clear();
}