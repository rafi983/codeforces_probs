#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <tuple>

using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, w;
};

struct Query {
    int b, k, id;
};

void solve() {
    int n, m, q;
    if (!(cin >> n >> m >> q)) return;

    vector<Edge> edges;
    vector<int> weights;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        weights.push_back(w);
    }

    sort(weights.begin(), weights.end());
    weights.erase(unique(weights.begin(), weights.end()), weights.end());

    vector<vector<Query>> queries(n + 1);
    for (int i = 0; i < q; ++i) {
        int a, b, k;
        cin >> a >> b >> k;
        queries[a].push_back({b, k, i});
    }

    vector<int> ans(q, -1);
    int answered_count = 0;

    // Adjacency list: u -> {v, weight}
    vector<vector<pair<int, int>>> adj(n + 1);
    for (const auto& e : edges) {
        adj[e.u].push_back({e.v, e.w});
        adj[e.v].push_back({e.u, e.w});
    }

    vector<int> dist(n + 1);
    deque<int> dq;

    for (int W : weights) {
        if (answered_count == q) break;

        for (int start_node = 1; start_node <= n; ++start_node) {
            if (queries[start_node].empty()) continue;

            bool needed = false;
            for (const auto& qry : queries[start_node]) {
                if (ans[qry.id] == -1) {
                    needed = true;
                    break;
                }
            }
            if (!needed) continue;

            fill(dist.begin(), dist.end(), INF);
            dist[start_node] = 0;
            dq.push_back(start_node);

            while (!dq.empty()) {
                int u = dq.front();
                dq.pop_front();

                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    int w = edge.second;
                    int cost = (w > W ? 1 : 0);

                    if (dist[u] + cost < dist[v]) {
                        dist[v] = dist[u] + cost;
                        if (cost == 0) {
                            dq.push_front(v);
                        } else {
                            dq.push_back(v);
                        }
                    }
                }
            }

            for (const auto& qry : queries[start_node]) {
                if (ans[qry.id] == -1) {
                    if (dist[qry.b] <= qry.k - 1) {
                        ans[qry.id] = W;
                        answered_count++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << (i == q - 1 ? "" : " ");
    }
    cout << "\n";
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

