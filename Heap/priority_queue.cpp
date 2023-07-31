#include <iostream>
#include <queue>
using namespace std;
 

int main() {

    // max heap
    priority_queue<int> pq;
    pq.push(70);
    pq.push(49);
    pq.push(57);
    pq.push(64);
    pq.emplace(84);

    cout << "root element -> " << pq.top() << endl;
    pq.pop();
    cout << "root element -> " << pq.top() << endl;


    // min heap
    priority_queue<int, vector<int> , greater<int> > minHeap;
    minHeap.push(70);
    minHeap.push(49);
    minHeap.push(57);
    minHeap.push(64);
    minHeap.emplace(84);

    cout << "root element of minHeap -> " << minHeap.top() << endl;
    minHeap.pop();
    cout << "root element of minHeap -> " << minHeap.top() << endl;
    
    return 0;
}