#include <list>
#include <vector>
#include <string>

using namespace std;

list<string> getTotalEnrollment(const vector<list<string> >& classLists,
    const list<string>& droppedStudents)
{
    list<string> allStudents;
    for (size_t i = 0; i < classLists.size(); ++i) {
        allStudents.insert(allStudents.end(), classLists[i].begin(),
            classLists[i].end());
    }

    //sort the master list
    allStudents.sort();

    //remove duplicate student names
    allStudents.unique();

    //remove student who are on the dropped list
    for (list<string>::const_iterator it = droppedStudents.begin();
        it != droppedStudents.end(); ++it) {
        allStudents.remove(*it);
    }

    return (allStudents);
}