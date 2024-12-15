#include <iostream>
#include <list>
#include <unordered_set>
using namespace std;

list<int> intersection(const list<int>& setA, const list<int>& setB) {
    unordered_set<int> elements(setA.begin(), setA.end());
    list<int> result;

    for (int student : setB) {
        if (elements.find(student) != elements.end()) {
            result.push_back(student);
        }
    }
    return result;
}

list<int> unionSet(const list<int>& setA, const list<int>& setB) {
    unordered_set<int> elements(setA.begin(), setA.end());
    list<int> result(setA.begin(), setA.end());

    for (int student : setB) {
        if (elements.find(student) == elements.end()) {
            result.push_back(student);
        }
    }
    return result;
}

list<int> symmetricDifference(const list<int>& setA, const list<int>& setB) {
    unordered_set<int> setAElements(setA.begin(), setA.end());
    unordered_set<int> setBElements(setB.begin(), setB.end());
    list<int> result;

    for (int student : setA) {
        if (setBElements.find(student) == setBElements.end()) {
            result.push_back(student);
        }
    }
    for (int student : setB) {
        if (setAElements.find(student) == setAElements.end()) {
            result.push_back(student);
        }
    }
    return result;
}

list<int> neither(const list<int>& allStudents, const list<int>& setA, const list<int>& setB) {
    unordered_set<int> unionAB(unionSet(setA, setB).begin(), unionSet(setA, setB).end());
    list<int> result;

    for (int student : allStudents) {
        if (unionAB.find(student) == unionAB.end()) {
            result.push_back(student);
        }
    }
    return result;
}

void displayList(const list<int>& lst) {
    for (int student : lst) {
        cout << student << " ";
    }
    cout << endl;
}

int main() {
    list<int> allStudents = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int> vanillaLovers = {1, 2, 3, 4, 5};
    list<int> butterscotchLovers = {4, 5, 6, 7}; 

    list<int> both = intersection(vanillaLovers, butterscotchLovers);
    cout << "Students who like both vanilla and butterscotch: ";
    displayList(both);

    list<int> eitherNotBoth = symmetricDifference(vanillaLovers, butterscotchLovers);
    cout << "Students who like either vanilla or butterscotch but not both: ";
    displayList(eitherNotBoth);

    list<int> neitherGroup = neither(allStudents, vanillaLovers, butterscotchLovers);
    cout << "Students who like neither vanilla nor butterscotch: ";
    displayList(neitherGroup);

    return 0;
}
