#include <iostream>
#include <queue>
using namespace std;

int main()
{
	//max heap
	priority_queue<int> maxi;

	//min heap
	priority_queue<int, vector<int>, greater<int>> mini;

	maxi.push(2);
	maxi.push(3);
	maxi.push(1);
	maxi.push(0);

	int n = maxi.size();
	for (int i = 0; i < n; i++)
	{
		cout<<maxi.top()<<"  ";
		maxi.pop();
	}
	cout<<endl;
	
	mini.push(3);
	mini.push(1);
	mini.push(4);
	mini.push(0);
	mini.push(2);
	
	int m=mini.size();
	for(int i=0;i<m;i++){
		cout<<mini.top()<<"  ";
		mini.pop();		
	}
	cout<<endl;
	
	cout<<"Empty or not -> "<<mini.empty();
	return 0;
}