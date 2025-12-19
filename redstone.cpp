#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    set<int> s;
    bool duplicate_found = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (s.count(a[i])) {
            duplicate_found = true;
        }
        s.insert(a[i]);
    }

    if (duplicate_found) {
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

