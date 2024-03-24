//? https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1

//! T.C -> O(n*log(n))
//! S.C -> O(1)

//* sort, greedy

#include <bits/stdc++.h> 
using namespace std;

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        //* Sort the candies array in ascending order
        sort(candies, candies+N);
        
        //* It store minimum amount
        int mini = 0;
        //* It pointes to the cheapest available candie which we'll gonna buy
        int buy = 0;
        //* It pointes to the expensive available candie which we'll take as free
        int Free = N-1;
        
        //* buy candie untill no candie left
        while (buy <= Free) {
            //* buy cheapest candie and go for next
            mini += candies[buy++];
            //* take K most expensive candie as free
            Free -= K;
        }
        
        //* //* It store maximum amount
        int maxi = 0;
        //* It pointes to the expensive available candie which we'll gonna buy
        buy = N-1;
        //* It pointes to the cheapest available candie which we'll take as free
        Free = 0;
        
        //* buy candie untill no candie left
        while (Free <= buy) {
            //* buy expensive candie and go for next
            maxi += candies[buy--];
            //* take K most cheapest candie as free
            Free += K;
        }
        
        //* Return the minimum and maximum ammount
        return {mini, maxi};
    }
};