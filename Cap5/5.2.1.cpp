// C5:p4 5.2.1 - Set y Multiset
#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "--- Set (únicos, ordenados) ---\n";
    set<int> s;
    s.insert(3);
    s.insert(5);
    s.insert(2);
    s.insert(5); // duplicado, ignorado

    for (int x : s) cout << x << " "; // 2 3 5
    cout << "\n";

    cout << "¿Contiene 3?: " << (s.count(3) ? "sí" : "no") << "\n";
    cout << "¿Contiene 4?: " << (s.count(4) ? "sí" : "no") << "\n";

    s.erase(3); // elimina el 3
    cout << "Después de borrar 3: ";
    for (int x : s) cout << x << " "; // 2 5
    cout << "\n";

    cout << "--- Multiset (permite duplicados) ---\n";
    multiset<int> ms;
    ms.insert(5);
    ms.insert(5);
    ms.insert(3);
    ms.insert(8);

    for (int x : ms) cout << x << " "; // 3 5 5 8
    cout << "\n";

    ms.erase(ms.find(5)); // elimina una sola ocurrencia de 5
    for (int x : ms) cout << x << " "; // 3 5 8
    cout << "\n";

    return 0;
}

