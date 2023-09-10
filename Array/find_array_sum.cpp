#include <iostream>
#include <vector>

using namespace std;


void reverse(vector<int> &arr) {
	int i = 0;
	int j = arr.size()-1;
	
	while (i < j) {
		swap(arr[i++], arr[j--]);
	}
}

vector<int> findArraySum(vector<int> a, int n, vector<int> b, int m)
{
	vector<int> ans;
	int carry = 0, sum = 0;
	int i = n - 1, j = m - 1;
	while (i >= 0 && j >= 0)
	{
		sum = a[i--] + b[j--] + carry;

		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
	}
	while (i >= 0)
	{
		sum = a[i--] + carry;

		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
	}
	while (j >= 0)
	{
		sum = a[j--] + carry;

		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
	}
	if (carry != 0)
		ans.push_back(carry);

	reverse(ans);

	return ans;
}

int main()
{
	vector<int> a = {9, 9, 9};
	vector<int> b = {1};
	vector<int> ans = findArraySum(a, a.size(), b, b.size());
	for (int i : ans)
		cout << i;
	cout << endl;
	return 0;
}