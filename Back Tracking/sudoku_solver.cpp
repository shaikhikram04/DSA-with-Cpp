//  https://www.codingninjas.com/studio/problems/sudoku-solver_699919?leftPanelTab=0

// T.C -> O(9^k)  [where k is no. of empty block]
// S.C -> O(1)    [stack space i.e. 9*9 is always constant]

#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &sudoku, int row, int col, int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == val)
            return false;

        if (sudoku[i][col] == val)
            return false;
    }

    int startR = row - (row%3);
    int startC = col - (col%3);

    for (int i = startR; i < startR + 3; i++) {
        for (int j = startC; j < startC + 3; j++) {
            if (sudoku[i][j] == val)
                return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>>& sudoku, int row, int col) {
    // base case
    if (row == 8 && col == 9) {
        return true;
    }

    if (col == 9)
        return solve(sudoku, row+1, 0);

    if (sudoku[row][col] != 0) 
        return solve(sudoku, row, col+1);

    bool solutionFound = false;
    for (int i = 1; i <= 9; i++) {
        if(isSafe(sudoku, row, col, i)) {
            sudoku[row][col] = i;

            solutionFound = solve(sudoku, row, col+1);

            if (solutionFound)
                return true;
            else
                sudoku[row][col] = 0;
        }
    }
    return solutionFound;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku, 0, 0);
}