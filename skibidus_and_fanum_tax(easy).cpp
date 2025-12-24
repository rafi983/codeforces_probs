#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<long long> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];

    long long B = b[0];
    long long current_val = -4e18; // Start with a very small number

    bool possible = true;
    for (int i = 0; i < n; ++i) {
        long long v1 = a[i];
        long long v2 = B - a[i];

        // We want the smallest value >= current_val
        if (v1 > v2) swap(v1, v2);

        if (v1 >= current_val) {
            current_val = v1;
        } else if (v2 >= current_val) {
            current_val = v2;
        } else {
            possible = false;
            break;
        }
    }

    if (possible) cout << "YES" << endl;
    else cout << "NO" << endl;
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

