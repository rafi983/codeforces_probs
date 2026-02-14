#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Cell {
    int r, c;
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<vector<int>> grid(n, vector<int>(m));
    int total_ones = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            total_ones += grid[i][j];
        }
    }

    int target = total_ones / 2;
    int current_sum = 0;


    vector<int> indeg(n * m, 0);
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            int d = 0;
            if (r > 0) d++;     // Requires (r-1, c)
            if (c < m - 1) d++; // Requires (r, c+1)
            indeg[r * m + c] = d;
        }
    }

    queue<Cell> q;
    if (n > 0 && m > 0) {
        for (int i = 0; i < n * m; ++i) {
            if (indeg[i] == 0) {
                q.push({i / m, i % m});
            }
        }
    }

    vector<bool> in_Sc(n * m, false);

    if (target > 0) {
        while (!q.empty()) {
            Cell u = q.front();
            q.pop();

            in_Sc[u.r * m + u.c] = true;
            current_sum += grid[u.r][u.c];

            if (current_sum == target) break;

            int neighbors[2][2] = {{u.r + 1, u.c}, {u.r, u.c - 1}};
            for (auto& nb : neighbors) {
                int nr = nb[0];
                int nc = nb[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int idx = nr * m + nc;
                    indeg[idx]--;
                    if (indeg[idx] == 0) {
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

    long long res = (long long)current_sum * (total_ones - current_sum);
    cout << res << endl;

    vector<int> L(n);
    for (int i = 0; i < n; ++i) {
        int count_Sc = 0;
        for (int j = 0; j < m; ++j) {
            if (in_Sc[i * m + j]) count_Sc++;
        }
        L[i] = m - count_Sc;
    }

    string path = "";
    int c = 0;
    for (int r = 0; r < n; ++r) {
        while (c < L[r]) {
            path += 'R';
            c++;
        }
        path += 'D';
    }
    while (c < m) {
        path += 'R';
        c++;
    }
    cout << path << endl;
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
