#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	deque<int> d;
	d.push_back(3);
	d.push_back(4);
	for (int i : d)
		cout << i << " ";
	cout << endl;

	d.push_front(2);
	d.push_front(1);
	for (int i : d)
		cout << i << " ";
	cout << endl;

	//removing first and last element
	d.pop_front();
	d.pop_back();
	for (int i : d)
		cout << i << " ";
	cout << endl;

	cout << "Printing first index element " << d.at(1) << endl;

	cout << "First element is " << d.front() << endl;
	cout << "Last element is " << d.back() << endl;

	cout << "Empty or not -> " << d.empty() << endl;

	cout << "after erase" << endl;
	d.erase(d.begin(), d.begin() + 1);
	for (int i : d)
		cout << i << " ";
	cout << endl;
	deque<char> d2 = {'h', 'e', 'l', 'l', 'o'};
	return 0;
}