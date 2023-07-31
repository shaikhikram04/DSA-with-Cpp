#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<string> q;
	q.push("Mohammed");
	q.push("Ikraam");
	q.push("Shaikh");
	cout<<"first element -> "<<q.front()<<endl;
	cout<<"Size before pop -> "<<q.size()<<endl;
	
	q.pop();
	cout<<"after pop"<<endl;
	cout<<"first element -> "<<q.front()<<endl;
	cout<<"Size after pop -> "<<q.size()<<endl;
	cout<<q.back();
	
	return 0;
}