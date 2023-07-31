#include <iostream>
using namespace std;

int pivotIndex(int arr[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return s;
}

int main()
{

    int arr[] = {7, 8, 10, 12,0};
    int n = sizeof(arr) / sizeof(int);
    cout << "Pivot index is " << pivotIndex(arr, n);
    return 0;
}