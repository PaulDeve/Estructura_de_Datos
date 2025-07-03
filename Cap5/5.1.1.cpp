// C5:p1 5.1.1 - Vectores en C++
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(3); // [3]
    v.push_back(2); // [3,2]
    v.push_back(5); // [3,2,5]

    cout << "--- Vector básico ---\n";
    cout << v[0] << " " << v[1] << " " << v[2] << "\n";

    vector<int> w = {2, 4, 2, 5, 1};
    vector<int> a(8);      // [0, 0, 0, 0, 0, 0, 0, 0]
    vector<int> b(8, 2);   // [2, 2, 2, 2, 2, 2, 2, 2]

    cout << "--- Iteración con índices ---\n";
    for (int i = 0; i < w.size(); i++) {
        cout << w[i] << " ";
    }
    cout << "\n";

    cout << "--- Iteración con for-each ---\n";
    for (auto x : w) {
        cout << x << " ";
    }
    cout << "\n";

    cout << "--- back() y pop_back() ---\n";
    cout << w.back() << "\n";  // 1
    w.pop_back();
    cout << w.back() << "\n";  // 5

    return 0;
}

