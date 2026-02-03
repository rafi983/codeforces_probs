#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[p].push_back(i);
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
        for(int v : adj[u]){
            q.push_back(v);
        }
    }

    vector<int> dp(n + 1, 0);
    vector<int> vals;
    vals.reserve(n);

    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        if (adj[u].empty()) {
            dp[u] = 0;
            continue;
        }

        vals.clear();
        for (int v : adj[u]) {
            vals.push_back(dp[v]);
        }
        sort(vals.begin(), vals.end());

        int M = vals.back();

        int mx_bit = -1;
        bool non_max_bits = false;
        long long carry = 0;
        int pos = 0;
        int current_h = vals[0];

        while (true) {
            long long weight = carry;

            while (pos < vals.size() && vals[pos] == current_h) {
                weight++;
                pos++;
            }

            if (weight % 2 != 0) {
                if (mx_bit != -1) non_max_bits = true;
                mx_bit = current_h;
            }

            carry = weight / 2;

            if (carry == 0 && pos == vals.size()) break;

            if (carry > 0) {
                current_h++;
            } else {
                current_h = vals[pos];
            }
        }

        int req = mx_bit;
        if (non_max_bits) req = mx_bit + 1;

        dp[u] = max(M + 1, req);
    }

    cout << dp[1] << "\n";
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
