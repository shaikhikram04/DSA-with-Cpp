#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	string str ;
	cin>>str;
	char myarray[str.length()];
	for (int i = 0; i <str.length(); i++)
	{
		if (isupper(str[i]))
		{
			myarray[str.length()+1];
			myarray[i] =' ';
			for (int j = i + 1; j<str.length()+1; j++)
			{
				myarray[j] = str[j - 1];
			}
			break;
		}
		else
		{
			myarray[i] = str[i];
		}
	}
	/*for(char a : myarray){
		cout<<a;
	}*/
	for(int i=0;i<str.length()+1;i++){
		cout<<myarray[i];
	}
		return 0;
}