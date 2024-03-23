//? https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

//! T.C -> O(n*m)
//! S.C -> O(n*m)

//* sort, greedy

#include <bits/stdc++.h> 
using namespace std;


class Solution{
    
    //* Comparatable function which is use to sort the array according to Finish time of meetings
    //* In ascending order.
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
    
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        //* create a vector which will store 3 things 
        //* Sr.No. of meeting, Start Time & Finish Time
        vector<vector<int>> meeting;
        for (int i = 0; i < N; i++) {
            meeting.push_back({i+1, S[i], F[i]});
        }
        //* then sort it according to Finish time
        sort(meeting.begin(), meeting.end(), cmp);
        
        //* It store result which is position of all Meetings which can be arrange
        //* in a meeting room
        vector<int> ans;
        //* It store the finish time of the previous meeting
        //* initially it is -1.
        int prevEnd = -1;

        //* Iterate meeting array,
        for (int i = 0; i < N; i++) {
            //* If current meeting is possible to arrange
            if (meeting[i][1] > prevEnd && meeting[i][2] > prevEnd) {
                //* Then store its position in ans array
                //* and update the prevEnd time to curr end time
                ans.push_back(meeting[i][0]);
                prevEnd = meeting[i][2];
            }
        }

        //* At the end sort the all final position 
        //* And return it.
        sort(ans.begin(), ans.end());
        return ans;
    }
};