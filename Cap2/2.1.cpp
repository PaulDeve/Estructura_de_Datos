// C2:p1 2.1.1
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    int c, d;
    string m;
    string x;

    // Lectura con cin
    cin >> a >> b >> x;

    // Salida con cout
    cout << a << " " << b << " " << x << endl;

    // Lectura con scanf
    scanf("%d %d", &c, &d);

    // Salida con printf
    printf("%d %d\n", c, d);

    // Lectura de línea completa (getline)
    getline(cin, m);  // cuidado: puede quedar un salto de línea pendiente
    cout << m;

    // Lectura hasta EOF
    string p;
    while(cin >> p){
        cout << p << "\n";
    }

    return 0;
}
