#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> initial_F;

int query_sum(const vector<int>& nodes) {
    if (nodes.empty()) return 0;
    cout << "? 1 " << nodes.size();
    for (int u : nodes) cout << " " << u;
    cout << endl;
    int res;
    cin >> res;
    return res;
}

void toggle(int u) {
    cout << "? 2 " << u << endl;
}

struct Component {
    int rep;
    vector<int> candidates_in_comp;
};

void get_components(int u, const vector<int>& candidates, vector<Component>& comps) {
    vector<bool> visited(n + 1, false);
    visited[u] = true;

    vector<bool> is_cand(n + 1, false);
    for (int c : candidates) is_cand[c] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            Component comp;
            comp.rep = v;

            vector<int> q;
            q.push_back(v);
            visited[v] = true;

            int head = 0;
            while(head < q.size()){
                int curr = q[head++];
                if (is_cand[curr]) {
                    comp.candidates_in_comp.push_back(curr);
                }
                for (int neighbor : adj[curr]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push_back(neighbor);
                    }
                }
            }

            if (!comp.candidates_in_comp.empty()) {
                comps.push_back(comp);
            }
        }
    }
}

int sz[1005];
void dfs_sz(int u, int p, int total_w, int& centroid, const vector<bool>& is_cand) {
    sz[u] = is_cand[u] ? 1 : 0;
    bool is_centroid = true;
    for (int v : adj[u]) {
        if (v != p) {
            dfs_sz(v, u, total_w, centroid, is_cand);
            sz[u] += sz[v];
            if (sz[v] > total_w / 2) is_centroid = false;
        }
    }
    if (total_w - sz[u] > total_w / 2) is_centroid = false;
    if (is_centroid) centroid = u;
}

int get_centroid(const vector<int>& candidates) {
    if (candidates.empty()) return 1;
    vector<bool> is_cand(n + 1, false);
    for (int c : candidates) is_cand[c] = true;
    int centroid = -1;
    dfs_sz(1, 0, candidates.size(), centroid, is_cand);
    return centroid;
}

void solve() {
    if (!(cin >> n)) return;
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    initial_F.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        initial_F[i] = query_sum({i});
    }

    vector<int> candidates;
    for (int i = 1; i <= n; ++i) {
        if (abs(initial_F[i]) == 1) {
            candidates.push_back(i);
        }
    }

    int root = -1;
    if (candidates.size() == 1) {
        root = candidates[0];
    } else {
        while (candidates.size() > 1) {
            int u = get_centroid(candidates);

            toggle(u);

            vector<Component> comps;
            get_components(u, candidates, comps);

            vector<int> probes;
            for (const auto& comp : comps) probes.push_back(comp.rep);

            long long expected_sum_initial = 0;
            for (int p : probes) expected_sum_initial += initial_F[p];

            int current_sum = query_sum(probes);
            int diff = abs(current_sum - expected_sum_initial);

            bool all_changed = false;
            int unchanged_idx = -1;

            if (!probes.empty()) {
                if (diff == 2 * probes.size()) {
                    all_changed = true;
                } else {
                    int L = 0, R = probes.size() - 1;
                    while (L < R) {
                        int mid = L + (R - L) / 2;
                        vector<int> subset;
                        long long sub_initial = 0;
                        for (int i = L; i <= mid; ++i) {
                            subset.push_back(probes[i]);
                            sub_initial += initial_F[probes[i]];
                        }

                        int sub_curr = query_sum(subset);
                        int sub_diff = abs(sub_curr - sub_initial);

                        if (sub_diff == 2 * subset.size()) {
                            L = mid + 1;
                        } else {
                            R = mid;
                        }
                    }
                    unchanged_idx = L;
                }
            } else {
                // Should imply u is the only candidate, but loop condition says > 1
                // This case is theoretically impossible if logic is correct
                all_changed = true;
            }

            toggle(u);

            if (all_changed) {
                root = u;
                break;
            } else {
                candidates = comps[unchanged_idx].candidates_in_comp;
            }
        }
        if (root == -1 && !candidates.empty()) root = candidates[0];
    }

    vector<int> ans(n + 1);
    ans[root] = initial_F[root];

    vector<int> q;
    q.push_back(root);
    vector<bool> visited(n + 1, false);
    visited[root] = true;

    int head = 0;
    while(head < q.size()){
        int u = q[head++];
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                ans[v] = initial_F[v] - initial_F[u];
                q.push_back(v);
            }
        }
    }

    cout << "!";
    for (int i = 1; i <= n; ++i) cout << " " << ans[i];
    cout << endl;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

