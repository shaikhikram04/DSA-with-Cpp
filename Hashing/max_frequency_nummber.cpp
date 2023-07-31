// https://www.codingninjas.com/studio/problems/maximum-frequency-number_920319?leftPanelTab=0


#include <vector>
#include <unordered_map>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> cnt;

    int maxFreq = 0;
    int ans = 0;

    for (int i : arr) {
        cnt[i]++;
        maxFreq = max(cnt[i], maxFreq);
    }

    for (int i : arr) {
        if (maxFreq == cnt[i]) {
            ans = i;
            break;
        }
    }
    

    return ans;
}