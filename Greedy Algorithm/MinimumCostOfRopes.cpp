//? https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

//! T.C -> O(n*log(n))
//! S.C -> O(n)

//* priority queue, greedy

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    long long minCost(long long arr[], long long n) {
        //* variable that store cost to make single rope
        long long cost = 0;
        
        //* creating minHeap
        priority_queue <long long, vector<long long>, greater<long long> > minHeap;
        
        //* copy input array into minHeap
        for (long long i = 0; i < n; i++)
            minHeap.push(arr[i]);
            
        //* Iterate untill there is atleast 2 element in minHeap
        while (minHeap.size() > 1) {
            //* take sum of 2 minimum element and pop them
            long long sum = minHeap.top();
            minHeap.pop();
            sum += minHeap.top();
            minHeap.pop();
            
            //* store the sum in minHeap
            minHeap.push(sum);
            //* and update cost as we connect 2 ropes
            cost += sum;
        }
        
        //* return cost
        return cost;
    }
};