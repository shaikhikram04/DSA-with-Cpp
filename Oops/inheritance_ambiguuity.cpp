#include <iostream>
using namespace std;

class A{
public:
    int a;
    void abc(){
        cout << "Inside class A" << endl;
    }
};

class B{
public:
    int a;
    void abc(){
        cout << "Inside class B" << endl;
    }
};

class C : public A, public B{
public:

};

int main()
{
    C obj;

    // it generate error
    //obj.abc();
    obj.B :: a = 51;
    obj.A :: abc();
    cout << obj.B :: a << endl;
    return 0;
}