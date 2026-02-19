#include <iostream>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(2 * n + 1, 0);

   for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int val;
            cin >> val;
            int k = i + j;
            p[k] = val;
        }
    }

    set<int> present;
    for (int k = 2; k <= 2 * n; ++k) {
        present.insert(p[k]);
    }

    for (int x = 1; x <= 2 * n; ++x) {
        if (present.find(x) == present.end()) {
            p[1] = x;
            break;
        }
    }

    for (int k = 1; k <= 2 * n; ++k) {
        cout << p[k] << (k == 2 * n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

