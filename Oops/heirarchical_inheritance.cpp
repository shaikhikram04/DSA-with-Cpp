#include <iostream>
using namespace std;

class Human{
public:
    Human(){
        cout << "Inside human class" << endl;
    }
};

class Male : public Human{
public:
    Male(){
        cout << "Inside male class" << endl;
    }
};

class Female : public Human{
public:
    Female(){
        cout << "Inside Human class" << endl;
    }
};

int main(){
    Male m;
    cout << "Male called" << endl; 
    Female f;
    cout << "Female called" << endl;
    return 0;
}