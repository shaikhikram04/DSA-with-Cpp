#include <iostream>
using namespace std;

class Animal{
public:
    int age;
    int weight;
};

// single inheritance
class Dog : public Animal{
public:
    void bark(){
        cout << "Dog barking" << endl;
    }
};