
#include <iostream>
using namespace std;

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long maxSum = arr[0];
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cout << "maxSum -> " << maxSum << endl;
            cout << "sum -> " << sum << endl << endl;
            sum += arr[i];
            
            if (sum > maxSum){
                maxSum = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        
        return maxSum;
    }
};

int main() {
    int arr[] = {-34, 95, -75, -17, 59, 53, -100, 59, 42, -24, -27, -61, -95, -96, 29};
    int n = sizeof(arr) / sizeof(int);
    Solution s;
    long long sum = s.maxSubarraySum(arr, n);
    cout << sum << endl;
    return 0;
}