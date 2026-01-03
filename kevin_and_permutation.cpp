#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n, 0);
    int cur = 1;
    for (int i = k; i <= n; i += k) {
        p[i - 1] = cur++;
    }
    for (int i = 0; i < n; ++i) {
        if (p[i] == 0) {
            p[i] = cur++;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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

