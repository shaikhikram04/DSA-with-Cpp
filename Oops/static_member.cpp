#include <iostream>
using namespace std;

class Hero
{
public:
    int health;
    char level;
    static int timeToComplete;

    // defining static function
    static int random(){
        return timeToComplete;
    }
};

int Hero::timeToComplete = 10;

int main()
{
    cout << Hero ::timeToComplete << endl;

    Hero a;
    cout << a.timeToComplete << endl;

    Hero b;
    b.timeToComplete = 20;
    cout << b.timeToComplete << endl;
    cout << a.timeToComplete << endl;

    // use static function
    cout << b.random() <<endl;

    return 0;
}