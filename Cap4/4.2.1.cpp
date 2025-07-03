// C4:p6 4.2.1 - Sweep Line Algorithm: máximo número de clientes simultáneos
#include <bits/stdc++.h>
using namespace std;

int maxClientesSimultaneos(vector<pair<int, int>>& intervalos) {
    vector<pair<int, int>> eventos;
    for (auto [llegada, salida] : intervalos) {
        eventos.push_back({llegada, +1}); // llegada
        eventos.push_back({salida, -1});  // salida
    }

    sort(eventos.begin(), eventos.end());

    int clientes = 0, maximo = 0;
    for (auto [tiempo, tipo] : eventos) {
        clientes += tipo;
        maximo = max(maximo, clientes);
    }

    return maximo;
}

int main() {
    vector<pair<int, int>> clientes = {
        {1, 5}, {2, 6}, {4, 7}, {5, 8}
    };

    cout << "--- Sweep Line - Clientes ---\n";
    cout << "Máximo número de clientes al mismo tiempo: ";
    cout << maxClientesSimultaneos(clientes) << "\n";

    return 0;
}

