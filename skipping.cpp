#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    vector<vector<pair<int, long long>>> adj(n + 1);

    for (int i = 1; i <= n; ++i) {
        adj[i].push_back({b[i], a[i]});
        if (i > 1) {
            adj[i].push_back({i - 1, 0});
        }
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(n + 1, INF);

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            long long weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    long long current_prefix_sum = 0;
    long long max_score = 0;

    for (int i = 1; i <= n; ++i) {
        current_prefix_sum += a[i];
        if (dist[i] != INF) {
            max_score = max(max_score, current_prefix_sum - dist[i]);
        }
    }

    cout << max_score << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
