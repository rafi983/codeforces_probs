#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];
    int m;
    cin >> m;
    vector<int> d(m);
    map<int, int> available;
    for (int i = 0; i < m; ++i) {
        cin >> d[i];
        available[d[i]]++;
    }
    map<int, int> needed;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            needed[b[i]]++;
        }
    }
    int last_val = d[m-1];
    bool found_last = false;
    for (int x : b) {
        if (x == last_val) {
            found_last = true;
            break;
        }
    }
    if (!found_last) {
        cout << "NO" << endl;
        return;
    }
    for (auto const& [val, count] : needed) {
        if (available[val] < count) {
            cout << "NO" << endl;
            return;
        }
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
