// C4:p7 4.2.2 - Seleccionar la mayor cantidad de eventos compatibles (Greedy)
#include <bits/stdc++.h>
using namespace std;

int eventosMaximos(vector<pair<int, int>>& eventos) {
    sort(eventos.begin(), eventos.end(), [](auto& a, auto& b) {
        return a.second < b.second; // ordenar por tiempo de fin
    });

    int finAnterior = 0, contador = 0;
    for (auto [inicio, fin] : eventos) {
        if (inicio >= finAnterior) {
            contador++;
            finAnterior = fin;
        }
    }
    return contador;
}

int main() {
    vector<pair<int, int>> eventos = {
        {1, 5}, {3, 9}, {0, 6}, {5, 7}, {8, 9}
    };

    cout << "--- Scheduling Events ---\n";
    cout << "Cantidad máxima de eventos compatibles: ";
    cout << eventosMaximos(eventos) << "\n";

    return 0;
}

