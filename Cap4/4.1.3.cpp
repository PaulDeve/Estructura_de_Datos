// C4:p12 4.1.3 - Radix Sort para enteros no negativos
#include <bits/stdc++.h>
using namespace std;

// Radix Sort por dígitos (base 10)
void radix_sort(vector<int>& array) {
    int max_element = *max_element(array.begin(), array.end());
    int exp = 1;

    while (max_element / exp > 0) {
        vector<vector<int>> buckets(10);  // 10 dígitos (0-9)

        for (int num : array) {
            int digit = (num / exp) % 10;
            buckets[digit].push_back(num);
        }

        array.clear();
        for (int d = 0; d < 10; d++) {
            for (int num : buckets[d]) {
                array.push_back(num);
            }
        }

        exp *= 10;
    }
}

int main() {
    vector<int> array = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "--- Antes de radix sort ---\n";
    for (int x : array) cout << x << " ";
    cout << "\n";

    radix_sort(array);

    cout << "--- Después de radix sort ---\n";
    for (int x : array) cout << x << " ";
    cout << "\n";

    return 0;
}

