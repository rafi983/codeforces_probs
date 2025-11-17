#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve_test_case() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    if (n == 1) {
        return 0;
    }

    int min_val = *min_element(arr.begin(), arr.end());
    int max_val = *max_element(arr.begin(), arr.end());

    if ((min_val + max_val) % 2 == 0) {
        return 0;
    }

    int min_operations = n; // Worst case: remove all elements except one

    for (int i = 0; i < n; ++i) {
        int potential_min = arr[i];

        for (int j = 0; j < n; ++j) {
            int potential_max = arr[j];

            if ((potential_min + potential_max) % 2 != 0 || potential_min > potential_max) {
                continue;
            }

            int operations = 0;
            for (int k = 0; k < n; ++k) {
                // Remove if element is smaller than new min or larger than new max
                if (arr[k] < potential_min || arr[k] > potential_max) {
                    ++operations;
                }
            }

            if (operations < min_operations) {
                min_operations = operations;
            }
        }
    }

    return min_operations;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int result = solve_test_case();
        cout << result << '\n';
    }

    return 0;
}

