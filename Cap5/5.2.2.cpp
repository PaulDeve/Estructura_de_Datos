// C5:p5 5.2.2 - Mapas en C++
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> m;
    m["uno"] = 1;
    m["dos"] = 2;
    m["tres"] = 3;

    cout << "--- Mapas: clave ? valor ---\n";
    cout << "uno = " << m["uno"] << "\n";
    cout << "dos = " << m["dos"] << "\n";

    // Iterar sobre el mapa
    for (auto [clave, valor] : m) {
        cout << clave << " ? " << valor << "\n";
    }

    // Contador de frecuencia con map
    map<int, int> frecuencia;
    vector<int> datos = {1, 2, 2, 3, 3, 3};
    for (int x : datos) frecuencia[x]++;
    cout << "--- Frecuencias ---\n";
    for (auto [x, f] : frecuencia) {
        cout << x << " aparece " << f << " veces\n";
    }

    return 0;
}

