#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> b(n + 1);
        vector<int> a(n + 1);

        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }

        // For each position i, determine a[i]
        for (int i = 1; i <= n; ++i) {
            long long diff;
            if (i == 1) {
                diff = b[1];
            } else {
                diff = b[i] - b[i - 1];
            }

            // diff tells us the distance to the last occurrence
            // If diff == i, it's a new element
            // Otherwise, the last occurrence was at position i - diff

            int last_pos = i - diff;

            if (last_pos == 0) {
                // This is a new element, assign any value we haven't used
                // or just assign i
                a[i] = i;
            } else {
                // Copy the value from the last occurrence
                a[i] = a[last_pos];
            }
        }

        // Print the result
        for (int i = 1; i <= n; ++i) {
            cout << a[i];
            if (i < n) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}

