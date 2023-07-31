#include <iostream>
using namespace std;

int main()
{
	int arr3d[2][3][2] = {
		{{6, 8},
		 {1, 3},
		 {2, 4}},
		{{5, 6},
		 {7, 8},
		 {9, 0}}};
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				cout << arr3d[i][j][k] << "\t";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}