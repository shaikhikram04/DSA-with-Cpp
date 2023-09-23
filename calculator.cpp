#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <iomanip>
using namespace std;


//!  test cases

//?  10+11+12+5-8-12                                -> 18 
//?  456+6523*5214+5412*5412                        -> 63301122
//?  4521-65*25-54+6523*9856/45+56-85               -> 1431494.95556
//?  2+5*(6+4-2*(4+1)+2)+1                          -> 13
//?  5214-956+658*85*(452+23*85+65)*(2)+65          -> 276522243
//?  5*(6+4-2*(4+(89*2)*51)+2)+1                    -> -90759
//?  5(6+4-2(4+(89*2)51)+2)+1                       -> -90759
//?  25143+6523*25+65(5214+65)/2+4                  -> 359789.500000
//?  4521+6523(541+65(23+12)62)+50                  -> 923602664.000000
//?  4521+6523(541+65(23+12)/62)+50                 -> 3772866.016129
//?  5(6+4-2(4+1)+2)+1                              -> 11.000000
//?  5413+652(5412+65(54+(89*2)+26+6)54)52          -> 31600296421.000000
//?  5214+5(56(4+5)54+6(54+(65+5)*84)/5+8)+2        -> 176940.000000
//?  3.7+98.1+8^5/2^3*7.4                           -> 30412.200000

// *✓

void addAsterisk(string &str) {
    string exp;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' && (str[i-1] >= '0' && str[i-1] <= '9')) {
            exp.push_back('*');
        } 
        else if (str[i-1] == ')' && (str[i] >= '0' && str[i] <= '9')) {
            exp.push_back('*');
        }
        exp.push_back(str[i]);
    }
    str = exp;
}


vector<string> getPostFix(string &exp) {
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
                temp.push_back(exp[i++]);
            }
            postFix.push_back(temp);

            if (i >= exp.size())
                break;

            ch = exp[i];
        }
        
		//* case : when stack is empty
		if (op.empty())
			op.push(ch);

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
			// cout << "in case 3" << endl;
            while (!op.empty() && precedence[ch] <= precedence[op.top()] && op.top() != '(') {
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

	while (!op.empty()) {
		string temp(1, op.top());
		postFix.push_back(temp);

		op.pop();
	}


    return postFix;
}

void solve (stack<double> &s, string optr) {
    double top = s.top();
    s.pop();
    if (optr == "+")
        s.top() += top;
    else if (optr == "-")
        s.top() -= top;
    else if (optr == "*")
        s.top() *= top;
    else if (optr == "/")
        s.top() /= top;
    else if (optr == "^")
        s.top() = pow(s.top(), top);
}

double calculate(string exp) {

    //* add * where it is not present
    addAsterisk(exp);

    //* convert into postFix
    vector<string> postFix = getPostFix(exp);

    cout << "\n postfix of given expression :" << endl;
    for (auto i : postFix)
        cout << i << " ";
    cout << endl << endl;

    stack<double> s;

    for (int i = 0; i < postFix.size(); i++) {
        string op = postFix[i];
        if (op == "+" || op == "-" || op == "*" || op == "/" || op == "^") {
            solve(s, op);
        }
        else {
            s.push(stod(op));
        }

    }
    return s.top();
}

int main() {

    string str;
    cout << "Enter Expression to calculate : ";
    cin >> str;

    cout << "answer = " << fixed << calculate(str) << endl;

    return 0;
}