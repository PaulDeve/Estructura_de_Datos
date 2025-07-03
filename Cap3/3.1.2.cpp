// C3:p12 3.1.2 - Complejidades de Tiempo Comunes
#include <bits/stdc++.h>
using namespace std;

// O(1) - constante
int ejemplo_constante(int a, int b) {
    return a + b; // operación directa
}

// O(log n) - búsqueda binaria
int ejemplo_logaritmico(vector<int>& v, int x) {
    int l = 0, r = v.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (v[m] == x) return m;
        if (v[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

// O(sqrt n) - conteo de divisores
int ejemplo_raiz(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) count += (i * i == n) ? 1 : 2;
    }
    return count;
}

// O(n) - suma de elementos
int ejemplo_lineal(vector<int>& v) {
    int suma = 0;
    for (int x : v) suma += x;
    return suma;
}

// O(n log n) - ordenamiento
void ejemplo_nlogn(vector<int>& v) {
    sort(v.begin(), v.end());
}

// O(n^2) - comparación de pares
int ejemplo_cuadratico(vector<int>& v) {
    int n = v.size(), count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (v[i] == v[j]) count++;
    return count;
}

// O(n^3) - comparación de ternas
int ejemplo_cubico(vector<int>& v) {
    int n = v.size(), count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (v[i] + v[j] == v[k]) count++;
    return count;
}

// O(2^n) - generación de subconjuntos
void ejemplo_exponencial(int n) {
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                subset.push_back(i + 1);
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
    }
}

// O(n!) - generación de permutaciones
void ejemplo_factorial(int n) {
    vector<int> perm;
    for (int i = 1; i <= n; i++) perm.push_back(i);
    do {
        for (int x : perm) cout << x << " ";
        cout << "\n";
    } while (next_permutation(perm.begin(), perm.end()));
}

// Función principal
int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    cout << "O(1) - Constante:\n";
    cout << ejemplo_constante(3, 4) << "\n\n";

    cout << "O(log n) - Búsqueda binaria:\n";
    cout << "Índice de 3: " << ejemplo_logaritmico(v, 3) << "\n\n";

    cout << "O(sqrt n) - Divisores de 36:\n";
    cout << ejemplo_raiz(36) << "\n\n";

    cout << "O(n) - Suma de vector:\n";
    cout << ejemplo_lineal(v) << "\n\n";

    cout << "O(n log n) - Ordenamiento:\n";
    ejemplo_nlogn(v);
    for (int x : v) cout << x << " ";
    cout << "\n\n";

    cout << "O(n^2) - Comparaciones dobles:\n";
    cout << ejemplo_cuadratico(v) << "\n\n";

    cout << "O(n^3) - Comparaciones triples:\n";
    cout << ejemplo_cubico(v) << "\n\n";

    cout << "O(2^n) - Subconjuntos (n = 3):\n";
    ejemplo_exponencial(3);
    cout << "\n";

    cout << "O(n!) - Permutaciones (n = 3):\n";
    ejemplo_factorial(3);
    cout << "\n";

    return 0;
}

