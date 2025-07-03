// C5:p10 5.3.3 - Function Objects y Lambdas
#include <bits/stdc++.h>
using namespace std;

// Functor (function object)
struct Mayor {
    bool operator()(int a, int b) const {
        return a > b;
    }
};

int main() {
    vector<int> v = {3, 1, 4, 2, 5};

    cout << "--- Sort con functor personalizado (Mayor) ---\n";
    sort(v.begin(), v.end(), Mayor());
    for (int x : v) cout << x << " ";  // 5 4 3 2 1
    cout << "\n";

    cout << "--- Sort con lambda (menor por defecto) ---\n";
    sort(v.begin(), v.end(), [](int a, int b) {
        return a < b;
    });
    for (int x : v) cout << x << " ";  // 1 2 3 4 5
    cout << "\n";

    cout << "--- Uso de set con comparador por lambda ---\n";
    auto comp = [](int a, int b) {
        return a > b; // orden descendente
    };
    set<int, decltype(comp)> s(comp);
    s.insert(3);
    s.insert(1);
    s.insert(4);

    for (int x : s) cout << x << " ";  // 4 3 1
    cout << "\n";

    return 0;
}

