// problem link : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

#include <iostream>
using namespace std;

int countVovel(string str) {
    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') 
            cnt++;
    }
    return cnt;
}

int maxVowels(string s, int k) {
    string subStr = "";
    int i;
    for (i = 0; i < k; i++) {
        subStr.push_back(s[i]);
    }
    int maxVovel = countVovel(subStr);
    cout << "subStr -> " << subStr << "\t vovel -> " << maxVovel << endl;
    cout << "max vovel -> " << maxVovel << endl;

    while (i < s.length()){
        subStr.push_back(s[i]);
        subStr.erase(subStr.begin() + 0);
        int nOv = countVovel(subStr);
        if(nOv > maxVovel){
            maxVovel = nOv;
        }
        cout << "subStr -> " << subStr << "\t vovel -> " << nOv << endl;
        cout << "max vovel -> " << maxVovel << endl;
        i++;
    }
    return maxVovel;
}

int main(){
    string s = "abciiidef";
    int k = 3;
    int maxVovel = maxVowels(s,k);
    cout << maxVovel << endl;
    return 0;
}