#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool dfs_cycle(int u, const vector<vector<int>>& adj, vector<int>& visited) {
    visited[u] = 1; // Mark as visiting
    for (int v : adj[u]) {
        if (visited[v] == 1) return true; // Cycle detected
        if (visited[v] == 0) {
            if (dfs_cycle(v, adj, visited)) return true;
        }
    }
    visited[u] = 2; // Mark as visited
    return false;
}

bool solve_test_case() {
    int n, m;
    if (!(cin >> n >> m)) return false;

    vector<vector<int>> A(n, vector<int>(m));
    vector<vector<int>> B(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> A[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> B[i][j];

    for (int k = 0; k < 30; ++k) {
        vector<bool> U(n, false); // Rows that MUST be set to 0 for bit k
        vector<bool> V(m, false); // Cols that MUST be set to 1 for bit k
        queue<int> q; // Queue for propagation

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int a_bit = (A[i][j] >> k) & 1;
                int b_bit = (B[i][j] >> k) & 1;

                if (a_bit == 1 && b_bit == 0) {
                    if (!U[i]) {
                        U[i] = true;
                        q.push(i);
                    }
                }
                if (a_bit == 0 && b_bit == 1) {
                    if (!V[j]) {
                        V[j] = true;
                        q.push(n + j);
                    }
                }
            }
        }

        // 2. Propagate constraints
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr < n) { // It's a row i
                int i = curr;
                for (int j = 0; j < m; ++j) {
                    int b_bit = (B[i][j] >> k) & 1;
                    if (b_bit == 1) {
                        if (!V[j]) {
                            V[j] = true;
                            q.push(n + j);
                        }
                    }
                }
            } else { // It's a col j
                int j = curr - n;
                for (int i = 0; i < n; ++i) {
                    int b_bit = (B[i][j] >> k) & 1;
                    if (b_bit == 0) {
                        if (!U[i]) {
                            U[i] = true;
                            q.push(i);
                        }
                    }
                }
            }
        }

        vector<vector<int>> adj(n + m);
        for (int i = 0; i < n; ++i) {
            if (!U[i]) continue;
            for (int j = 0; j < m; ++j) {
                if (!V[j]) continue;

                int b_bit = (B[i][j] >> k) & 1;
                if (b_bit == 0) {
                    // Need 0. Row op must be last. Col -> Row
                    adj[n + j].push_back(i);
                } else {
                    // Need 1. Col op must be last. Row -> Col
                    adj[i].push_back(n + j);
                }
            }
        }

        // 4. Check for cycles
        vector<int> visited(n + m, 0);
        for (int i = 0; i < n + m; ++i) {
            if (visited[i] == 0) {
                if (dfs_cycle(i, adj, visited)) return false; // Cycle found -> Impossible
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            if (solve_test_case()) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}

