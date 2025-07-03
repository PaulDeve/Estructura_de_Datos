// C4:p5 4.2 - Verificar si todos los elementos de un arreglo son únicos
#include <bits/stdc++.h>
using namespace std;

bool sonUnicos(vector<int>& array) {
    sort(array.begin(), array.end());
    for (int i = 1; i < array.size(); i++) {
        if (array[i] == array[i - 1])
            return false;
    }
    return true;
}

int main() {
    vector<int> A = {4, 2, 5, 3, 5, 8, 3};
    vector<int> B = {1, 2, 3, 4, 5};

    cout << "--- Verificación de unicidad ---\n";
    cout << "A tiene repetidos: " << (!sonUnicos(A) ? "sí" : "no") << "\n";
    cout << "B tiene repetidos: " << (!sonUnicos(B) ? "sí" : "no") << "\n";

    return 0;
}

