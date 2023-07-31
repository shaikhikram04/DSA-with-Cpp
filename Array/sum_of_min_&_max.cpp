// problem link : https://practice.geeksforgeeks.org/problems/max-min/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include <iostream>
using namespace std;

class Solution
{
   public:
    int findSum(int A[], int N)
    {
        int mini = A[0];
        int maxi = A[0];
        for (int i = 1; i < N; i++) {
            if (A[i] > maxi)
                maxi = A[i];

            if (A[i] < mini)
                mini = A[i];
        }
        int sum = mini + maxi;
        
        return sum;
    }

};
