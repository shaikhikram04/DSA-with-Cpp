#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Shape
{
public:
    string shapeType;
    void printMyType()
    {
        cout << this->shapeType << endl;
    }
};

class Square : public Shape
{
public:
    string shapeType = "square";
    int length;
    void printMyType()
    {
        cout << this->shapeType << endl;
    }
    int calculateArea()
    {
        return length * length;
    }
};

class Rectangle : public Shape
{
public:
    string shapeType = "rectangle";
    int length;
    int breadth;
    void printMyType()
    {
        cout << this->shapeType << endl;
    }
    int calculateArea()
    {
        return length * breadth;
    }
};

int main()
{

    Square s;
    s.length = 5;
    s.printMyType();
    cout << s.calculateArea() << endl;

    Rectangle r;
    r.length = 5;
    r.breadth = 4;
    r.printMyType();
    cout << r.calculateArea() << endl;

    return 0;
}