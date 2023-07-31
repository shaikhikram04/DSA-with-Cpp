// https://practice.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1

class Solution {
public:
    void segregateElements(int arr[], int n)
    {
        int last = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] < 0) {
                int num = arr[i];
                int j = i;
                
                while (j < n - 1 && arr[j + 1] >= 0) {
                    arr[j] = arr[j+1];
                    j++;
                }
                arr[j] = num;
            }
        }
    }
};