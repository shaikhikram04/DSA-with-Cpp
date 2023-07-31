#include <iostream>
using namespace std;

int main()
{
	int m, n;
	cout << "Enter row of jagged array : ";
	cin >> m;
	int *size = new int[m];

	int **arr = new int *[m];
	for (int i = 0; i < m; i++)
	{
		cout << "Enter size of " << i + 1 << " row : ";
		cin >> n;
		size[i] = n;
		arr[i] = new int[n];
		cout << "Enter element : ";
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < size[i]; j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
	
	for(int i=0; i<m; i++){
		delete [] arr[i] ;
	}
	delete [] arr;

	return 0;
}