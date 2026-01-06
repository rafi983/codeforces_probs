#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    int capacity;
    int flow;
    int cost;
    int reverse_edge;
};

vector<vector<Edge>> adj;
vector<long long> dist;
vector<int> parent_edge;
vector<int> parent_node;

void add_edge(int u, int v, int cap, int cost) {
    Edge forward = {v, cap, 0, cost, (int)adj[v].size()};
    Edge backward = {u, 0, 0, -cost, (int)adj[u].size()};
    adj[u].push_back(forward);
    adj[v].push_back(backward);
}

bool spfa(int s, int t, int& flow, long long& cost, int N_nodes) {
    dist.assign(N_nodes, INF);
    parent_node.assign(N_nodes, -1);
    parent_edge.assign(N_nodes, -1);
    vector<bool> in_queue(N_nodes, false);
    queue<int> q;

    dist[s] = 0;
    q.push(s);
    in_queue[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;

        for (int i = 0; i < adj[u].size(); ++i) {
            Edge& e = adj[u][i];
            if (e.capacity - e.flow > 0 && dist[e.to] > dist[u] + e.cost) {
                dist[e.to] = dist[u] + e.cost;
                parent_node[e.to] = u;
                parent_edge[e.to] = i;
                if (!in_queue[e.to]) {
                    q.push(e.to);
                    in_queue[e.to] = true;
                }
            }
        }
    }

    if (dist[t] == INF) return false;

    int push = 1e9;
    int curr = t;
    while (curr != s) {
        int p = parent_node[curr];
        int idx = parent_edge[curr];
        push = min(push, adj[p][idx].capacity - adj[p][idx].flow);
        curr = p;
    }

    flow += push;
    cost += (long long)push * dist[t];
    curr = t;
    while (curr != s) {
        int p = parent_node[curr];
        int idx = parent_edge[curr];
        adj[p][idx].flow += push;
        int reverse_idx = adj[p][idx].reverse_edge;
        adj[curr][reverse_idx].flow -= push;
        curr = p;
    }

    return true;
}

// Tarjan's
vector<int> tin, low;
vector<bool> on_stack;
vector<int> st;
vector<vector<int>> sccs;
int timer;

void tarjan(int u, const vector<vector<int>>& graph) {
    tin[u] = low[u] = ++timer;
    st.push_back(u);
    on_stack[u] = true;

    for (int v : graph[u]) {
        if (tin[v] == -1) {
            tarjan(v, graph);
            low[u] = min(low[u], low[v]);
        } else if (on_stack[v]) {
            low[u] = min(low[u], tin[v]);
        }
    }

    if (low[u] == tin[u]) {
        vector<int> current_scc;
        while (true) {
            int v = st.back();
            st.pop_back();
            on_stack[v] = false;
            current_scc.push_back(v);
            if (u == v) break;
        }
        sccs.push_back(current_scc);
    }
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    // SCC
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    on_stack.assign(n + 1, false);
    st.clear();
    sccs.clear();
    timer = 0;
    for (int i = 1; i <= n; ++i) {
        if (tin[i] == -1) tarjan(i, graph);
    }

    int k = sccs.size();
    vector<int> scc_id(n + 1);
    vector<int> scc_a(k);
    for (int i = 0; i < k; ++i) {
        for (int node : sccs[i]) {
            scc_id[node] = i;
            scc_a[i] = min(1000, scc_a[i] + a[node]); // Cap at sensible value
        }
    }

    // Build DAG edges
    vector<vector<int>> dag_adj(k);
    for (int u = 1; u <= n; ++u) {
        for (int v : graph[u]) {
            if (scc_id[u] != scc_id[v]) {
                dag_adj[scc_id[u]].push_back(scc_id[v]);
            }
        }
    }

    int S = 0, T = 1;
    int num_nodes = 2 + 3 * k;
    adj.assign(num_nodes, vector<Edge>());

    vector<int> balance(num_nodes, 0);
    long long base_cost = 0;

    for (int i = 0; i < k; ++i) {
        int u_src = 2 + 3 * i;
        int u_in = 2 + 3 * i + 1;
        int u_out = 2 + 3 * i + 2;

        balance[u_in] -= 1;
        balance[u_out] += 1;

        add_edge(u_in, u_out, 1e9, 0);

        add_edge(S, u_src, scc_a[i], 0); // Supply from population
        add_edge(u_src, u_in, 1e9, 1);   // Paid entry
        add_edge(u_src, u_out, 1e9, 0);  // Free amplification

        add_edge(u_out, T, 1e9, 0);

        for (int neighbor : dag_adj[i]) {
            int v_in = 2 + 3 * neighbor + 1;
            add_edge(u_out, v_in, 1e9, 0);
        }
    }

    add_edge(T, S, 1e9, 0);

    int SS = num_nodes;
    int TT = num_nodes + 1;
    adj.resize(num_nodes + 2);

    for (int i = 0; i < num_nodes; ++i) {
        if (balance[i] > 0) {
            add_edge(SS, i, balance[i], 0);
        } else if (balance[i] < 0) {
            add_edge(i, TT, -balance[i], 0);
        }
    }

    int flow = 0;
    long long min_cost = 0;


    while (spfa(SS, TT, flow, min_cost, num_nodes + 2));

    for (const auto& e : adj[SS]) {
        if (e.flow < e.capacity) {
            cout << "-1\n";
            return;
        }
    }

    cout << min_cost << "\n";
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

