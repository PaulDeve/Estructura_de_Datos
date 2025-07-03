// C5:p9 5.3.2 - Policy-Based Data Structures: Ordered Set
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Ordered Set
template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

int main() {
    ordered_set<int> s;

    s.insert(2);
    s.insert(3);
    s.insert(7);
    s.insert(9);

    cout << "--- Ordered Set (PBDS) ---\n";
    // Elemento en índice 1 (0-based)
    cout << "s[1] = " << *s.find_by_order(1) << "\n"; // 3

    // Cantidad de elementos < 7
    cout << "Elementos < 7: " << s.order_of_key(7) << "\n"; // 2

    // Elementos < 6
    cout << "Elementos < 6: " << s.order_of_key(6) << "\n"; // 2

    // Elementos < 3
    cout << "Elementos < 3: " << s.order_of_key(3) << "\n"; // 1

    // Borrar elemento
    s.erase(3);
    cout << "Después de borrar 3, s[1] = " << *s.find_by_order(1) << "\n"; // 7

    return 0;
}

