// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1


#include <limits.h>
#include <iostream>
using namespace std;

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        int mini = 0;
        int maxi = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[mini]) {
                mini = i;
            }
            if (arr[i] > arr[maxi]) {
                maxi = i;
            }
        }
        int mini2 = arr[mini] + k;
        int maxi2 = arr[maxi] - k;
        cout << "mini -> " << mini << endl;
        cout << "maxi -> " << maxi << endl << endl;
        for (int j = 0; j < n; j++) {
            cout << arr[j] << " ";
        } cout  << endl << endl;

        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            if (i == mini) {
                arr[i] += k;
            }
            else if (curr - k < mini2) {
                if (mini2 - (curr - k) < (curr + k) - maxi2) {
                    arr[i] -= k;
                    mini2 = arr[i];
                } else {
                    arr[i] += k;
                    if (arr[i] > maxi2) {
                        maxi2 = arr[i];
                    }
                }
            }
            else {
                arr[i] -= k;
            }
            cout << "i -> " << i << endl;
            for (int j = 0; j < n; j++) {
                cout << arr[j] << " ";
            } cout  << endl;
            cout << "mini2 -> " << mini2 << "\t";
            cout << "maxi2 -> " << maxi2 << endl << endl;
            
        }
        return (maxi2 - mini2); 
    }
};

int main() {
    int arr[] = {1, 5, 9, 5, 7, 3, 1, 4, 4, 8};
    int n = sizeof(arr) / sizeof(int);
    int k = 4;
    Solution s;
    int minDeff = s.getMinDiff(arr, n, k);
    cout << minDeff << endl;
}