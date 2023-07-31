#include <iostream>
using namespace std;

int main()
{
	int m,n;
	cout<<"Enter row of a matrix : ";
	cin>>m;
	cout<<"Enter column of a matrix : ";
	cin>>n;
	
	// creating 2D array
	int** arr=new int*[m];
	for(int i=0; i<m; i++){
		arr[i] = new int[n];
	}
	
	// taking input for 2D array
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	cout << endl;
	
	// printing 2D array
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}