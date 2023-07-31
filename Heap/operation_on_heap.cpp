#include <iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index/2;

            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        } cout << endl;
    }

    void deleteRoot() {
        if (size == 0) {
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        // take root node to its correct position
        int i = 1;
        while (i < size) {
            int largest = i;
            int l = 2*i;
            int r = 2*i + 1;

            if (l <= size && arr[l] > arr[largest]) 
                largest = l;
            
            if (r <= size && arr[r] > arr[largest])
                largest = r;

            if (largest != i) {
                swap(arr[largest], arr[i]); 
                i = largest;
            }
            else {
                return;
            }
        }
    }
};

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i;
    int r = 2*i + 1;

    if (l <= n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r <= n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int size) {

    while (size > 1) {
        swap(arr[1], arr[size]);
        size--; 
        heapify(arr, size, 1);
    }
    
}


int main() {
    heap h;

    h.insert(60);
    h.insert(30);
    h.insert(20);
    h.insert(50);
    h.insert(40);
    h.insert(55);
    h.insert(70);

    h.print();

    h.deleteRoot();
    cout << "after delete" << endl;
    h.print();


    int arr[8] = {-1, 40, 70, 62, 90, 51, 42, 80};
    int n = 7;
    for (int i = n/2 ; i > 0; i--)
        heapify(arr, n, i);

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    heapSort(arr, n);
    cout << "after heapify" << endl;
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}