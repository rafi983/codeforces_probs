#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

long long MOD = 998244353;
const int MAXN = 400005; // 2*N for Catalan
long long fact[MAXN], invFact[MAXN];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modInverse(fact[i]);
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

long long catalan(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    // C_n = 1/(n+1) * C(2n, n)
    long long res = nCr(2 * n, n);
    res = (res * modInverse(n + 1)) % MOD;
    return res;
}

struct Segment {
    int l, r, id;
};

bool compareSegments(const Segment& a, const Segment& b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r > b.r;
}

vector<vector<int>> adj;
vector<long long> ways;
vector<Segment> segments;

void dfs(int u) {
    long long prod = 1;
    long long covered_len = 0;
    for (int v : adj[u]) {
        dfs(v);
        prod = (prod * ways[v]) % MOD;
        covered_len += (segments[v].r - segments[v].l + 1);
    }
    long long total_len = segments[u].r - segments[u].l + 1;
    long long gaps = total_len - covered_len;
    long long items = adj[u].size() + gaps;
    ways[u] = (prod * catalan(items - 1)) % MOD;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    segments.clear();
    bool has_root = false;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        segments.push_back({l, r, i});
        if (l == 1 && r == n) has_root = true;
    }

    if (!has_root) {
        segments.push_back({1, n, m});
    }

    sort(segments.begin(), segments.end(), compareSegments);

    int sz = segments.size();
    adj.assign(sz, vector<int>());
    ways.assign(sz, 0);

    stack<int> st;
    st.push(0);

    for (int i = 1; i < sz; ++i) {
        while (!st.empty()) {
            int top = st.top();
            if (segments[top].r >= segments[i].r) {
                adj[top].push_back(i);
                st.push(i);
                break;
            } else {
                st.pop();
            }
        }
    }

    dfs(0);
    cout << ways[0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

