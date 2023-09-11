#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
	int sRow = 0;
	int eCol = 0;
	while ((sRow < n / 2) && (eCol < m / 2)) {

		int temp = mat[sRow][sRow];
		int i = sRow;
		int j = i;
		while (i < m - sRow - 1) {
			mat[i][j] = mat[i+1][j];
			i++;
		}
		while (j < n - eCol - 1) {
			mat[i][j] = mat[i][j+1];
			j++;
		}
		while (i > sRow) {
			mat[i][j] = mat[i-1][j];
			i--;
		}
		while (j > sRow + 1) {
			mat[i][j] = mat[i][j-1];
			j--;
		}
		
		mat[i][j] = temp;

		
		sRow++;
		eCol++;
	}

}

int main()
{
	vector<vector<int>> matrix = {{1, 2, 3,4}, {5,6,7,8}, {9,10,11,12} };
	int n = matrix.size();
	int m = matrix[0].size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
	rotateMatrix(matrix, m, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	
	return 0;
}