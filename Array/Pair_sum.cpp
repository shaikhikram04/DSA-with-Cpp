#include <iostream>
using namespace std;

void pairSum(int arr[], int size, int s)
{
	int ans[10][2], a = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] + arr[j] == s)
			{
				ans[a][0] = min(arr[i], arr[j]);
				ans[a][1] = max(arr[i], arr[j]);
				a++;
			}
		}
	}
	for (int p = 0; p < a; p++)
	{
		for (int q = 0; q <= 1; q++)
		{
			cout << ans[p][q] << "   ";
		}
		cout << endl;
	}
}

int main()
{
	int arr[] = {2, -3, 3, 3, -2};
	int size = sizeof(arr) / sizeof(int);
	pairSum(arr, size, 0);
	return 0;
}