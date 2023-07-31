#include <iostream>
using namespace std;

class Human{
public:
    int height;
    int weight;
    void speak(){

    }
    Human(){
        cout << "Inside human class" << endl;
    }
};

class Animal{
public:
    void bark(){

    }
    Animal(){
        cout << "Inside animal class" << endl;
    }
};

// multiple inheritance
class LivingBeing : public Human, public Animal{
public:
    void breath(){

    }
    LivingBeing(){
        cout << "Inside Livingbeing class" << endl;
    }
};

int main(){
    LivingBeing l;
    cout << "living being called" << endl;

    return 0;
    
}