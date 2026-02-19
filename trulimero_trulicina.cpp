#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;


    vector<vector<int>> grid(n, vector<int>(m));

    if (m % k != 0) {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                long long idx = (long long)i * m + j;
                grid[i][j] = (idx % k) + 1;
            }
        }
    } else if (n % k != 0) {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                long long idx = (long long)j * n + i;
                grid[i][j] = (idx % k) + 1;
            }
        }
    } else {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                grid[i][j] = ((i + j) % k) + 1;
            }
        }
    }

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cout << grid[i][j] << (j == m-1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}

