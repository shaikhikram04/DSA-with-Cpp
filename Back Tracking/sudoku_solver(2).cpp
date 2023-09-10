

// T.C -> O(9^k)
// S.C -> O(1)

#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, int k, vector<vector<int>> &sudoku)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == k || sudoku[i][col] == k ||
            sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == k)
            return false;
    }
    return true;
}
bool solve(vector<vector<int>> &sudoku)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (sudoku[row][col] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (isValid(row, col, k, sudoku))
                    {
                        sudoku[row][col] = k;
                        if (solve(sudoku))
                            return true;
                        else
                            sudoku[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> &sudoku) { solve(sudoku); }