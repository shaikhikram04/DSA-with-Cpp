#include <iostream>
#include <cmath>

using namespace std;

int squareRoot(int n, int s, int e)
{
    int mid = s + (e - s) / 2;
    if (n >= pow(mid, 2) && n < pow(mid + 1, 2))
    {
        return mid;
    }

    if (n > pow(mid, 2))
    {
        return squareRoot(n, mid + 1, e);
    }
    else
    {
        return squareRoot(n, s, mid - 1);
    }
}

int main()
{
    int n;
    cout << "Enter a positive number : ";
    cin >> n;
    cout << "Squareroot of " << n << " is " << squareRoot(n, 0, n / 2 + 1) << endl;
    return 0;
}