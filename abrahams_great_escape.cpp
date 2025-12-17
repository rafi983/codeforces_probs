#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    int m = n * n - k;


    if (m == 1) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    vector<string> grid(n, string(n, ' '));

    if (m == 0) {
        // All cells must escape. Pointing everything UP works (top row escapes, others follow).
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                grid[i][j] = 'U';
            }
        }
    } else {
        // We need m >= 2 non-escaping cells.
        // Create a cycle of length 2 at (0,0) and (0,1).
        grid[0][0] = 'R';
        grid[0][1] = 'L';
        int count = 2;

        // Fill the rest of the grid in row-major order.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                if (i == 0 && j == 1) continue;

                if (count < m) {

                    if (j > 0) {
                        grid[i][j] = 'L';
                    } else {
                        grid[i][j] = 'U';
                    }
                    count++;
                } else {

                    grid[i][j] = 'D';
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << grid[i] << endl;
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
