#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int a_dim, b_dim, c_dim;
    if (!(cin >> a_dim >> b_dim >> c_dim)) return;

    vector<string> x_grid(c_dim);
    for (int i = 0; i < c_dim; ++i) cin >> x_grid[i];

    vector<int> X(b_dim, 0);
    bool possible = true;

    for (int j = 0; j < b_dim; ++j) {
        int first_one = -1;
        for (int i = 0; i < c_dim; ++i) {
            if (x_grid[i][j] == '1') {
                first_one = i;
                break;
            }
        }

        if (first_one != -1) {
            for (int i = first_one; i < c_dim; ++i) {
                if (x_grid[i][j] == '0') {
                    possible = false;
                }
            }
            X[j] = c_dim - first_one;
        } else {
            X[j] = 0;
        }
    }

    // Read Y-view
    // Size c * a
    vector<string> y_grid(c_dim);
    for (int i = 0; i < c_dim; ++i) cin >> y_grid[i];

    vector<int> Y(a_dim, 0);
    for (int j = 0; j < a_dim; ++j) {
        int first_one = -1;
        for (int i = 0; i < c_dim; ++i) {
            if (y_grid[i][j] == '1') {
                first_one = i;
                break;
            }
        }

        if (first_one != -1) {
            for (int i = first_one; i < c_dim; ++i) {
                if (y_grid[i][j] == '0') {
                    possible = false;
                }
            }
            Y[j] = c_dim - first_one;
        } else {
            Y[j] = 0;
        }
    }

    if (!possible) {
        cout << "-1" << endl;
        return;
    }

    int max_x = 0;
    for(int h : X) max_x = max(max_x, h);
    int max_y = 0;
    for(int h : Y) max_y = max(max_y, h);

    if (max_x != max_y) {
        cout << "-1" << endl;
        return;
    }

    // counts
    vector<int> cntX(c_dim + 1, 0);
    for (int h : X) cntX[h]++;

    vector<int> cntY(c_dim + 1, 0);
    for (int h : Y) cntY[h]++;

    // suffix sums
    vector<int> sufX(c_dim + 2, 0);
    for (int k = c_dim; k >= 1; --k) sufX[k] = sufX[k+1] + cntX[k];

    vector<int> sufY(c_dim + 2, 0);
    for (int k = c_dim; k >= 1; --k) sufY[k] = sufY[k+1] + cntY[k];

    long long min_cubes = 0;
    long long max_cubes = 0;
    long long current_S_size = 0;

    for (int k = c_dim; k >= 1; --k) {
        long long cx = sufX[k];
        long long cy = sufY[k];

        long long nxt_cx = sufX[k+1];
        long long nxt_cy = sufY[k+1];

        long long delta = max(cx - nxt_cx, cy - nxt_cy);
        current_S_size += delta;
        min_cubes += current_S_size;

        if (cx == 0 && cy == 0) continue;
        max_cubes += cx * cy;
    }

    cout << min_cubes << " " << max_cubes << endl;
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
