// https://www.codingninjas.com/codestudio/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047

#include <bits/stdc++.h> 
using  namespace std;

long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {

	deque<int> mini, maxi;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        // make maxi in decreasing order 
        while (!maxi.empty() && nums[maxi.back()] <= nums[i]) {
            maxi.pop_back();
        }
        // make mini in increasing order
        while (!mini.empty() && nums[mini.back()] >= nums[i]) {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    for (int i = k; i < n; i++) {
        sum += nums[maxi.front()] + nums[mini.front()];

        // removal part
        while (!maxi.empty() && i - maxi.front() >= k) {
            maxi.pop_front();
        }
        while (!mini.empty() && i - mini.front() >= k) {
            mini.pop_front();
        }

        // addition part
        while (!maxi.empty() && nums[maxi.back()] <= nums[i]) {
            maxi.pop_back();
        }
        while (!mini.empty() && nums[mini.back()] >= nums[i]) {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }
    sum += nums[maxi.front()] + nums[mini.front()];

    return sum;
}
