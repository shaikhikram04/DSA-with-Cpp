#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, string> m;
	m[1] = "Mohammed";
	m[13] = "Shaikh";
	m[2] = "Ikraam";

	m.insert({6, "Dost"}); // here {6, "Dost"} is a pair 
						   // for insert a pair we can direct insert using above method
						   // or we have to first create pair and then insert it into map	

	for (auto i : m)
	{
		cout << i.first << "  " << i.second << endl;
	}

	//return 1 if 13 is present else false
	cout << "finding 13 -> " << m.count(13) << endl;
	m.erase(6);
	cout << "\nafter erase" << endl;
	for (auto i : m)
	{
		cout << i.first << "  " << i.second << endl;
	}
	auto it = m.find(2);

	for (auto i = it; i != m.end(); i++)
	{
		cout << (*i).first << endl;
	}

	return 0;
}