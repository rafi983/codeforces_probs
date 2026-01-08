#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve a single test case using the required name
void zaman() {
    int n;
    if (!(cin >> n)) return;

    // Adjacency list
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // We track the maximum width of any level and maximum star size (node + children)
    int max_level_width = 0;
    int max_star_degree = 0;

    // BFS initialization
    vector<int> current_nodes;
    current_nodes.reserve(n);
    current_nodes.push_back(1);

    vector<int> p(n + 1, 0);

    while (!current_nodes.empty()) {
        max_level_width = max(max_level_width, (int)current_nodes.size());

        vector<int> next_nodes;
        next_nodes.reserve(current_nodes.size() * 2); // Heuristic reservation

        for (int u : current_nodes) {
            int children_count = 0;
            for (int v : adj[u]) {
                if (v != p[u]) {
                    p[v] = u;
                    next_nodes.push_back(v);
                    children_count++;
                }
            }
            max_star_degree = max(max_star_degree, children_count + 1);
        }

        current_nodes = move(next_nodes);
    }

    cout << max(max_level_width, max_star_degree) << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            zaman();
        }
    }
    return 0;
}
