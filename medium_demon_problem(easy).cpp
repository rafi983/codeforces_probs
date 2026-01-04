#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> r(n);
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
        r[i]--;
        indegree[r[i]]++;
    }

    vector<int> L(n, 0);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int max_L = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (L[u] > max_L) {
            max_L = L[u];
        }

        int v = r[u];
        if (L[u] + 1 > L[v]) {
            L[v] = L[u] + 1;
        }

        indegree[v]--;
        if (indegree[v] == 0) {
            q.push(v);
        }
    }

    cout << max_L + 3 << endl;
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
