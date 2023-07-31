#include <iostream>
#include <string.h>
using namespace std;

class Hero
{
    int health;
    char level;

public:
    char *name;
    Hero()
    {
        name = new char[100];
    }
    Hero(Hero &temp)
    {
        char *ch = new char[strlen(temp.name)];
        strcpy(ch, temp.name);
        this->name = ch;

        this->health = temp.health;
        this->level = temp.level;
    }

    void setName(char name[])
    {
        strcpy(this->name, name);
    }
    void setHealth(int health)
    {
        this->health = health;
    }
    void setLevel(char level)
    {
        this->level = level;
    }
    void print()
    {
        cout << name << "\t" << health << "\t" << level << endl;
    }
};

int main()
{
    Hero hero1;
    hero1.setHealth(70);
    hero1.setLevel('B');
    char name[7] = "Babbar";
    hero1.setName(name);
    hero1.print();

    // use degault copy constructor
    Hero hero2(hero1);
    hero2.print();

    hero1.name[0] = 'G';
    hero1.print();

    hero2.print();
    
    return 0;
}