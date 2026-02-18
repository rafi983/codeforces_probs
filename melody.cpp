#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    int id;
};

int n;
map<int, int> v_compress, p_compress;
int v_cnt, p_cnt;
vector<vector<Edge>> adj;
vector<int> degree;
vector<int> path;
vector<bool> used_edge;

// Helper to add edges
void add_edge(int u, int v, int id) {
    adj[u].push_back({v, id});
    adj[v].push_back({u, id});
    degree[u]++;
    degree[v]++;
}

void find_euler(int u) {
    while (!adj[u].empty()) {
        Edge e = adj[u].back();
        adj[u].pop_back();
        if (used_edge[e.id]) continue;
        used_edge[e.id] = true;
        find_euler(e.to);
        path.push_back(e.id);
    }
}

void solve() {
    if (!(cin >> n)) return;

    v_compress.clear();
    p_compress.clear();
    v_cnt = 0;
    p_cnt = 0;

    vector<pair<int, int>> sounds(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> sounds[i].first >> sounds[i].second;
        if (v_compress.find(sounds[i].first) == v_compress.end()) {
            v_compress[sounds[i].first] = v_cnt++;
        }
        if (p_compress.find(sounds[i].second) == p_compress.end()) {
            p_compress[sounds[i].second] = p_cnt++;
        }
    }

    int total_nodes = v_cnt + p_cnt;
    adj.assign(total_nodes, vector<Edge>());
    degree.assign(total_nodes, 0);
    used_edge.assign(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        int u = v_compress[sounds[i].first];
        int v = v_cnt + p_compress[sounds[i].second]; // Offset pitch nodes
        add_edge(u, v, i);
    }

    int odd_degree = 0;
    int start_node = -1;
    for (int i = 0; i < total_nodes; ++i) {
        if (degree[i] % 2 != 0) {
            odd_degree++;
            if (start_node == -1 || degree[i] % 2 != 0) start_node = i;
        }
        if (degree[i] > 0 && start_node == -1) start_node = i;
    }

    if (odd_degree != 0 && odd_degree != 2) {
        cout << "NO" << endl;
        return;
    }

    // If odd_degree is 2, start_node MUST be one of the odd degree nodes.
    if (odd_degree == 2) {
        // Re-find the correct start node
        for(int i=0; i<total_nodes; ++i) {
            if(degree[i] % 2 != 0) {
                start_node = i;
                break;
            }
        }
    }

    if (start_node == -1) { // No edges? (n=0 case, though constraint says n>=1)
        if (n == 0) cout << "YES" << endl << endl;
        else cout << "NO" << endl; // Should not happen given constraints
        return;
    }

    path.clear();
    find_euler(start_node);

    if (path.size() != n) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << path[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
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

