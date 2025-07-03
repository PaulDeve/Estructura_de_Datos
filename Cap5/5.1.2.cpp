// C5:p2 5.1.2 - Iteradores y Rangos
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {5, 2, 3, 1, 2, 5, 7, 1};

    cout << "--- Ordenar, invertir, mezclar ---\n";
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    random_shuffle(v.begin(), v.end());

    cout << "--- Primer elemento: " << *v.begin() << "\n";

    vector<int> a = {2, 3, 3, 5, 7, 8, 8, 8};
    auto it1 = lower_bound(a.begin(), a.end(), 5);
    auto it2 = upper_bound(a.begin(), a.end(), 5);
    cout << "--- lower_bound / upper_bound ---\n";
    cout << *it1 << " " << *it2 << "\n"; // 5 7

    // Eliminar duplicados
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    cout << "--- Elementos únicos ordenados ---\n";
    for (int x : a) cout << x << " ";
    cout << "\n";

    return 0;
}

