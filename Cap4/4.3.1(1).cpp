// C4:p10 4.3.1 - Binary Search con saltos desde la izquierda
#include <bits/stdc++.h>
using namespace std;

bool busquedaBinariaSaltos(const vector<int>& array, int x) {
    int n = array.size();
    int k = 0;
    for (int b = n / 2; b >= 1; b /= 2) {
        while (k + b < n && array[k + b] <= x) {
            k += b;
        }
    }
    return (array[k] == x);
}

int main() {
    vector<int> v = {1, 3, 4, 5, 6, 9, 10, 12, 15};
    cout << "--- Binary Search con saltos ---\n";
    cout << "¿Está el 9? " << (busquedaBinariaSaltos(v, 9) ? "Sí" : "No") << "\n";
    cout << "¿Está el 7? " << (busquedaBinariaSaltos(v, 7) ? "Sí" : "No") << "\n";
    return 0;
}

