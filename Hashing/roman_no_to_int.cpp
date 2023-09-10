// https://www.codingninjas.com/studio/problems/roman-number-to-integer_981308?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include <unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> roman;
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;

    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (roman[s[i]] >= roman[s[i+1]]) {
            ans += roman[s[i]];
        }
        else {
            ans -= roman[s[i]];
        }
    }

    return ans;
}