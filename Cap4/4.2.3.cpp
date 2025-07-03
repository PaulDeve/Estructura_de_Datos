// C4:p8 4.2.3 - Maximizar score: deadline - tiempo de finalizaci�n
#include <bits/stdc++.h>
using namespace std;

int maximizarScore(vector<pair<int, int>>& tareas) {
    sort(tareas.begin(), tareas.end()); // ordenar por duraci�n

    int tiempo = 0, totalScore = 0;
    for (auto [duracion, deadline] : tareas) {
        tiempo += duracion;
        totalScore += deadline - tiempo;
    }
    return totalScore;
}

int main() {
    // {duraci�n, deadline}
    vector<pair<int, int>> tareas = {
        {2, 8}, {3, 10}, {4, 2}, {4, 15}
    };

    cout << "--- Tasks and Deadlines ---\n";
    cout << "Puntaje total �ptimo: ";
    cout << maximizarScore(tareas) << "\n";

    return 0;
}

