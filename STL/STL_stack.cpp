#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<string> s;
	s.push("One");
	s.push("Two");
	s.push("Three");
	
	cout<<"top element "<<s.top()<<endl;
	s.pop();
	cout<<"top element "<<s.top()<<endl;
	cout<<"size is "<<s.size()<<endl;
	cout<<"Empty or not -> "<<s.empty()<<endl;
	return 0;
}