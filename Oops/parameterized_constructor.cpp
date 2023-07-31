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
    hero h1;
    h1.print();
    hero h2(100, 'O');
    h2.print();
    return 0;
}