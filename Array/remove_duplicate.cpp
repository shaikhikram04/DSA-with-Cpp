#include <vector>
#include <iostream>
using namespace std;

int removeDuplicates(vector<int> &arr, int n)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            arr.erase(arr.begin() + i + 1);
            i--;
        }
        cout << "i -> " << i << endl;
        for (int j = 0; j < arr.size(); j++) {
            cout << arr[j] << " ";
        }
        cout << endl << endl;
    }
    return arr.size();
}

int main()
{
    vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 4, 5};
    cout << "length after remove : " << removeDuplicates(arr, arr.size());

    return 0;
}