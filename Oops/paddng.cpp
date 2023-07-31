#include <iostream>
using namespace std;

class hero{
    public:
    char level;
    int health;
    // double d;
};

int main(){
    hero h1;
    // we expecting size of h1 is 5(4 + 1) but...
    cout << "Size of h1 = " << sizeof(h1) << endl;
    // it is 8, here concept of padding come 
    // resource : https://www.scaler.com/topics/structure-padding-in-c/#:~:text=Structure%20padding%20is%20defined%20as,4%20bytes%20at%20a%20time. 
    return 0;
}