#include <iostream>
using namespace std;

class Hero
{
private:
    int health;
    char level;

public:

    // We can use above private member using getter and setter given below
    // Getter
    int getHealth(){
        return health;
    }
    char getLevel(){
        return level;
    }

    //Setter
    void setHealth(int h){
        health = h;
    }
    void setLevel(char l){
        level = l;
    }
};

int main()
{
    Hero mario;
    // use setter
    mario.setHealth(70);
    mario.setLevel('A');

    // use getter
    cout << "health is " << mario.getHealth() << endl;
    cout << "level is " << mario.getLevel() << endl;

    return 0;
}