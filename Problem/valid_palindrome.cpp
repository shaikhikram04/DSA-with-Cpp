#include <iostream>
using namespace std;

bool isNonAlphaNumeric(string s, int index)
{
    return (s[index] < '0' || (s[index] > '9' && s[index] < 'a') || s[index] > 'z');
}

void checkAndLower(string &s, int i)
{
    if (s[i] >= 'A' && s[i] <= 'Z')
    {
        s[i] = s[i] - 'A' + 'a';
    }
}

bool isPalindrome(string s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        checkAndLower(s, i);
        checkAndLower(s, j);

        cout << "i ->" << i << "\t"
             << "j ->" << j << endl;
        cout << s[i] << "\t" << s[j] << endl;

        if (isNonAlphaNumeric(s, i) || isNonAlphaNumeric(s, j))
        {
            while (isNonAlphaNumeric(s, i))
            {
                i++;
                checkAndLower(s, i);
                if (i == s.length() - 1)
                    return true;
            }
            while (isNonAlphaNumeric(s, j))
            {
                j--;
                checkAndLower(s, j);
                if (j == 0)
                    return true;
            }
            cout << "I ->" << i << "\t"
                 << "J ->" << j << endl;
            cout << s[i] << "\t" << s[j] << endl;
        }

        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // string s = "A man, a plan, a canal: Panama";
    string s = "Marge, let's \"[went].\" I await {news} telegram.";
    if (isPalindrome(s))
    {
        cout << "It is a pallindrome" << endl;
    }
    else
    {
        cout << "It is not a pallindrome" << endl;
    }
}