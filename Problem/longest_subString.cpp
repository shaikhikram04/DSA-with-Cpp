#include <iostream>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int len = 0;
    int n = s.length();
    string subStr = "";
    for (int i = 0; i < n; i++){
        int index = subStr.find(s[i]);
        if (index >= 0 && index < n){
            if (subStr.length() > len)
                len = subStr.length();
            subStr.erase(0 ,index + 1);
        }
        subStr.push_back(s[i]);
        if (i == n -1 && subStr.length() > len){
            len = subStr.length();
        }
    }
    return len;
}

int main(){
    string s = " ";
    int subStrLen = lengthOfLongestSubstring(s);
    cout << subStrLen << endl;
}