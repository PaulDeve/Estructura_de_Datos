// C4:p9 4.3.1 - Binary Search tradicional
#include <bits/stdc++.h>
using namespace std;

bool busquedaBinariaTradicional(const vector<int>& array, int x) {
    int a = 0, b = array.size() - 1;
    while (a <= b) {
        int k = (a + b) / 2;
        if (array[k] == x) return true;
        if (array[k] < x) a = k + 1;
        else b = k - 1;
    }
    return false;
}

int main() {
    vector<int> v = {1, 3, 4, 5, 6, 9, 10, 12, 15};
    cout << "--- Binary Search tradicional ---\n";
    cout << "¿Está el 9? " << (busquedaBinariaTradicional(v, 9) ? "Sí" : "No") << "\n";
    cout << "¿Está el 7? " << (busquedaBinariaTradicional(v, 7) ? "Sí" : "No") << "\n";
    return 0;
}

