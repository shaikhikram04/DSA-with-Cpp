#include <bits/stdc++.h> 
using namespace std;

int specialSum(vector<int>& arr, int n){
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    //* to get sum of each digit until we got single digit sum
    while (sum / 10 != 0) {
        int tempSum = 0;
        while (sum != 0) {
            int digit = sum % 10;
            tempSum += digit;
            sum = sum / 10;
        }
        sum = tempSum;
    }
    return sum;
}

int main() {

    vector<int> arr = {8,7,0,1,2};
    int n = arr.size();
    cout << specialSum(arr, n) << endl;
    return 0;
}