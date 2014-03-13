#include <set>
#include <string>
#include <list>

using std::set;
using std::string;
using std::list;

class AccessList
{
public:
    AccessList() {}

    //add the user to the permissions list
    void addUser(const string& user);

    //remove the user from the permissions list
    void removeUser(const string& user);

    //returns true if user is in the permissions list
    bool isAllowed(const string& user) const;

    //returns a list of all the users who have permissions
    list<string> getAllUsers() const;

protected:
    set<string> mAllowed;
};