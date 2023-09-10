#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> nums1, int m, vector<int> nums2, int n)
{
	vector<int> nums;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
		nums1.pop_back();

	while (a < m - n && b < n)
	{
		if (nums1[a] < nums2[b])
		{
			nums.push_back(nums1[a]);
			a++;
		}
		else
		{
			nums.push_back(nums2[b]);
			b++;
		}
	}
	while (a < m - n)
	{
		nums.push_back(nums1[a]);
		a++;
	}
	while (b < n)
	{
		nums.push_back(nums2[b]);
		b++;
	}
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << "  ";
	cout << endl;
}

int main()
{
	vector<int> nums1 = {1, 2, 3, 0, 0, 0};
	vector<int> nums2 = {2, 5, 6};
	int m = nums1.size(), n = nums2.size();
	merge(nums1, m, nums2, n);
	return 0;
}