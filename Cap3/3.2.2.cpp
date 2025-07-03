// C3:p16 3.2.2 - Two Queens Problem
#include <bits/stdc++.h>
using namespace std;

// Verifica si dos reinas se atacan entre sí
bool seAtacan(int x1, int y1, int x2, int y2) {
    return x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2);
}

// O(n^4) - fuerza bruta
int dosReinasBruteForce(int n) {
    int count = 0;
    for (int x1 = 0; x1 < n; x1++) {
        for (int y1 = 0; y1 < n; y1++) {
            for (int x2 = 0; x2 < n; x2++) {
                for (int y2 = 0; y2 < n; y2++) {
                    if (x1 == x2 && y1 == y2) continue;
                    if (!seAtacan(x1, y1, x2, y2)) count++;
                }
            }
        }
    }
    return count / 2; // cada par se cuenta dos veces
}

// O(n) - recursiva optimizada
int dosReinasRecursiva(int n) {
    if (n <= 2) return 0;
    if (n == 3) return 8;
    return dosReinasRecursiva(n - 1) + 2 * (n - 1) * (n - 1) * (n - 2);
}

// O(1) - fórmula cerrada: q(n) = (3n^4 - 10n^3 + 9n^2 - 2n) / 6
int dosReinasFormula(int n) {
    if (n <= 2) return 0;
    return (3 * n * n * n * n - 10 * n * n * n + 9 * n * n - 2 * n) / 6;
}

int main() {
    vector<int> tests = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "--- Two Queens Problem ---\n\n";

    for (int n : tests) {
        cout << "n = " << n << " ? ";
        cout << "BruteForce = " << dosReinasBruteForce(n) << ", ";
        cout << "Recursiva = " << dosReinasRecursiva(n) << ", ";
        cout << "Fórmula = " << dosReinasFormula(n) << "\n";
    }

    return 0;
}

