#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> r(n);
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
        r[i]--; // 0-indexed
        indegree[r[i]]++;
    }

    vector<long long> S(n, 1);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    long long max_S = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (S[u] > max_S) {
            max_S = S[u];
        }

        int v = r[u];
        S[v] += S[u];
        indegree[v]--;
        if (indegree[v] == 0) {
            q.push(v);
        }
    }

    cout << max_S + 2 << endl;
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
