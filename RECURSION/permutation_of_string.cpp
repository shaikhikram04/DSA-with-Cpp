#include <iostream>
#include <vector>

using namespace std;

void solve(string str, int index, vector<string> &ans)
{
    if (index >= str.size())
    {
        ans.push_back(str);
        return;
    }
    else
    {
        for (int i = index; i < str.size(); i++)
        {
            swap(str[index], str[i]);
            solve(str, index + 1, ans);
            // back track 
            // if we go for next iteration then swaped string will pass instead of main string 
            swap(str[index], str[i]);
        }
    }
}

// TIME COMPLEXITY  --> O(n^2)
// SPACE COMPLEXITY --> 
vector<string> permutation(string str)
{
    vector<string> ans;
    int index = 0;
    solve(str, index, ans);
    return ans;
}

int main()
{
    string str = "123";
    vector<string> ans = permutation(str);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}