#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVector(const vector<T>& vec)
{
    //add typename here to declare it as a
    //variable to vector<T>::const_iterator
    typename vector<T>::const_iterator it; 
    for (it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }

    cout << endl;
}

int main(int argc, char** argv)
{
    int i;
    vector<int> vectorOne, vectorTwo;

    vectorOne.push_back(1);
    vectorOne.push_back(2);
    vectorOne.push_back(3);
    vectorOne.push_back(5);

    //Insert it in the correct place
    vectorOne.insert(vectorOne.begin() + 3, 4);

    for (i = 6; i <= 10; i++) {
        vectorTwo.push_back(i);
    }

    printVector(vectorOne);
    printVector(vectorTwo);

    vectorOne.insert(vectorOne.end(), vectorTwo.begin(), vectorTwo.end());

    printVector(vectorOne);

    vectorTwo.clear();
    vectorTwo.insert(vectorTwo.begin(), 10, 100);
    vectorTwo.pop_back();

    vectorOne.erase(vectorOne.begin() + 1, vectorOne.begin() + 5);
    printVector(vectorOne);
    printVector(vectorTwo);

    return 0;
}