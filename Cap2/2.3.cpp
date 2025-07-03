// C2:P6 - 2.3 Bit Manipulation
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = -43;
    unsigned int y = x;  // reinterpretación de los bits de x como unsigned

    cout << "Valor con signo (int): " << x << "\n";  // -43
    cout << "Valor sin signo (unsigned int): " << y << "\n";  // 4294967253 (si int es de 32 bits)

    // Explicación:
    // -43 en complemento a dos (32 bits) es: 11111111111111111111111111010101
    // Interpretar eso como unsigned es: 2^32 - 43 = 4294967253

    return 0;
}

