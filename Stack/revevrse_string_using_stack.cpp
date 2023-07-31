#include <iostream>
#include <stack>
using namespace std;

string reverseString(string str) {
    stack<int> st;
    for(int i = 0; i < str.size(); i++) {
        st.push(str[i]);
    }
    string ans;
    while(!(st.empty())) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    string str = "Hello Jii!!";
    string reversedStr = reverseString(str);
    cout << str << endl;
    cout << reversedStr << endl;
    return 0;
}