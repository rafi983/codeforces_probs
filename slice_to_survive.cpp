#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long centered_cost(long long L) {
    if (L <= 1) return 0;
    long long turns = 0;
    long long current = 1;
    while (current < L) {
        current *= 2;
        turns++;
    }
    return turns;
}

void solve() {
    long long n, m, a, b;
    cin >> n >> m >> a >> b;

    long long ans = -1;

    if (n > 1) {
        long long n_new = min(a, n - a + 1);
        long long current_ans = 1 + centered_cost(n_new) + centered_cost(m);
        if (ans == -1 || current_ans < ans) {
            ans = current_ans;
        }
    }

    if (m > 1) {
        long long m_new = min(b, m - b + 1);
        long long current_ans = 1 + centered_cost(n) + centered_cost(m_new);
        if (ans == -1 || current_ans < ans) {
            ans = current_ans;
        }
    }

    if (ans == -1) ans = 0; // Should not happen given constraints n,m >= 2
    cout << ans << "\n";
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

