#include <iostream>
using namespace std;

int main()
{
	int num;
	cin>>num;
	
	int m = num;
	int mask = 0;
	if(num==0){
		cout<<"1";
		goto end;
	}
	while (m != 0)
	{
		mask = (mask << 1) | 1;
		m = m >> 1;
	}
	int ans;
	ans = (~num) & mask;
	cout<<ans;
	end:
	cout<<endl;
	return 0;
}