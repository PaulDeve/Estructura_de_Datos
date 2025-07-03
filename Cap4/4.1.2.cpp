// C4:p2 4.1.2 - Merge Sort
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& array, int a, int b) {
    int k = (a + b) / 2;
    int i = a, j = k + 1;
    vector<int> temp;
    while (i <= k && j <= b) {
        if (array[i] < array[j]) temp.push_back(array[i++]);
        else temp.push_back(array[j++]);
    }
    while (i <= k) temp.push_back(array[i++]);
    while (j <= b) temp.push_back(array[j++]);
    for (int i = a; i <= b; i++) array[i] = temp[i - a];
}

void mergeSort(vector<int>& array, int a, int b) {
    if (a >= b) return;
    int k = (a + b) / 2;
    mergeSort(array, a, k);
    mergeSort(array, k + 1, b);
    merge(array, a, b);
}

int main() {
    vector<int> array = {1, 3, 6, 2, 8, 2, 5, 9};
    mergeSort(array, 0, array.size() - 1);

    cout << "--- Merge Sort ---\n";
    for (int x : array) cout << x << " ";
    cout << "\n";

    return 0;
}

