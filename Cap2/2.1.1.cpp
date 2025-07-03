#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); // Mejora la velocidad de cin y cout
    cin.tie(0);               // Evita que cin espere a cout

    int a, b;
    int c, d;
    string m, x, p;

    // Entrada est�ndar con cin
    cin >> a >> b >> x;
    cout << a << " " << b << " " << x << endl;

    // Entrada est�ndar con scanf
    scanf("%d %d", &c, &d);
    printf("%d %d\n", c, d);

    // Leer l�nea completa
    cin.ignore(); // limpia el buffer antes de usar getline
    getline(cin, m);
    cout << m << "\n";

    // Leer entradas hasta EOF
    while (cin >> p) {
        cout << p << "\n";
    }

    return 0;
}

