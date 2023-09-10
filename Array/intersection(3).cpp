#include <iostream>
#include <vector>
#include <array>
using namespace std;

vector<int> intersection(vector<int> arr1, int n1, vector<int> arr2, int n2)
{
	vector<int> ans;
	int i = 0, j = 0;
	while (i < n1 && j < n2)
	{
		if (arr1[i] == arr2[j])
		{
			ans.push_back(arr1[i]);
			i++;
			j++;
		}
		else if (arr1[i] < arr2[j])
			i++;

		else
			j++;
	}
	return ans;
}

int main()
{
	vector<int> arr1,arr2;
	int n1,n2;
	arr1 = {1, 2, 3, 3, 5};
	arr2 = {1, 3, 5, 6};
	n1 = arr1.size();
	n2 = arr2.size();
	vector<int> ans=intersection(arr1,n1,arr2,n2);
	for(int i=0;i<ans.size();i++){
		cout<<ans.at(i)<<" ";
	}
	return 0;
}