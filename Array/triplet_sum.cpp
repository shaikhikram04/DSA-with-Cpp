#include <iostream>
using namespace std;

void tripletSum(int arr[], int n, int sum)
{
	int r = 0;
	int ans[r][3];
	int index = 0;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (arr[i] + arr[j] + arr[k] == sum)
				{
					r++;
					ans[r][3];
					ans[index][index] = arr[i];
					ans[index][index + 1] = arr[j];
					ans[index][index + 2] = arr[k];
				}
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << ans[i][j] << "  ";
		}
		cout << endl;
	}
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 1 , 0};
	int n = sizeof(arr) / sizeof(int);
	int k = 6;
	tripletSum(arr, n, k);
	return 0;
}