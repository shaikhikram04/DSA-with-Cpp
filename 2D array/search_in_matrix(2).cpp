#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> matrix, int target)
{
	int row = matrix.size();
	int col = matrix[0].size();

	int i = 0;
	int j = col - 1;

	while (i < row && j >= 0)
	{
		int element = matrix[i][j];

		if (element == target)
			return 1;

		else if (element > target)
			j--;

		else if (element < target)
			i++;
	}

	return false;
}

int main()
{
	vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
	int target = 20;

	if (searchMatrix(matrix, target))
		cout << target << " is found in the matrix" << endl;
	else
		cout << target << " is not found in the matrix" << endl;

	return 0;
}