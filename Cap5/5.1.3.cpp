// C5:p3 5.1.3 - Deque, Stack y Queue
#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "--- Deque ---\n";
    deque<int> d;
    d.push_back(5);  // [5]
    d.push_back(2);  // [5,2]
    d.push_front(3); // [3,5,2]
    d.pop_back();    // [3,5]
    d.pop_front();   // [5]
    for (int x : d) cout << x << " ";
    cout << "\n";

    cout << "--- Stack ---\n";
    stack<int> s;
    s.push(2);
    s.push(5);
    cout << s.top() << "\n"; // 5
    s.pop();
    cout << s.top() << "\n"; // 2

    cout << "--- Queue ---\n";
    queue<int> q;
    q.push(2);
    q.push(5);
    cout << q.front() << "\n"; // 2
    q.pop();
    cout << q.back() << "\n";  // 5

    return 0;
}

