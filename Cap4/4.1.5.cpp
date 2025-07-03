// C4:p4 4.1.5 - Usar sort de C++ STL
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {4, 2, 5, 3, 5, 8, 3};
    sort(v.begin(), v.end());
    cout << "Sort ascendente: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    sort(v.rbegin(), v.rend());
    cout << "Sort descendente: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    string s = "monkey";
    sort(s.begin(), s.end());
    cout << "String ordenado: " << s << "\n";

    vector<pair<int, int>> p = {{1, 5}, {2, 3}, {1, 2}};
    sort(p.begin(), p.end());
    cout << "Pares ordenados: ";
    for (auto pr : p) cout << "(" << pr.first << "," << pr.second << ") ";
    cout << "\n";

    vector<tuple<int, int, int>> t = {{2, 1, 4}, {1, 5, 3}, {2, 1, 3}};
    sort(t.begin(), t.end());
    cout << "Tuplas ordenadas: ";
    for (auto tp : t) {
        int a, b, c;
        tie(a, b, c) = tp;
        cout << "(" << a << "," << b << "," << c << ") ";
    }
    cout << "\n";

    return 0;
}

