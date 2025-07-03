// C3:p13 3.1.3 - Estimación de eficiencia por complejidad
#include <bits/stdc++.h>
using namespace std;

void estimar_operaciones(int n) {
    cout << fixed << setprecision(1);
    cout << "\nEstimaciones de operaciones para n = " << n << ":\n";

    cout << "O(1)       ˜ " << 1 << " operación\n";
    cout << "O(log n)   ˜ " << log2(n) << " operaciones\n";
    cout << "O(vn)      ˜ " << sqrt(n) << " operaciones\n";
    cout << "O(n)       ˜ " << n << " operaciones\n";
    cout << "O(n log n) ˜ " << n * log2(n) << " operaciones\n";
    cout << "O(n^2)     ˜ " << 1LL * n * n << " operaciones\n";
    cout << "O(n^3)     ˜ " << 1LL * n * n * n << " operaciones\n";
    cout << "O(2^n)     ˜ " << pow(2, min(n, 30)) << " operaciones (limitado a n <= 30)\n";
    cout << "O(n!)      ˜ ";

    long double fact = 1;
    for (int i = 1; i <= min(n, 20); i++) fact *= i;
    cout << fact << " operaciones (limitado a n <= 20)\n";
}

void sugerencia_por_limite(int n) {
    cout << "\nSugerencia de complejidad si n = " << n << ":\n";

    if (n <= 10) cout << "? Puedes usar O(n!)\n";
    else if (n <= 20) cout << "? Puedes usar O(2^n)\n";
    else if (n <= 500) cout << "? Puedes usar O(n^3)\n";
    else if (n <= 5000) cout << "? Puedes usar O(n^2)\n";
    else if (n <= 1e6) cout << "? O(n log n) o O(n) es lo adecuado\n";
    else cout << "? Solo O(n), O(log n) u O(1) funcionarán\n";
}

int main() {
    vector<int> tests = {10, 20, 500, 5000, 100000, 1000000, 10000000};
    for (int n : tests) {
        estimar_operaciones(n);
        sugerencia_por_limite(n);
        cout << "----------------------------\n";
    }

    return 0;
}

