#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Func {
    long long a, b, c;
};

bool is_independent(const Func& u, const Func& v) {
    long long A = u.a - v.a;
    long long B = u.b - v.b;
    long long C = u.c - v.c;

    if (A == 0) {
        return B == 0 && C != 0;
    }

    long long delta = B * B - 4 * A * C;
    return delta < 0;
}

bool is_strictly_above(const Func& u, const Func& v) {
    long long A = u.a - v.a;
    long long B = u.b - v.b;
    long long C = u.c - v.c;

    if (A == 0) {
        return B == 0 && C > 0;
    }

    if (A <= 0) return false;

    long long delta = B * B - 4 * A * C;
    return delta < 0;
}

vector<int> memo_L;
vector<int> memo_R;
vector<vector<int>> adj;
vector<vector<int>> rev_adj;

int get_L(int u) {
    if (memo_L[u] != -1) return memo_L[u];
    int max_prev = 0;
    for (int v : rev_adj[u]) {
        max_prev = max(max_prev, get_L(v));
    }
    return memo_L[u] = 1 + max_prev;
}

int get_R(int u) {
    if (memo_R[u] != -1) return memo_R[u];
    int max_next = 0;
    for (int v : adj[u]) {
        max_next = max(max_next, get_R(v));
    }
    return memo_R[u] = 1 + max_next;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<Func> func(n);
    for (int i = 0; i < n; ++i) {
        cin >> func[i].a >> func[i].b >> func[i].c;
    }

    adj.assign(n, vector<int>());
    rev_adj.assign(n, vector<int>());

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (is_strictly_above(func[i], func[j])) {
                adj[i].push_back(j);
                rev_adj[j].push_back(i);
            }
        }
    }

    memo_L.assign(n, -1);
    memo_R.assign(n, -1);

    for (int i = 0; i < n; ++i) {
        int left = get_L(i);
        int right = get_R(i);
        cout << (left + right - 1) << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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

