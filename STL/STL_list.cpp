#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> l;
	l.push_back(3);
	l.push_back(4);
	for (int i : l)
		cout << i << " ";
	cout << endl;

	l.push_front(2);
	l.push_front(1);
	for (int i : l)
		cout << i << " ";
	cout << endl;
	
	cout<<"After Erase"<<endl;
	l.erase(l.begin());
	for (int i : l)
		cout << i << " ";
	cout << endl;
	return 0;
}