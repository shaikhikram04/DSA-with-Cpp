#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(string digit, string output, int index, vector<string>& ans, string mapping[])
{ 
    // base case
    if (index >= digit.length())
    {
        ans.push_back(output);
        return;
    }

    int number = digit[index] - '0';
    string value = mapping[number];

    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solve(digit, output, index + 1, ans, mapping);
        output.pop_back();
    }
}

// TIME COMPLEXITY  --> O(n)
// SPACE COMPLEXITY --> 
vector<string> letterCombination(string digit)
{
    vector<string> ans;
    if (digit.size() == 0)
        return ans;

    string output = "";
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(digit, output, index, ans, mapping);
    return ans;
}

int main()
{
    string digit = "23";
    vector<string> ans = letterCombination(digit);
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl << endl;

    return 0;
}