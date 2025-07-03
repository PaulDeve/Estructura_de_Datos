// C3:p15 3.2.1 - Maximum Subarray Sum (3 versiones)
#include <bits/stdc++.h>
using namespace std;

// O(n^3) - brute force con 3 bucles
int maxSubarraySum_n3(const vector<int>& array) {
    int best = 0;
    int n = array.size();
    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
            int sum = 0;
            for (int k = a; k <= b; k++) {
                sum += array[k];
            }
            best = max(best, sum);
        }
    }
    return best;
}

// O(n^2) - mejora sumando sobre la marcha
int maxSubarraySum_n2(const vector<int>& array) {
    int best = 0;
    int n = array.size();
    for (int a = 0; a < n; a++) {
        int sum = 0;
        for (int b = a; b < n; b++) {
            sum += array[b];
            best = max(best, sum);
        }
    }
    return best;
}

// O(n) - Kadane’s algorithm
int maxSubarraySum_n(const vector<int>& array) {
    int best = 0, sum = 0;
    for (int k = 0; k < array.size(); k++) {
        sum = max(array[k], sum + array[k]);
        best = max(best, sum);
    }
    return best;
}

int main() {
    vector<int> array = {-1, 2, 4, -3, 5, 2, -5, 2};

    cout << "--- Maximum Subarray Sum ---\n";
    cout << "Array: ";
    for (int x : array) cout << x << " ";
    cout << "\n\n";

    cout << "Versión O(n^3): " << maxSubarraySum_n3(array) << "\n";
    cout << "Versión O(n^2): " << maxSubarraySum_n2(array) << "\n";
    cout << "Versión O(n)  : " << maxSubarraySum_n(array) << " (Kadane)\n";

    return 0;
}

