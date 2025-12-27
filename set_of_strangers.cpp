#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    // Read input
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }


    vector<int> status(n * m + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int c = a[i][j];
            if (status[c] == 0) {
                status[c] = 1;
            }

            if (status[c] == 2) continue;

            // Check right neighbor
            if (j + 1 < m) {
                if (a[i][j] == a[i][j+1]) {
                    status[c] = 2;
                }
            }
            // Check down neighbor
            if (i + 1 < n) {
                if (a[i][j] == a[i+1][j]) {
                    status[c] = 2;
                }
            }
        }
    }

    long long total_cost = 0;
    int max_cost = 0;

    for (int i = 1; i <= n * m; ++i) {
        if (status[i] != 0) {
            int cost = (status[i] == 2) ? 2 : 1;
            total_cost += cost;
            if (cost > max_cost) {
                max_cost = cost;
            }
        }
    }

    cout << total_cost - max_cost << "\n";
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

