#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> p(n);
    vector<int> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b;
    if (n > 0) {
        b.push_back(a[0]);
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[i-1]) {
                b.push_back(a[i]);
            }
        }
    }

    // Check duplicates in b
    vector<bool> seen(n + 1, false);
    for (int x : b) {
        if (seen[x]) {
            cout << "NO" << endl;
            return;
        }
        seen[x] = true;
    }

    // Check order
    int last_idx = -1;
    for (int x : b) {
        int idx = pos[x];
        if (idx < last_idx) {
            cout << "NO" << endl;
            return;
        }
        last_idx = idx;
    }

    cout << "YES" << endl;
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

