#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    if (a[n-1] != b[n-1]) {
        cout << "NO" << endl;
        return;
    }

    bool c0 = true; // can_be_0 for i+1
    bool c1 = false; // can_be_1 for i+1

    for (int i = n - 2; i >= 0; --i) {
        bool next_c0 = false;
        bool next_c1 = false;

        bool valid_suffix = c0 || c1;

        // Try x[i] = 0
        if (a[i] == b[i] && valid_suffix) {
            next_c0 = true;
        }

        // Try x[i] = 1
        // Option 1: use a[i+1] (requires valid_suffix)
        if ((a[i] ^ a[i+1]) == b[i] && valid_suffix) {
            next_c1 = true;
        }
        // Option 2: use b[i+1] (requires c1 from next step)
        if ((a[i] ^ b[i+1]) == b[i] && c1) {
            next_c1 = true;
        }

        c0 = next_c0;
        c1 = next_c1;
    }

    if (c0 || c1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

