//? https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

//! T.C -> O(n*log(n))
//! S.C -> O(n)

//* sort, greedy

#include <bits/stdc++.h> 
using namespace std;

class Solution
{
    public:
    //* Function to find the maximum number of meetings that can
    //* be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        //* crete an array of pairs which store starting and ending time of the meeting
        vector<pair<int, int>> intervals;
        for (int i = 0; i < n; i++) {
            intervals.push_back({start[i], end[i]});
        }
        
        //* sort the array according to start time
        sort(intervals.begin(), intervals.end());
        
        int ans = 0;
        int nextStart = INT_MAX;
        
        //* counting the no. of meeting possible in a room using nextStart time
        //* Iterate from last meeting in sorted schedule
        for (int i = n-1; i >= 0; i--) {
            if (intervals[i].second < nextStart) {
                ans++;
                nextStart = intervals[i].first;
            }
        }
        
        return ans;
    }
};