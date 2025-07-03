// C4:p1 4.1.1 - Bubble Sort
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& array) {
    int n = array.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> array = {1, 3, 8, 2, 9, 2, 5, 6};
    bubbleSort(array);

    cout << "--- Bubble Sort ---\n";
    for (int x : array) cout << x << " ";
    cout << "\n";

    return 0;
}

