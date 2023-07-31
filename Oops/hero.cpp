#include <iostream>
using namespace std;

class Hero
{
    // by default private
    char name[100]; // it is private member we cant directly access it into a main function

public: // access modifier
    int health;
    char level;
};

