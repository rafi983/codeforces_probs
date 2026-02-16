#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> left_child(n + 1, 0);
    vector<int> right_child(n + 1, 0);
    vector<int> parent(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        left_child[i] = l;
        right_child[i] = r;
        if (l != 0) {
            parent[l] = i;
            parent[r] = i;
        }
    }

    vector<int> order;
    order.reserve(n);
    vector<int> q;
    q.reserve(n);
    q.push_back(1);

    int head = 0;
    while(head < q.size()){
        int u = q[head++];
        order.push_back(u);
        if(left_child[u] != 0){
            q.push_back(left_child[u]);
            q.push_back(right_child[u]);
        }
    }

    vector<long long> T(n + 1, 0);

    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        if (left_child[u] == 0) { // Leaf
            T[u] = 1;
        } else {
            T[u] = (T[left_child[u]] + T[right_child[u]] + 3) % MOD;
        }
    }

    vector<long long> ans(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        int u = order[i];
        if (u == 1) {
            ans[u] = T[u];
        } else {
            ans[u] = (ans[parent[u]] + T[u]) % MOD;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << (i == n ? "" : " ");
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
