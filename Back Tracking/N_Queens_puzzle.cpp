// https://www.codingninjas.com/studio/problems/the-n-queens-puzzle_981286?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

// T.C -> O(N!)
// S.C -> O(N*N)


#include <bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
	vector<int> temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}

bool isSafe (vector<vector<int>> &board, int row, int col, int n) {

	// check for row
	for (int i = 0; i < col; i++) {
		if (board[row][i])
			return false;
	}

	// check for diagonal
	int r = row;
	int c = col;
	while (c >= 0 && r < n) {
		if (board[r][c])
			return false;

		r++;
		c--;
	}

	r = row;
	c = col;
	while (c >= 0 && r >= 0) {
		if (board[r][c])
			return false;

		r--;
		c--;
	}

	return true;
}

void solve(vector<vector<int>> &ans, vector<vector<int>> &board, int n, int col) {
	// base case
	if (col == n) {
		addSolution(board, ans, n);
		return;
	}

	for (int row = 0; row < n; row++) {
		if (isSafe(board, row, col, n)) {
			board[row][col] = 1;
			solve(ans, board, n, col + 1);
			board[row][col] = 0;
		}
	}
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> ans;

	vector<vector<int>> board(n, vector<int> (n, 0));

	solve(ans, board, n, 0);

	return ans;
}