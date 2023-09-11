#include <iostream>
#include <vector>
using namespace std;


//matrix is sorted row wise and first element of each row is greater than last element of its previous row
bool searchMatrix(vector<vector<int>> matrix, int target)
{
	int row = matrix.size();
	int col = matrix[0].size();

	int start = 0;
	int end = row * col - 1;
	int mid;

	while (start <= end)
	{
		mid = start + (end - start) / 2;

		int element = matrix[mid / col][mid % col];
		if (element == target)
			return true;
		else if (element > target)
			end = mid - 1;
		else if (element < target)
			start = mid + 1;
	}
	return false;
}

int main()
{
	vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
	int target = 33;

	if (searchMatrix(matrix, target))
		cout << target << " is found in the matrix" << endl;
	else
		cout << target << " is not found in the matrix" << endl;

	return 0;
}