// problem link : https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio

#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    for (int i = n-1; i >= 0; i--) {
        int element = arr[i];
        
        while (s.top() >= element) {
            s.pop();
        }
        arr[i] = s.top();
        s.push(element);
    }
    return arr;
}