#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<int> next_node(n);
    for (int i = 0; i < n - 1; ++i) {
        if (p[i] > p[i+1]) {
            next_node[i] = i + 1;
        } else {
            next_node[i] = i + 2;
        }
    }
    next_node[n - 1] = n;

    vector<long long> S(n + 1, 1);

    for (int i = 0; i < n; ++i) {
        int u = next_node[i];
        if (u < n) {
            S[u] += S[i];
        }
    }

    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        total_sum += S[i] * (long long)(n - i);
    }

    cout << total_sum << "\n";
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

