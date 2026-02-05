#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int max_kept = 0;

    for (int i = 0; i < n; ++i) {
        int kept = 0;
        for (int j = i; j < n; ++j) {
            if (a[j] <= a[i]) {
                kept++;
            }
        }
        if (kept > max_kept) {
            max_kept = kept;
        }
    }
    cout << n - max_kept << endl;
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
