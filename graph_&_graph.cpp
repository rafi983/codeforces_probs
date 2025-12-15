#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n, s1, s2;
    if (!(cin >> n >> s1 >> s2)) return;

    int m1;
    cin >> m1;
    vector<vector<int>> adj1(n + 1);
    for (int i = 0; i < m1; ++i) {
        int u, v;
        cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }

    int m2;
    cin >> m2;
    vector<vector<int>> adj2(n + 1);
    for (int i = 0; i < m2; ++i) {
        int u, v;
        cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    vector<bool> is_good(n + 1, false);
    bool any_good = false;



    for (int u = 1; u <= n; ++u) {
        sort(adj1[u].begin(), adj1[u].end());
        sort(adj2[u].begin(), adj2[u].end());

        int i = 0, j = 0;
        while (i < adj1[u].size() && j < adj2[u].size()) {
            if (adj1[u][i] == adj2[u][j]) {
                is_good[u] = true;
                any_good = true;
                break;
            } else if (adj1[u][i] < adj2[u][j]) {
                i++;
            } else {
                j++;
            }
        }
    }

    if (!any_good) {
        cout << -1 << endl;
        return;
    }



    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;

    dist[s1][s2] = 0;
    pq.push({0, {s1, s2}});

    long long ans = INF;

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u1 = pq.top().second.first;
        int u2 = pq.top().second.second;
        pq.pop();

        if (d > dist[u1][u2]) continue;

        if (u1 == u2 && is_good[u1]) {
            ans = d;
            break;
        }



        for (int v1 : adj1[u1]) {
            for (int v2 : adj2[u2]) {
                int cost = abs(v1 - v2);
                if (dist[u1][u2] + cost < dist[v1][v2]) {
                    dist[v1][v2] = dist[u1][u2] + cost;
                    pq.push({dist[v1][v2], {v1, v2}});
                }
            }
        }
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
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

