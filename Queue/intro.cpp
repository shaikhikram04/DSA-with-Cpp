#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<int> q;
    q.push(6);
    q.push(5);
    q.push(41);
    q.push(12);
    cout << "size -> " << q.size() << endl;
    cout << "front element -> " << q.front() << endl;
    cout << "back element -> " << q.back() << endl;
    q.pop();
    q.pop();
    q.pop();
    cout << "after pop" << endl;
    cout << "size -> " << q.size() << endl;
    cout << "front element -> " << q.front() << endl;
    cout << "back element -> " << q.back() << endl;
    q.pop();
    if (q.empty()) {
        cout << "queue is empty" << endl;
    } else {
        cout << "queue is not empty" << endl;
    }
    return 0;
}