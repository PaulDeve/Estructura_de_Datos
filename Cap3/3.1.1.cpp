// C3:p1 3.1.1
#include <bits/stdc++.h>
using namespace std;

void ejemplos() {
    int a = 1, b = 2, c;

    // O(1)
    a++; b++; c = a + b;

    int n = 100;

    // O(n)
    for (int i = 1; i <= n; i++) {
        // ...
    }

    // O(n^2)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // ...
        }
    }

    // O(n^2) ejemplo triangular
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            // ...
        }
    }
}

