#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> dist(n + 1, -1);
    vector<int> transitions;
    queue<int> q;

    vector<bool> seen(n + 1, false);

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val <= n) {
            if (!seen[val]) {
                seen[val] = true;
                dist[val] = 1;
                q.push(val);
                if (val > 1) {
                    transitions.push_back(val);
                }
            }
        }
    }

    sort(transitions.begin(), transitions.end());

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int x : transitions) {
            long long v_long = (long long)u * x;
            if (v_long > n) break;

            int v = (int)v_long;
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << (i == n ? "" : " ");
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
