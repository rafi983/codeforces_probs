#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<int> r_max(n);
    for (int i = 0; i < n; ++i) {
        int limit = m;
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '0') {
                limit = j;
                break;
            }
        }
        r_max[i] = limit;
    }

    vector<int> c_max(m);
    for (int j = 0; j < m; ++j) {
        int limit = n;
        for (int i = 0; i < n; ++i) {
            if (grid[i][j] == '0') {
                limit = i;
                break;
            }
        }
        c_max[j] = limit;
    }

    bool possible = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '1') {
                bool covered_by_row = (j < r_max[i]);
                bool covered_by_col = (i < c_max[j]);
                if (!covered_by_row && !covered_by_col) {
                    possible = false;
                    break;
                }
            }
        }
        if (!possible) break;
    }

    if (possible) cout << "YES" << "\n";
    else cout << "NO" << "\n";
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
