#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> x(n + 1);
    vector<int> count(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        count[x[i]]++;
    }

    int missing = -1;
    for (int v = 1; v <= n; ++v) {
        if (count[v] == 0) {
            missing = v;
            break;
        }
    }

    if (missing != -1) {
        // Not a permutation
        int u = (missing == 1) ? 2 : 1;
        cout << "? " << missing << " " << u << endl;
        int ans;
        cin >> ans;
        if (ans == -1) exit(0);

        if (ans == 0) {
            cout << "! A" << endl;
        } else {
            cout << "! B" << endl;
        }
    } else {
        // Permutation
        int i = -1, j = -1;
        for (int k = 1; k <= n; ++k) {
            if (x[k] == 1) i = k;
            if (x[k] == n) j = k;
        }

        cout << "? " << i << " " << j << endl;
        int d1;
        cin >> d1;
        if (d1 == -1) exit(0);

        cout << "? " << j << " " << i << endl;
        int d2;
        cin >> d2;
        if (d2 == -1) exit(0);

        if (d1 != d2) {
            cout << "! A" << endl;
        } else {
            // d1 == d2
            // For B, d1 >= n - 1
            // For A, d1 <= n / 2
            if (d1 >= n - 1) {
                cout << "! B" << endl;
            } else {
                cout << "! A" << endl;
            }
        }
    }
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
