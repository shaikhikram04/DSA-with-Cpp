#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;

	s.insert(5);
	s.insert(5);
	s.insert(3);
	s.insert(6);
	s.insert(0);
	s.insert(0);
	s.insert(6);
	s.insert(2);

	//* s.erase(s.begin());
	cout << "First element -> " << *s.begin() << endl;
	for (int i : s)
	{
		cout << i << " ";
	}
	cout << endl;

	set<int>::iterator it = s.begin();
	it++;

	s.erase(it);

	for (int i : s)
	{
		cout << i << " ";
	}
	cout << endl;

	cout << "5 is present -> " << s.count(5) << endl;

	set<int>::iterator itr = s.find(5);
	cout << "5 is present at index " << *itr << endl;

	for (auto it = itr; it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}