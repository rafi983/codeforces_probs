#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    set<int> sa, sb;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sa.insert(x);
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sb.insert(x);
    }

    if (sa.size() + sb.size() >= 4) {
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
