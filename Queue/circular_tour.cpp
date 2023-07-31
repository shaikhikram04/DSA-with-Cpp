// https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int balance = 0;
        int start = 0;
        int need = 0;
        for (int i = 0; i < n; i++) {
            balance += p[i].petrol - p[i].distance;
            // travel not posible
            if (balance < 0) {
                need += balance;
                start = i + 1;
                balance = 0;
            }
        }
        if (balance + need >= 0) {
            return start;
        }
        else {
            return -1;
        }
    }
};



