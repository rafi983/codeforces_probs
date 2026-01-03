#include <iostream>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    --x; --y;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
        int prev = (i - 1 + n) % n;
        int next = (i + 1) % n;
        adj[i].push_back(prev);
        adj[i].push_back(next);
    }

    bool already_adjacent = false;
    for (int neighbor : adj[x]) {
        if (neighbor == y) {
            already_adjacent = true;
            break;
        }
    }

    if (!already_adjacent) {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i % 2;
    }

    for (int iter = 0; iter < 30; ++iter) {
        bool changed = false;
        for (int i = 0; i < n; ++i) {
            bool seen[6] = {false, false, false, false, false, false};
            for (int neighbor : adj[i]) {
                if (a[neighbor] < 6) {
                    seen[a[neighbor]] = true;
                }
            }
            int mex = 0;
            while (seen[mex]) mex++;

            if (a[i] != mex) {
                a[i] = mex;
                changed = true;
            }
        }
        if (!changed) break;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
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

