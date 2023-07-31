#include <iostream>
#include <vector>

using namespace std;

int pivotIndex(vector<int> arr, int s, int e)
{
    if (s >= e)
    {
        return s;
    }

    int mid = s + (e - s) / 2;
    if (arr[mid] >= arr[0])
    {
        return pivotIndex(arr, mid + 1, e);
    }
    else
    {
        return pivotIndex(arr, s, mid);
    }
}

int main()
{
    vector<int> arr = {5, 7, 9, 1, 3, 4};
    int s = 0;
    int e = arr.size() - 1;

    cout << "Pivot index is " << pivotIndex(arr, s, e) << endl;

    return 0;
}