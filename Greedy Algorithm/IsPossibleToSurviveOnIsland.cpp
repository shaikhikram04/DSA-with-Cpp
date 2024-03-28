//? https://www.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1

//! T.C -> O(1)
//! S.C -> O(1)

//* Mathematical logic, greedy

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //! N – The maximum unit of food you can buy each day.
    //! S – Number of days you are required to survive.
    //! M – Unit of food required each day to survive.
    int minimumDays(int S, int N, int M){
        //* Find no. of sunday appear in S days
        int sunday = S / 7;
        //* Then find No. of day inWhich we can buy food(exclude sunday from survive day)
        int buyingDays = S - sunday;
        
        //* Find Total quantity of food required to servive
        int totalFood = S*M;

        //* it will store result(No. of time buy a food)
        int ans = 0;
        
        //* if total food required is multiple of N
        if (totalFood % N == 0) {
            //* Then we need to buy exactly totalFood/N  food to survive
            ans = totalFood/N;
        }
        else {
            //* otherwise, we have to buy food 1 extra time with totalFood/N to survive
            ans = totalFood/N + 1;
        }
        
        //* If our ans is less than or equal to buyingDays that means 
        //* here we not include sunday to buy food so we return ans
        if (ans <= buyingDays)
            return ans;
        //* Otherwise we return -1 coz here we include Sunday to buy food
        //* But it is not possible to buy food on sunday so return -1
        else
            return -1;
    }
};