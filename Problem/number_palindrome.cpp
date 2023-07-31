#include <iostream>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int revNum = 0;
    int num = x;
    while (x > revNum)
    {
        revNum = (revNum * 10) + (x % 10);
        x /= 10;
    }
    return x == revNum || x == revNum / 10;
}

int main()
{
    int x = 1234567899;
    if (isPalindrome(x))
    {
        cout << x << " is palindrome" << endl;
    }
    else
    {
        cout << x << " is not palindrome" << endl;
    }
    return 0;
}