#include <iostream>
#include <vector>
using namespace std;

vector<int> printSpring(vector<vector<int>> matrix)
{
	int row = matrix.size();
	int col = matrix[0].size();

	vector<int> spring;
	int rs = 0;
	int re = row - 1;
	int cs = 0;
	int ce = col - 1;

	int count = 0;
	int total = row * col;
	while (count < total)
	{
		//printing starting row
		for (int i = cs; i <= ce && count < total; i++)
		{
			spring.push_back(matrix[rs][i]);
			count++;
		}
		rs++;

		//printing last column
		for (int i = rs; i <= re && count < total; i++)
		{
			spring.push_back(matrix[i][ce]);
			count++;
		}
		ce--;

		//printing last row
		for (int i = ce; i >= cs && count < total; i--)
		{
			spring.push_back(matrix[re][i]);
			count++;
		}
		re--;

		//printing first column
		for (int i = re; i >= rs && count < total; i--)
		{
			spring.push_back(matrix[i][cs]);
			count++;
		}
		cs++;
	}

	return spring;
}

int main()
{
	vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	vector<int> spring = printSpring(matrix);

	for (int i : spring)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}