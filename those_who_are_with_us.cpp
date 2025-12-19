#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int r, c;
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<vector<int>> a(n, vector<int>(m));
    int max_val = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] > max_val) {
                max_val = a[i][j];
            }
        }
    }

    vector<Point> max_positions;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == max_val) {
                max_positions.push_back({i, j});
            }
        }
    }

    if (max_positions.empty()) {
        cout << max_val << "\n";
        return;
    }

    Point p0 = max_positions[0];

    bool row_works = true;
    int fixed_col = -1;
    for (const auto& p : max_positions) {
        if (p.r != p0.r) {
            if (fixed_col == -1) {
                fixed_col = p.c;
            } else if (fixed_col != p.c) {
                row_works = false;
                break;
            }
        }
    }

    if (row_works) {
        cout << max_val - 1 << "\n";
        return;
    }

    bool col_works = true;
    int fixed_row = -1;
    for (const auto& p : max_positions) {
        if (p.c != p0.c) {
            if (fixed_row == -1) {
                fixed_row = p.r;
            } else if (fixed_row != p.r) {
                col_works = false;
                break;
            }
        }
    }

    if (col_works) {
        cout << max_val - 1 << "\n";
    } else {
        cout << max_val << "\n";
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

