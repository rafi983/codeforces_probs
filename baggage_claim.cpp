#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long long MOD = 1e9 + 7;

void solve() {
    int n, m, k;
    if (!(cin >> n >> m >> k)) return;

    vector<pair<int, int>> q(k + 1);
    for (int i = 0; i < k + 1; ++i) {
        cin >> q[i].first >> q[i].second;
    }

    map<pair<int, int>, int> cell_to_id;
    int next_id = 0;
    auto get_id = [&](int r, int c) {
        if (cell_to_id.find({r, c}) == cell_to_id.end()) {
            cell_to_id[{r, c}] = next_id++;
        }
        return cell_to_id[{r, c}];
    };

    vector<pair<int, int>> edges;

    for (int i = 0; i < k; ++i) {
        int r1 = q[i].first;
        int c1 = q[i].second;
        int r2 = q[i+1].first;
        int c2 = q[i+1].second;

        vector<pair<int, int>> candidates;

        int dist = abs(r1 - r2) + abs(c1 - c2);

        if (dist != 2) {
            cout << 0 << "\n";
            return;
        }

        if (r1 == r2) {
            candidates.push_back({r1, (c1 + c2) / 2});
        } else if (c1 == c2) {
            candidates.push_back({(r1 + r2) / 2, c1});
        } else {
            candidates.push_back({r1, c2});
            candidates.push_back({r2, c1});
        }

        if (candidates.empty()) {
             cout << 0 << "\n";
             return;
        }

        if (candidates.size() == 1) {
            int u = get_id(candidates[0].first, candidates[0].second);
            edges.push_back({u, u});
        } else {
            int u = get_id(candidates[0].first, candidates[0].second);
            int v = get_id(candidates[1].first, candidates[1].second);
            edges.push_back({u, v});
        }
    }

    int V = next_id;
    vector<vector<int>> adj(V);

    for (auto& e : edges) {
        if (e.first == e.second) {
            adj[e.first].push_back(e.first);
            adj[e.first].push_back(e.first);
        } else {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
        }
    }

    vector<bool> visited(V, false);
    long long total_ways = 1;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            long long cntV = 0;
            long long cntE = 0;
            bool hasSelfLoop = false;

            vector<int> q_bfs;
            q_bfs.push_back(i);
            visited[i] = true;

            int head = 0;
            while(head < q_bfs.size()){
                int u = q_bfs[head++];
                cntV++;

                for (int v : adj[u]) {
                    cntE++;
                    if (u == v) hasSelfLoop = true;
                    if (!visited[v]) {
                        visited[v] = true;
                        q_bfs.push_back(v);
                    }
                }
            }

            cntE /= 2;

            if (cntE > cntV) {
                cout << 0 << "\n";
                return;
            }

            long long ways = 0;
            if (cntE == cntV) {
                if (hasSelfLoop) ways = 1;
                else ways = 2;
            } else { // cntE == cntV - 1
                ways = cntV;
            }

            total_ways = (total_ways * ways) % MOD;
        }
    }

    cout << total_ways << "\n";
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

