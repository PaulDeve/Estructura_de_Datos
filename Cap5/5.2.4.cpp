// C5:p7 5.2.4 - Comparadores personalizados en set y sort
#include <bits/stdc++.h>
using namespace std;

// Estructura con 2 valores
struct Punto {
    int x, y;

    // Operador < personalizado para ordenar por x, y
    bool operator<(const Punto& otro) const {
        if (x != otro.x) return x < otro.x;
        return y < otro.y;
    }
};

int main() {
    set<Punto> puntos;
    puntos.insert({2, 5});
    puntos.insert({1, 3});
    puntos.insert({2, 2});
    puntos.insert({2, 5}); // duplicado, no se inserta

    cout << "--- Set con objetos y operador < ---\n";
    for (auto p : puntos) {
        cout << "(" << p.x << "," << p.y << ") ";
    }
    cout << "\n";

    // Comparador personalizado para sort: ordenar por y descendente
    vector<Punto> vec = {{1, 2}, {2, 4}, {3, 3}};
    sort(vec.begin(), vec.end(), [](const Punto& a, const Punto& b) {
        return a.y > b.y;
    });

    cout << "--- Sort por y descendente ---\n";
    for (auto p : vec) {
        cout << "(" << p.x << "," << p.y << ") ";
    }
    cout << "\n";

    return 0;
}

