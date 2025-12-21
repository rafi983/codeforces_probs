#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    bool possible = true;
    int val = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            possible = false;
        }
        if (a[i] > 0) {
            if (val == -1) {
                val = a[i];
            } else if (val != a[i]) {
                possible = false;
            }
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

