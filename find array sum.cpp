#include <iostream>
#include <vector>
using namespace std;

vector<int> findArraySum(vector<int> a, int n, vector<int> b, int m)
{
	vector<int> ans;
	int carry = 0, sum = 0;
	int i = n - 1, j = m - 1;
	while (i >= 0 && j >= 0)
	{
		sum = a[i] + b[j] + carry;

		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		i--;
		j--;
	}
	while (i >= 0)
	{
		sum = a[i] + carry;

		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		i--;
	}
	while (j >= 0)
	{
		sum = a[j] + carry;

		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		j--;
	}
	if (carry != 0)
		ans.push_back(carry);

	reverse(ans.begin(), ans.end());

	return ans;
}

int main()
{
	vector<int> a = {4, 5, 1};
	vector<int> b = {3, 4, 5};
	vector<int> ans = findArraySum(a, a.size(), b, b.size());
	for (int i : ans)
		cout << i;
	cout << endl;
	return 0;
}