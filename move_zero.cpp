#include <vector>
#include <iostream>
#include <array>
using namespace std;

vector<int> move_zeroes(const vector<int> &input)
{
	vector<int> ans;
	int count = 0, s = input.size();
	for (int i = 0; i < s; i++)
	{
		if (input[i] == 0)
		{
			count++;
			continue;
		}
		ans.push_back(input[i]);
	}
	for(int i=1;i<=count;i++){
		ans.push_back(0);
	}
	return ans;
}

int main()
{
	vector<int> arr={1,0,1,2,0,1,3};
	vector<int> ans=move_zeroes(arr);
	for(int i=0;i<arr.size();i++){
		cout<<ans.at(i)<<"  ";
	}
	return 0;
}