#include <iostream>
using namespace std;

class Animal{
public:
    int age;
    int weight;
    Animal(){
        cout << "inside animal" << endl;
    }
};

class Dog : public Animal{
public:
    void bark(){
        cout << "Dog barking" << endl;
    }
    Dog(){
        cout << "Inside Dog" << endl;
    }
};

class GermanShephard : public Dog{
public:
    void attack(){

    }
    GermanShephard(){
        cout << "Inside german shephard" << endl;
    }
};

int main()
{
    GermanShephard g;
    return 0;
}