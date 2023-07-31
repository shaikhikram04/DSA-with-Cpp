#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter degree of square array : ";
	
	// taking size of 2D array as input
	cin >> n;
	
	// creating 2D array
	int **arr = new int *[n];  // creating a double pointer the array of pointer of size n
	for (int i = 0; i < n; i++){
		arr[i] = new int[n]; // make array of size n for each pointer
	}
	
	// taking input for 2D array
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	cout << endl;
	
	// printing 2D array
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}