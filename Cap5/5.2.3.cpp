// C5:p6 5.2.3 - Priority Queue
#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(3);
    pq.push(5);
    pq.push(7);
    pq.push(2);

    cout << "--- Priority Queue (máximo primero) ---\n";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";

    // Para tener mínimo primero:
    priority_queue<int, vector<int>, greater<int>> pq_min;
    pq_min.push(3);
    pq_min.push(5);
    pq_min.push(7);
    pq_min.push(2);

    cout << "--- Priority Queue (mínimo primero) ---\n";
    while (!pq_min.empty()) {
        cout << pq_min.top() << " ";
        pq_min.pop();
    }
    cout << "\n";

    return 0;
}

