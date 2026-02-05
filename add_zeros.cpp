#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<long long, vector<long long>> adj;
    for (int i = 1; i < n; ++i) { // i corresponds to 1-based index i+1
        long long pos = i + 1;
        long long u = a[i] + pos - 1;
        long long v = u + pos - 1;
        adj[u].push_back(v);
    }

    long long max_len = n;
    set<long long> visited;
    vector<long long> s;

    s.push_back(n);
    visited.insert(n);

    while (!s.empty()) {
        long long u = s.back();
        s.pop_back();

        if (u > max_len) max_len = u;

        auto it = adj.find(u);
        if (it != adj.end()) {
            for (long long v : it->second) {
                if (visited.find(v) == visited.end()) {
                    visited.insert(v);
                    s.push_back(v);
                }
            }
        }
    }
    cout << max_len << "\n";
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
