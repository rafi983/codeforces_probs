#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

void solve() {
    int a, b;
    long long x, y;
    if (!(cin >> a >> b >> x >> y)) return;

    int limit = 250;
    vector<long long> dist(limit + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[a] = 0;
    pq.push({0, a});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;
        if (u == b) {
            cout << d << "\n";
            return;
        }

        // Operation 1: u -> u + 1
        if (u + 1 <= limit) {
            if (dist[u + 1] > d + x) {
                dist[u + 1] = d + x;
                pq.push({dist[u + 1], u + 1});
            }
        }

        // Operation 2: u -> u ^ 1
        int v = u ^ 1;
        if (v <= limit) {
            if (dist[v] > d + y) {
                dist[v] = d + y;
                pq.push({dist[v], v});
            }
        }
    }

    cout << -1 << "\n";
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

