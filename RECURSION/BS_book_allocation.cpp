#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int> books, int pages, int student, int mid)
{
    int studCount = 1;
    int pageSum = 0;

    for (int i = 0; i < pages; i++)
    {
        if (pageSum + books[i] <= mid)
        {
            pageSum += books[i];
        }
        else
        {
            studCount++;
            if (studCount > student || books[i] > mid)
            {
                return false;
            }
            pageSum = books[i];
        }
    }
    return true;
}

int bookAllocation(vector<int> books, int s, int e, int pages, int student, int &ans)
{
    if (s >= e)
        return ans;

    int mid = s + (e - s) / 2;
    if (isPossible(books, pages, student, mid))
    {
        ans = mid;
        return bookAllocation(books, s, mid - 1, pages, student, ans);
    }
    else
    {
        return bookAllocation(books, mid + 1, e, pages, student, ans);
    }
}

int main()
{
    // vector<int> books = {12, 34, 67, 90};
    vector<int> books = {10, 20, 30, 40};
    int pages = books.size();
    int student = 2;
    int ans = -1;
    int s = 0;
    int sum = 0;
    for (int i = 0; i < books.size(); i++)
        sum += books[i];

    int e = sum;

    cout << bookAllocation(books, s, e, pages, student, ans) << endl;

    return 0;
}