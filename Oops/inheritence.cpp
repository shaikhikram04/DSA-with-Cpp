#include <iostream>
using namespace std;

class human{
private:
    int weight;
public:
    int height;
    string name;
    int age;
    void setName(string n){
        name = n;
    }
    string getName(){
        return name;
    }
};

class male : public human{
public:
    string beard;
    void sleep(){
        cout << "male sleeping"<< endl;
    }

};

int main(){
    male m1;
    m1.setName("Abhishek");
    m1.age = 37;
    m1.height = 171;
    // we cant access the weight because it is private member
    // m1.weight = 76;
    m1.sleep();

    cout << m1.getName() << endl;
    cout << m1.age << endl;
    cout << m1.height << endl;

    return 0;
}