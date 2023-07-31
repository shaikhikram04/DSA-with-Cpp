#include <iostream>
using namespace std;

class Hero
{
public:
    Hero(){
        cout << "Simple connstructor called"<< endl;
    }

    // destructor 
    ~Hero(){
        cout << "Destructor called"<< endl;
    }
};

int main(){
    // statically
    Hero a;
    
    // Dynamically
    Hero* b = new Hero();

    // manually destructor call
    delete b;
}
