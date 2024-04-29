//? https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

//! T.C -> O(n*log(n))
//! S.C -> O(n)

//* sort, greedy

#include <bits/stdc++.h>
using namespace std;

//* Structure to represent an item with its value and weight
struct Item {
    int value;    //* Value of the item
    int weight;   //* Weight of the item
};

class Solution {
    //* Custom comparator for sorting items by value per weight ratio
    static bool cmp(pair<Item, double>& a, pair<Item, double>& b) {
        return a.second > b.second;  //* Sort in descending order of value per weight
    }
    
public:
    //* Function to solve the fractional knapsack problem
    double fractionalKnapsack(int w, Item arr[], int n) {
        //* Create a vector of pairs to store items along with their value per weight ratio
        vector<pair<Item, double>> v;
        
        //* Populate the vector with items and their corresponding value per weight ratio
        for (int i = 0; i < n; i++) {
            v.push_back({arr[i], static_cast<double>(arr[i].value) / arr[i].weight});
        }
        
        //* Sort the vector using the custom comparator
        sort(v.begin(), v.end(), cmp);
        
        //* Variable to store the total value of the knapsack
        double ans = 0.0;

        //* Traverse through the sorted items
        for (int i = 0; i < n; i++) {
            //* If the capacity is greater than the weight of the current item
            if (w > v[i].first.weight) {
                //* Include the entire item in the knapsack
                ans += v[i].first.value;
                //* Update the remaining capacity
                w -= v[i].first.weight;
            } else {
                //* Otherwise, take a fraction of the current item according to the remaining capacity
                ans += v[i].second * w;
                break;  //* Since the knapsack is now full, exit the loop
            }
        }
        
        //* Return the total value of the knapsack
        return ans;
    }
};
