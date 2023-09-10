#include <iostream>
using namespace std;

void reverseArr(char arr[], int size)
{
	int s = 0, e = size - 1;
	while (s < e)
	{
		swap(arr[s], arr[e]);
		s++;
		e--;
	}
}

int getLength(char arr[])
{
	int count = 0;
	for (int i = 0; arr[i] != '\0'; i++)
		count++;
	return count;
}

int main()
{
	char name[20];
	cout << "Enter your name : ";
	cin >> name;
	int len = getLength(name);
	cout << "Your name is " << name << endl;
	cout << "Length : " << len << endl;
	reverseArr(name,len);
	cout<<"After reverse \n"<<name << endl;
	
	char arr[] = {'a', 'b', '\0', 'c', 'd'};
	string str = {'a', 'b', '\0', 'c', 'd'};
	cout << arr << endl;
	cout << str << endl;
	return 0;
}