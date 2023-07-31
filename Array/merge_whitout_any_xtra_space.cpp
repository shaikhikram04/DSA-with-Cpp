//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            queue<int> q;
            for (int i = 0; i < n; i++) {
                q.push(arr1[i]);
            }
            int i = 0, j = 0;
            while (!q.empty() && i < n && j < m) {
                if (arr2[j] < q.front()) {
                    arr1[i] = arr2[j];
                    j++;
                }
                else {
                    arr1[i] = q.front();
                    q.pop();
                }
                i++;
            }
            while (!q.empty() && i < n) {
                arr1[i] = q.front();
                q.pop();
                i++;
            }
            i = 0;
            while (!q.empty() && j < m) {
                if (arr2[j] < q.front()) {
                    arr2[i] = arr2[j];
                    j++;
                }
                else {
                    arr2[i] = q.front();
                    q.pop();
                }
                i++;
            }
            while (!q.empty() && i < m) {
                arr2[i] = q.front();
                q.pop();
                i++;
            }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends