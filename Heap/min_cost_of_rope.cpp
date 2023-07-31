// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include <bits/stdc++.h>
using namespace std;

 class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        long long cost = 0;
        
        priority_queue <long long, vector<long long>, greater<long long> > minHeap;
        
        for (long long i = 0; i < n; i++)
            minHeap.push(arr[i]);
            
        while (minHeap.size() > 1) {
            long long sum = minHeap.top();
            minHeap.pop();
            sum += minHeap.top();
            minHeap.pop();
            
            minHeap.push(sum);
            cost += sum;
        }
        
        return cost;
    }
};