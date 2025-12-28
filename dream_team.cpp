#include <bits/stdc++.h>
using namespace std;


struct DSU {
    vector<int> p, r;
    DSU(int n = 0) { init(n); }
    void init(int n) { p.resize(n); r.assign(n, 0); iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; if (!(cin >> T)) return 0;
    for (int tc = 1; tc <= T; ++tc) {
        int N; cin >> N;
        vector<int> a(N);
        int maxA = 0;
        for (int i = 0; i < N; ++i) { cin >> a[i]; maxA = max(maxA, a[i]); }

        // Bucket indices by value
        vector<vector<int>> pos(maxA + 1);
        for (int i = 0; i < N; ++i) pos[a[i]].push_back(i);

        DSU dsu(N);
        long long ans = 0;

        // Process gcd g from maxA down to 1
        vector<int> roots;
        roots.reserve(N);
        for (int g = maxA; g >= 1; --g) {
            roots.clear();
            unordered_set<int> seen;
            seen.reserve(16);
            for (int m = g; m <= maxA; m += g) {
                if (pos[m].empty()) continue;
                for (int idx : pos[m]) {
                    int rt = dsu.find(idx);
                    if (seen.insert(rt).second) {
                        roots.push_back(rt);
                    }
                }
            }
            if (roots.size() <= 1) continue;
            // Connect components: chain union with weight g per successful union
            int base = roots[0];
            for (size_t i = 1; i < roots.size(); ++i) {
                if (dsu.unite(base, roots[i])) ans += g;
            }
        }

        cout << "Case " << tc << ": " << ans << "\n";
    }
    return 0;
}

