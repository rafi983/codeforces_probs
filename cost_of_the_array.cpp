#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == k) {
        vector<int> b;
        for (int i = 1; i < n; i += 2) {
            b.push_back(a[i]);
        }
        b.push_back(0);

        for (int i = 0; i < b.size(); ++i) {
            if (b[i] != i + 1) {
                cout << i + 1 << endl;
                return;
            }
        }
    } else {
        // We check if we can make the first element of b not equal to 1.
        // The first element of b is the first element of the second subarray (S2).
        // S2 can start at any index i (0-based) such that:
        // 1. We have at least 1 element before it for S1 (i >= 1).
        // 2. We have enough elements starting from i to form S2...Sk (k-1 subarrays).
        //    So (n - i) >= k - 1. => i <= n - k + 1.

        bool found_non_1 = false;
        for (int i = 1; i <= n - k + 1; ++i) {
            if (a[i] != 1) {
                found_non_1 = true;
                break;
            }
        }

        if (found_non_1) {
            cout << 1 << endl;
        } else {
            // If all possible starts for S2 are 1, then b[1] must be 1.
            // Since n > k, we have enough "slack" to ensure b[2] = 1.
            // Since b[2] should be 2 for a match, b[2]=1 implies a mismatch at index 2.
            // Thus the cost is 2.
            cout << 2 << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

