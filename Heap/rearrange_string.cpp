// https://www.codingninjas.com/studio/problems/rearrange-string_982765?leftPanelTab=0

// T.C -> O(n * log(n))
// S.C -> O(n)


#include <bits/stdc++.h> 
using namespace std;
string reArrangeString(string &s)
{
	map<char, int> cnt;
    for (auto i : s) {
        cnt[i]++;
    }

    priority_queue<pair<int, char> > pq;

    for (auto i : cnt) {
        pq.push({i.second, i.first});
    }

    string ans;

    while (!pq.empty()) {
        pair<int, char> temp = pq.top();
        pq.pop();
        ans.push_back(temp.second);
        temp.first--;
        
        if (!pq.empty()) {
            pair<int, char> temp2 = pq.top();
            pq.pop();
            ans.push_back(temp2.second);
            temp2.first--;

            if (temp2.first)
                pq.push(temp2);
        } else {
            if (temp.first)
                return "not possible";
        }

        if (temp.first)
            pq.push(temp);
    }

    return ans;
}
