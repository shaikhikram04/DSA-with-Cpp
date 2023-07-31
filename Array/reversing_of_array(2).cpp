#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v = {11, 4, 8, 19, 2, 29};
	
	reverse(v.begin(),v.end());
	cout<<"after reverse \n";
	for(int i:v){
		cout<<i<<"  ";
	}
	cout<<endl;
	return 0;
}