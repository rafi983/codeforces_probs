#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
vector<pair<int, int>> chords;
vector<ll> h;
vector<int> L;
vector<ll> Y;

struct Fenwick {
    int size;
    vector<ll> tree;

    void init(int s) {
        size = s;
        tree.assign(s + 1, 0);
    }

    void add(int i, ll val) {
        for (; i <= size; i += i & -i)
            tree[i] ^= val;
    }

    ll query(int i) {
        ll res = 0;
        for (; i > 0; i -= i & -i)
            res ^= tree[i];
        return res;
    }

    ll query(int l, int r) {
        if (l > r) return 0;
        return query(r) ^ query(l - 1);
    }
};

void solve() {
    cin >> n;
    chords.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> chords[i].first >> chords[i].second;
        if (chords[i].first > chords[i].second) swap(chords[i].first, chords[i].second);
    }

    // Random hashes
    mt19937_64 beta(chrono::steady_clock::now().time_since_epoch().count());
    h.resize(n + 1);
    for (int i = 1; i <= n; ++i) h[i] = beta();

    L.assign(n + 1, 0);
    Y.assign(n + 1, 0);

    Fenwick ftL, ftY;
    ftL.init(2 * n);
    ftY.init(2 * n);

    ll current_H = 0;
    string ans = "";

    for (int i = 1; i <= n; ++i) {
        int u = chords[i].first;
        int v = chords[i].second;

        // Calculate L[i]
        ll sum_L = ftL.query(u, v);
        L[i] = 1 ^ (sum_L & 1);

        // Update ftL
        if (L[i]) {
            ftL.add(u, 1);
            ftL.add(v, 1);
        }

        // Calculate Y[i]
        ll w_i = (L[i] ? h[i] : 0);
        ll sum_Y = ftY.query(u, v);
        Y[i] = w_i ^ sum_Y;

        // Update ftY
        ftY.add(u, Y[i]);
        ftY.add(v, Y[i]);

        // Update H
        current_H ^= Y[i];

        if (current_H == 0) ans += '1';
        else ans += '0';
    }

    cout << ans << "\n";
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
