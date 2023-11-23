//? problem link : https://practice.geeksforgeeks.org/problems/max-min/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//! T.C -> O(log n)
//! S.C -> O(1)

#include <utility>
using namespace std;

class Solution
{
    pair<int, int> getMinMax(int A[], int start, int last) {
        pair<int, int> minMax;
        
        // case 1 : 1 element in array
        if (start == last) {
            return {A[start], A[last]};
        }
        
        // case 2 : 2 element in array
        if (last == start + 1) {
            if (A[start] < A[last]) {
                minMax.first = A[start];
                minMax.second = A[last];
            }
            else {
                minMax.first = A[last];
                minMax.second = A[start];
            }
            return minMax;
        }
        
        // case 3 : more than 2 element
        
        // divide array into 2 parts
        int mid = (start + last)/2;
        
        // finding min and max of both parts
        pair<int, int> left = getMinMax(A, start, mid);
        pair<int, int> right = getMinMax(A, mid+1, last);
        
        // comparing min and max of both part and assigning the result
        if (left.first < right.first)
            minMax.first = left.first;
        else 
            minMax.first = right.first;
            
        if (left.second > right.second)
            minMax.second = left.second;
        else
            minMax.second = right.second;
            
        return minMax;
    }
   public:
    int findSum(int A[], int N)
    {
    	pair<int, int> minMax = getMinMax(A, 0, N-1);
    	
    	return (minMax.first + minMax.second);
    }

};