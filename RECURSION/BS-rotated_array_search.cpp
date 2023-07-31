#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> arr, int s, int e, int key)
{
    if (s > e)
    {
        return -1;
    }

    int mid = s + (e - s) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[mid] - arr[s] < 0)
    {
        if (key > arr[mid] && key <= arr[e])
        {
            return search(arr, mid + 1, e, key);
        }
        else
        {
            return search(arr, s, mid - 1, key);
        }
    }
    else if (arr[mid] - arr[s] >= 0)
    {
        if (key < arr[mid] && key >= arr[s])
        {
            return search(arr, s, mid - 1, key);
        }
        else
        {
            return search(arr, mid + 1, e, key);
        }
    }
}

int main()
{
    vector<int> arr = {8, 1, 2, 3, 5, 7};
    int s = 0;
    int e = arr.size() - 1;
    int key;
    cout << "Enter a key : ";
    cin >> key;
    int index = search(arr, s, e, key);
    cout << "index --> " << index << endl;
    if (index < 0)
        cout << key << " is not present" << endl;

    else
        cout << key << " is present at " << index << endl;

    return 0;
}
