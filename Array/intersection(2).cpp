#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main()
{
	vector<int> arr1, arr2,ans;
	int n1, n2;
	arr1 = {1,2,3,3,5};
	arr2 = {1,3,5,6};
	n1 = arr1.size();
	n2 = arr2.size();
	
	for(int i=0;i<n1;i++){
		for(int j=0;j<n2;j++){
			if(arr1[i]<arr2[j]) break;
			if(arr1[i]==arr2[j]){
				ans.push_back(arr1[i]);
				arr2[j]=-7377;
				break;
			}
		}
	}
	for(int i=0; i < ans.size(); i++)
   cout << ans.at(i) <<"  ";
	return 0;
}