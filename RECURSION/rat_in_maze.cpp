// problem link : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSafe(int x, int y, vector<vector<int>> m, int n, vector<vector<int>> visited)
{
    // check condition for travel of mouse
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && m[x][y] == 1 && visited[x][y] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(vector<vector<int>> m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    // assigning visited matrix of index x,y as 1
    visited[x][y] = 1;

    // 4 choice D || L || R || U

    // Down
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, m, n, visited))
    {
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // LEFT
    newx = x;
    newy = y - 1;
    if (isSafe(newx, newy, m, n, visited))
    {
        path.push_back('L');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // RIGHT
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, m, n, visited))
    {
        path.push_back('R');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // UP
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, m, n, visited))
    {
        path.push_back('U');
        solve(m, n, ans, newx, newy, visited, path);
        // back tracking    
        path.pop_back();
    }

    // reassigning visited matrix of intex x,y as 0
    visited[x][y] = 0;
}

// TIME COMPLEXITY  --> O(2^(n^2))
// SPACE COMPLEXITY --> O(n^2)
vector<string> findPath(vector<vector<int>> m, int n)
{
    vector<string> ans;

    // if the source place is 0 then return a empty vector
    if (m[0][0] == 0)
    {
        return ans;
    }
    int srcx = 0;
    int srcy = 0;
    vector<vector<int>> visited = m;

    // initialize all element of visited array is 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            visited[i][j] = 0;
    }

    string path = "";
    solve(m, n, ans, srcx, srcy, visited, path);

    // we have to return all path in lexicographical increasing order
    // so we have to sort the ans vector
    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int n = 4;
    vector<string> ans = findPath(m, n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    cout << endl;

    return 0;
}