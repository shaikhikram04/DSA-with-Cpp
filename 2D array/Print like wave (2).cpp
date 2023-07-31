#include <iostream>
#include <vector>
using namespace std;
vector<int> printWave(vector<vector<int>> arr, int row, int col)
{
	vector<int> wave;
	for (int j = 0; j < col; j++)
	{
		if (j & 1)
		{
			//for bottom to top
			for (int i = row - 1; i>= 0; i--)
				wave.push_back(arr[i][j]);
		}
		else
		{
			//top to bottom
			for (int i = 0; i < row; i++)
				wave.push_back(arr[i][j]);
		}
	}

	return wave;
}

int main()
{
	vector<vector<int>> arr = {{3, 5, 2}, {4, 3, 1}};

	vector<int> wave = printWave(arr, 2, 3);

	for (int i : wave)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}