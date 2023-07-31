#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int sum_intervals(vector<pair<int, int>> intervals)
{
	int a, b, sum = 0;
	for (int i = 0; i < intervals.size(); i++)
	{
		a = intervals[i].first;
		b = intervals[i].second;
		for (int j = i + 1; j < intervals.size(); j++)
		{
			if (intervals[j].first <= b)
			{
				if (intervals[j].second > b)
					b = intervals[j].second;

				if (intervals[j].first < a)
					a = intervals[j].first;

				intervals.erase(intervals.begin() + j);
			}
		}
		sum += b - a;
	}
	return sum;
}

int main()
{
	vector<pair<int, int>> interval;
	interval = {make_pair(61, 438), make_pair(359, 424), make_pair(405, 453),make_pair(393,399)};
	cout << sum_intervals(interval);
	return 0;
}