#include <iostream>
using namespace std;

class hero
{
    int health;
    char level;

public:
    hero()
    {
        cout << "constructor called" << endl;
    }
    // defining copy constructor
    hero(hero& temp){
        this->health = temp.health;
        this->level = temp.level;
    }
    hero(int health, char level)
    {
        this->health = health;
        this->level = level;
    }
    void print()
    {
        cout << "Health is " << health << endl;
        cout << "Level is " << level << endl;
    }
};

int main()
{
    hero a(70,'B');
    a.print();

    // copying the parameter value of a to the b object
    hero b(a);
    b.print();

    return 0;
}
