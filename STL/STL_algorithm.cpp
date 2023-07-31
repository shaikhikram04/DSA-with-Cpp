#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;

	v.push_back(1);
	v.push_back(3);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);

	//finding 6 using binary search
	cout << binary_search(v.begin(), v.end(), 6) << endl;

	cout << "Lower bound -> " << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl;
	cout <<"Before Rotate ->";
	for (int i : v)
	{
		cout << i << "  ";
	}
	cout << endl;
	rotate(v.begin(), v.begin() + 1, v.end());
	cout <<"Afer Rotate ->";
	for (int i : v)
	{
		cout << i << "  ";
	}
	cout << endl;
	sort(v.begin(), v.end());
	for (int i : v)
	{
		cout << i << "  ";
	}
	cout<<endl;
	
	string abcd="abcd";
	reverse(abcd.begin(),abcd.end());
	cout<<"On reverse abcd -> "<<abcd;
	
	
	return 0;
}