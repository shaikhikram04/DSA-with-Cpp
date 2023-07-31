#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<string> subSequences(string str)
{
    vector<string> subSec;

    int bit = str.length();
    int allbit = pow(2, bit);

    for (int i = 0; i < allbit; i++)
    {
        string output = "";
        for (int j = 0; j < bit; j++)
        {
            if ((i >> j) & 1)
            {
                output.push_back(str.at(j));
            }
        }
        if (output.length() > 0)
            subSec.push_back(output);
    }
    return subSec;
}

int main()
{
    string str = "abc";
    vector<string> subSeq = subSequences(str);

    for (int i = 0; i < pow(2, str.length()) - 1; i++)
    {
        for (int j = 0; j < subSeq[i].size(); j++)
        {
            cout << subSeq[i][j] << " ";
        }
        cout << endl;
    }
}