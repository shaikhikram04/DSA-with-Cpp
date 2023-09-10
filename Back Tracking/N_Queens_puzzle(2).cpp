// T.C -> O(N!)
// S.C -> O(N*N)


#include <bits/stdc++.h>
using namespace std; 

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
	vector<int> temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			temp.push_back(board[i][j]);
	}
	ans.push_back(temp);
}

void solve(vector<vector<int>> &ans, vector<vector<int>> &board, unordered_map<int, bool> &checkRow, unordered_map<int, bool> &checkUD, unordered_map<int, bool> &checkLD, int n, int col) {
	if (col == n) {
		addSolution(board, ans, n);
		return;
	}

	for (int row = 0; row < n; row++) {
		if (!checkRow[row] && !checkUD[row-col] && !checkLD[row+col]) {
			board[row][col] = 1;
			checkRow[row] = checkUD[row-col] = checkLD[row+col] = true;
			
			solve(ans, board, checkRow, checkUD, checkLD, n, col + 1);
			
			board[row][col] = 0;
			checkRow[row] = checkUD[row-col] = checkLD[row+col] = false;
		}
	}
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> ans;
	vector<vector<int>> board(n, vector<int> (n, 0));
	unordered_map<int, bool> checkRow;
	unordered_map<int, bool> checkUD;
	unordered_map<int, bool> checkLD;
	
	solve(ans, board, checkRow, checkUD, checkLD, n, 0);

	return ans;
	
}