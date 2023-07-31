#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	cout << "Capacity is " << v.capacity() << endl;

	v.push_back(1);
	cout << "Capacity is " << v.capacity() << endl;
	v.push_back(2);
	cout << "Capacity is " << v.capacity() << endl;
	v.push_back(3);
	cout << "Capacity is " << v.capacity() << endl;
	//capacity of vector got double when we add extra element

	//this show no. of element present in a vector
	cout << "Size is " << v.size() << endl;

	//print element using index
	cout << "element at index 1 is " << v.at(1) << endl;
	cout << "element at index 1 is " << v[1] << endl;

	//print first and last element
	cout << "First element is " << v.front() << endl;
	cout << "Last element is " << v.back() << endl;

	//removing last element of a vector
	cout << "\nBefore pop" << endl;
	for (int i : v)
		cout << i << " ";

	v.pop_back();

	cout << "\nAfter pop" << endl;
	for (int i : v)
		cout << i << " ";
	cout << endl;
	//clear a vector
	v.clear();
	cout << "Size after clearing is " << v.size() << endl;
	cout << "Capacity after clearing is " << v.capacity() << endl;
	// NOTE : AFTER CLEARING VECTOR ONLY SIZE WILL BECOME ZERO , CAPACITY WILL REMAIN SAME

	//Assigning vector with capacity
	vector<int> v2(5, 1); //implise that a vector of name v2 with size 5 and all element is 1.
	//if we not assign 1 then it is by default 0
	cout << "print v2" << endl;
	for (int i : v2)
		cout << i << " ";
	cout << endl;

	//copy an elements of existing vector to a new vector
	cout << "print v3" << endl;
	vector<int> v3(v2);
	for (int i : v3)
		cout << i << " ";
	cout << endl;
	vector<int> num = {6, 8, 2, 73, 52, 91, 4, 2, 6};
	for (int i : num)
		cout << i << " ";
	cout << endl;
	num.erase(num.begin()+3,num.begin()+6);
	for (int i : num)
		cout << i << " ";
	cout << endl;
	return 0;
}