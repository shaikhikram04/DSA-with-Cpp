//? https://leetcode.com/problems/min-cost-climbing-stairs/description/

//! T.C -> O(n)
//! S.C -> O(1)

#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //* top of stair
        int n = cost.size();

        //* previous 2 stair
        int prev1 = cost[0];
        int prev2 = cost[1];

        for (int i = 2; i < n; i++) {
            //* find minimum cost and add curr cost into it
            int curr = cost[i] + min(prev1, prev2);

            //* shift previous 2 stair
            prev1 = prev2;
            prev2 = curr;
        }
 
        //* return minimum of previous 2 stair of top stair
        return min(prev1, prev2);
    }
};