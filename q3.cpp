#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string str="hello";
	string array[str.size()];
	for(int i=0;i<str.size();i++){
		string strn=str;
		strn[i]=toupper(str[i]);
		array[i]=strn;
	}
	for(int i=0;i<str.size();i++){
		cout<<array[i]<<endl;
	}
	
	return 0;
}