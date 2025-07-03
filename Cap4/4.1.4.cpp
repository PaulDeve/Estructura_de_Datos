// C4:p3 4.1.4 - Counting Sort (O(n) para elementos pequeños)
#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& array, int c) {
    vector<int> count(c + 1, 0);
    for (int x : array) count[x]++;
    int index = 0;
    for (int i = 0; i <= c; i++) {
        while (count[i]--) {
            array[index++] = i;
        }
    }
}

int main() {
    vector<int> array = {1, 3, 6, 9, 9, 3, 5, 9};
    countingSort(array, 9);

    cout << "--- Counting Sort ---\n";
    for (int x : array) cout << x << " ";
    cout << "\n";

    return 0;
}

