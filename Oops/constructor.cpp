#include <iostream>
using namespace std;

class hero
{
public:
    hero()
    {
        cout << "constructor called" << endl;
    }
};

int main()
{
    hero a;
    hero *b = new hero;
    hero *c = new hero();
    return 0;
}
