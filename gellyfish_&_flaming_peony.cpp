#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    int g_total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0) g_total = a[i];
        else g_total = gcd(g_total, a[i]);
    }

    int ones = 0;
    for (int i = 0; i < n; ++i) {
        a[i] /= g_total;
        if (a[i] == 1) ones++;
    }

    if (ones > 0) {
        cout << n - ones << "\n";
        return;
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    // Now a contains unique values

    // BFS
    vector<int> dist(5001, -1);
    queue<int> q;

    for (int x : a) {
        dist[x] = 0;
        q.push(x);
    }

    int min_ops = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == 1) {
            min_ops = dist[u];
            break;
        }

        for (int x : a) {
            int v = gcd(u, x);
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << n - 1 + min_ops << "\n";
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

