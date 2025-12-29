#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 1);

    sort(p.begin(), p.end(), [&](int u, int v) {
        if (u < v) {
            return g[u-1][v-1] == '1';
        } else {
            return g[u-1][v-1] == '0';
        }
    });

    for (int i = 0; i < n; ++i) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
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

