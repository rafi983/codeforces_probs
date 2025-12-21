#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
int w[MAXN];
int c[MAXN];
vector<int> adj[MAXN];
set<int>* sets[MAXN];
int final_c[MAXN];
long long min_cost = 0;

void dfs(int u, int p) {
    sets[u] = new set<int>();
    vector<int> bad_colors;
    bool has_fixed = false;

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);

        if (sets[v] == nullptr) {
            continue;
        }
        has_fixed = true;

        if (sets[u]->size() < sets[v]->size()) {
            swap(sets[u], sets[v]);
        }

        for (int color : *sets[v]) {
            if (sets[u]->count(color)) {
                bad_colors.push_back(color);
            } else {
                sets[u]->insert(color);
            }
        }
        delete sets[v];
        sets[v] = nullptr;
    }

    sort(bad_colors.begin(), bad_colors.end());
    bad_colors.erase(unique(bad_colors.begin(), bad_colors.end()), bad_colors.end());

    if (c[u] != 0) {
        has_fixed = true;
        sets[u]->insert(c[u]);

        bool cutie = false;
        for (int bc : bad_colors) {
            if (bc != c[u]) {
                cutie = true;
                break;
            }
        }
        if (cutie) min_cost += w[u];

        if (!bad_colors.empty()) final_c[u] = bad_colors[0];
        else final_c[u] = c[u];

    } else {
        if (!has_fixed) {
            delete sets[u];
            sets[u] = nullptr;
            return;
        }

        if (!bad_colors.empty()) {
            c[u] = bad_colors[0];
            if (bad_colors.size() > 1) min_cost += w[u];
            final_c[u] = c[u];
        } else {
            c[u] = *sets[u]->begin();
            final_c[u] = c[u];
        }
    }
}

void propagate(int u, int p, int inherited_color) {
    int fill;
    if (c[u] == 0) {
        c[u] = inherited_color;
        fill = c[u];
    } else {
        fill = final_c[u];
    }

    for (int v : adj[u]) {
        if (v == p) continue;
        propagate(v, u, fill);
    }
}

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    for(int i=1; i<=n; ++i) cin >> w[i];
    for(int i=1; i<=n; ++i) cin >> c[i];
    for(int i=1; i<=n; ++i) adj[i].clear();
    for(int i=0; i<n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    min_cost = 0;
    dfs(1, 0);
    propagate(1, 0, 1);

    cout << min_cost << "\n";
    for(int i=1; i<=n; ++i) cout << c[i] << (i==n ? "" : " ");
    cout << "\n";

    if (sets[1]) {
        delete sets[1];
        sets[1] = nullptr;
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

