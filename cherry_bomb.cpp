#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;

    vector<long long> a(n);
    long long min_a = -1;
    long long max_a = -1;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0) {
            min_a = a[i];
            max_a = a[i];
        } else {
            min_a = min(min_a, a[i]);
            max_a = max(max_a, a[i]);
        }
    }

    vector<long long> b(n);
    long long fixed_x = -1;
    bool possible = true;

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] != -1) {
            long long current_x = a[i] + b[i];
            if (fixed_x == -1) {
                fixed_x = current_x;
            } else {
                if (fixed_x != current_x) {
                    possible = false;
                }
            }
        }
    }

    if (!possible) {
        cout << 0 << "\n";
        return;
    }

    long long L = max_a;
    long long R = min_a + k;

    if (L > R) {
        cout << 0 << "\n";
        return;
    }

    if (fixed_x != -1) {
        if (fixed_x >= L && fixed_x <= R) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    } else {
        cout << (R - L + 1) << "\n";
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

