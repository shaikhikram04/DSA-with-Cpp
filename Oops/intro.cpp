#include <iostream>
#include "hero.cpp"
using namespace std;

// OOPS CODE STUDIO ; https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1382163

int main()
{
    Hero mario;
    mario.health = 70;
    mario.level = 'A';

    cout << "health is " << mario.health << endl;
    cout << "level is " << mario.level << endl;

    return 0;
}