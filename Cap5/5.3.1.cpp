// C5:p8 5.3.1 - Bitsets en C++
#include <bits/stdc++.h>
using namespace std;

int main() {
    bitset<10> b1(string("1010010010"));
    bitset<10> b2(string("1111000011"));

    cout << "--- Bitset básico ---\n";
    cout << "b1: " << b1 << "\n";
    cout << "b2: " << b2 << "\n";

    // Operaciones
    cout << "AND  : " << (b1 & b2) << "\n";
    cout << "OR   : " << (b1 | b2) << "\n";
    cout << "XOR  : " << (b1 ^ b2) << "\n";
    cout << "NOT b1: " << (~b1) << "\n";

    // Contar bits encendidos
    cout << "b1 tiene " << b1.count() << " bits en 1\n";

    // Acceder y modificar bits
    cout << "b1[3] = " << b1[3] << "\n";
    b1[3] = 1;
    cout << "b1 después de b1[3] = 1: " << b1 << "\n";

    // Comparar y chequear estado
    cout << "Algún bit en b1 está activado? " << (b1.any() ? "sí" : "no") << "\n";
    cout << "Ningún bit en b1 activado? " << (b1.none() ? "sí" : "no") << "\n";

    // Shift left y right
    cout << "b1 << 1: " << (b1 << 1) << "\n";
    cout << "b1 >> 2: " << (b1 >> 2) << "\n";

    return 0;
}

