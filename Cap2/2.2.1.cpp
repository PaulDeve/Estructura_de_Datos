#include <bits/stdc++.h>
using namespace std;

int n = 3; // Valor fijo para pruebas: subconjuntos de {1, 2, 3}
vector<int> subset;

void search(int k) {
    if (k == n + 1) {
        // Mostrar subconjunto generado
        cout << "{";
        for (size_t i = 0; i < subset.size(); i++) {
            cout << subset[i] << (i + 1 < subset.size() ? ", " : "");
        }
        cout << "}\n";
        return;
    }
    // Incluir k en el subconjunto
    subset.push_back(k);
    search(k + 1);

    // No incluir k
    subset.pop_back();
    search(k + 1);
}

int main() {
    search(1);
    return 0;
}

