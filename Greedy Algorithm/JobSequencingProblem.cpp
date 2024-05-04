//? https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

//! T.C -> O(n*log(n))
//! S.C -> O(n)

//* sort, greedy

#include <bits/stdc++.h>
using namespace std;

//* Structure representing a Job with its id, deadline & profit
struct Job 
{ 
    int id;	  //* Job Id 
    int dead; //* Deadline of the job 
    int profit; //* Profit if the job is completed before or on the deadline 
};

class Solution 
{
    //* Custom comparator used to sort an array of Jobs according to profit
    static bool cmp(Job& a, Job& b) {
        return a.profit > b.profit;
    }
    
    public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        //* Sorting the job array according to profit
        sort(arr, arr+n, cmp);
        
        //* An array to schedule the jobs
        vector<bool> schedule(n+1, false);

        //* Variables to count the number of jobs done and the maximum profit
        int jobDone = 0;
        int maxProfit = 0;
        
        //* Iterating over the Job array
        for (int i = 0; i < n; i++) {
            //* For each job, find an available schedule
            for (int j = arr[i].dead; j > 0; j--) {
                //* If the schedule is available 
                if (schedule[j] == false) {
                    //* Increment the job count
                    //* Accumulate profit
                    //* Assign the job and update the schedule array, then move to the next job
                    jobDone++;
                    maxProfit += arr[i].profit;
                    schedule[j] = true;
                    break;
                }
            }
        }
        
        //* Returning the number of jobs done and the profit
        return {jobDone, maxProfit};
    } 
};
