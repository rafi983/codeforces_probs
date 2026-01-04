#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<int> a(n);
    vector<int> counts(k, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        counts[a[i] % k]++;
    }

    for (int i = 0; i < n; ++i) {
        if (counts[a[i] % k] == 1) {
            cout << "YES" << endl;
            cout << i + 1 << endl;
            return;
        }
    }

    cout << "NO" << endl;
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

