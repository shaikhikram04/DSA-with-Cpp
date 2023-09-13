#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;


//!  test cases

//?  10+11+12+5-8-12
//?  456+6523*5214+5412*5412
//?  4521-65*25-54+6523*9856/45+56-85
//?  2+5*(6+4-2*(4+1)+2)+1
//?  5214-956+658*85*(452+23*85+65)*(2)+65
//?  5*(6+4-2*(4+(89*2)*51)+2)+1
//?  5(6+4-2(4+(89*2)51)+2)+1
//?  25143+6523*25+65(5214+65)/2+4
//?  4521+6523(541+65(23+12)62)+50
//?  4521+6523(541+65(23+12)/62)+50
//?  5(6+4-2(4+1)+2)+1
//?  5413+652(5412+65(54+(89*2)+26+6)54)52
//?   5214+5(56(4+5)54+6(54+(65+5)*84)/5+8)+2

// *✓

vector<string> getPostFix(string exp) {
    vector<string> postFix;
    stack<char> op;
    unordered_map<char, int> precedence;
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['^'] = 3;
    precedence['('] = 4;

    int i = 0;
    while (i < exp.size()) {
        char ch = exp[i];

        //* case 1: number (0 - 9)
        if ((ch >= '0' && ch <= '9') || ch == '.') {
            string temp;
            while ((exp[i] >= '0' && exp[i] <= '9') || exp[i] == '.') {
                temp.push_back(exp[i]);
                i++;
            }
            postFix.push_back(temp);
            i--;
        }
        
        //* case 2 : close braces )
        else if (ch == ')') {
            while (op.top() != '(') {
                string temp(1, op.top());
                postFix.push_back(temp);

                op.pop();
            }
            op.pop();
        }

        //* case 3: lower or equal precedence
        else if (precedence[ch] <= precedence[op.top()]) {
            while (precedence[ch] <= precedence[op.top()] && op.top() != '(') {
                string temp(1, op.top());
                postFix.push_back(temp);

                op.pop();
            }
            op.push(ch);
        }

        //* case 4 : higher precedence
        else {
            op.push(ch);
        }

        i++;
    }

    return postFix;
}

int calculate(string exp) {

    //* convert into postFix
    vector<string> postFix = getPostFix(exp);
}

int main() {

    string str;
    cout << "Enter Expression to calculate : ";
    cin >> str;

    vector<string> postFix = getPostFix(str);

    cout << "postfix of given expression is : " << endl;
    for (auto i : postFix)
        cout << i << " ";
    cout << endl;
}