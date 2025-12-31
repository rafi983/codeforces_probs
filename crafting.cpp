#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<long long> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector<long long> d(n);
    int neg_count = 0;
    int neg_index = -1;

    for (int i = 0; i < n; ++i) {
        d[i] = a[i] - b[i];
        if (d[i] < 0) {
            neg_count++;
            neg_index = i;
        }
    }

    if (neg_count == 0) {
        cout << "YES" << endl;
        return;
    }

    if (neg_count > 1) {
        cout << "NO" << endl;
        return;
    }

    // neg_count == 1
    long long needed = -d[neg_index];
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        if (i == neg_index) continue;
        if (d[i] < needed) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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

