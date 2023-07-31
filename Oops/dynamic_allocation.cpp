#include <iostream>
using namespace std;

class Hero
{
public:
    int health;
};

int main()
{
    // static allocation
    Hero h1;
    h1.health = 70;
    cout << "Health is " << h1.health << endl;

    // dynamic allocation
    Hero *h2 = new Hero;
    (*h2).health = 80;
    cout << "Health is " << (*h2).health << endl; // 1st method
    cout << "Health is " << h2->health << endl;   // 2nd method

    return 0;
}