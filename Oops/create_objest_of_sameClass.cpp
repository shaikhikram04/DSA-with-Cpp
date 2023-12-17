#include <iostream>
using namespace std;

class Animal {
public:
    Animal() {
        cout << "PAPA...PAPA...PAPAAA.." << endl;
    } 
    Animal *BD = nullptr;

    //* Recursion Occur
    //! Animal *BD = new Animal();
     
};

int main() {
    Animal *RK = new Animal();

    return 0;
}