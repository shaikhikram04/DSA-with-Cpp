#include <vector>
#include <iostream>
using namespace std;
int score(const std::vector<int> &dice)
{
	int points = 0;
	int count;
	for (int f = 1; f <= 6; f++)
	{
		count = 0;
		for (int i = 0; i < dice.size(); i++)
		{
			if (dice[i] == f)
			{
				count++;
			}
		}
		if (count > 3)
		{
			if (f == 1)
			{
				points += 1000;
			}
			else
			{
				points += f * 100;
			}
			count = count - 3;
			if (f == 1)
				points += count * 100;
			if (f == 5)
				points += count * 50;
		}
		else if (count == 3)
		{
			if (f == 1)
			{
				points += 1000;
			}
			else
			{
				points += f * 100;
			}
		}
		else
		{
			if (f == 1)
				points += count * 100;
			if (f == 5)
				points += count * 50;
		}
	}
	return points;
}

int main()
{
	const std::vector<int> dice = {2,4,4,5,4};
	std::cout << score(dice);
	return 0;
}