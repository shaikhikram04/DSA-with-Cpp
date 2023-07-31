#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main() {

    // creation 
    unordered_map <string, int> um;

// insertion

        // method 1 : 
    pair<string, int> p = make_pair("Shaikh", 4);
    um.insert(p);

        // method 2:
    um.insert({"I'm", 1});

        // method 3:
    um["Ikram"] = 2;

    // can we insert "Shaikh" again?
    um["Shaikh"] = 3;

    // here Shaikh is not a new inserted key
    // it only update from value 4 to 3. Now key "Shaikh"  value is 3
    // In Map there is an all unique key

// Searching
    cout << "value of Ikram -> " << um["Ikram"] << endl;
    cout << "value of Shaikh -> " << um.at("Shaikh") << endl;

    // what happen when we try to access non-exist key ?
        // using at method
    // cout << "try to access non-exist key -> " << um.at("Unknown") << endl;

        // using [] method
    cout << "try to access non-exist key -> " << um["Unknown"] << endl;
    cout << "try to access non-exist key -> " << um.at("Unknown") << endl;

// size
    cout << "size -> " << um.size() << endl;
    // now size is 4 because "unknown is also inserted"

// check presence
    cout << "is bro present -> " << um.count("bro") << endl;

// delete
    cout << "is present -> " << um.erase("Unknown") << endl;
    cout << "size after erase -> " << um.size() << endl;

// printing
        // iterator that point to the key
    unordered_map<string, int> :: iterator it = um.begin();
    cout << endl;
    while (it != um.end()) {
        cout << (*it).first << " -> " << (*it).second << endl;
        it++;
    }
    cout << endl;

    for (auto i : um) {
        cout << i.first << " -> " << i.second << endl;
    }



    return 0;
}