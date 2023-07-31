#include <string>
#include <vector>
using namespace std;
int countSmileys(vector<string> arr)
{
	int count = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		string str = arr[i];
		if ((str[0] == ':' || str[0] == ';') && (str[1] == 'D' || str[1] == ')'))
			count++;

		if ((str[0] == ':' || str[0] == ';') && (str[1] == '-' || str[1] == '~') && (str[2] == 'D' || str[2] == ')'))
			count++;
	}
	return count;
}