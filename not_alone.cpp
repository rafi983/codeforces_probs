#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const long long INF = 1e18;

long long cost2(int a, int b) {
    return abs(a - b);
}

long long cost3(int a, int b, int c) {
    int mn = min({a, b, c});
    int mx = max({a, b, c});
    return mx - mn;
}

long long solve_linear(const vector<int>& a) {
    int n = a.size();
    if (n == 0) return 0;
    vector<long long> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        if (i >= 2) {
            long long c = cost2(a[i-2], a[i-1]);
            if (dp[i-2] != INF) {
                dp[i] = min(dp[i], dp[i-2] + c);
            }
        }
        if (i >= 3) {
            long long c = cost3(a[i-3], a[i-2], a[i-1]);
            if (dp[i-3] != INF) {
                dp[i] = min(dp[i], dp[i-3] + c);
            }
        }
    }
    return dp[n];
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long ans = INF;

    // Case 1: Tile [0, 1]
    if (n >= 2) {
        long long current_cost = cost2(a[0], a[1]);
        vector<int> rem;
        rem.reserve(n-2);
        for (int i = 2; i < n; ++i) rem.push_back(a[i]);
        long long res = solve_linear(rem);
        if (res != INF) ans = min(ans, current_cost + res);
    }

    // Case 2: Tile [0, 1, 2]
    if (n >= 3) {
        long long current_cost = cost3(a[0], a[1], a[2]);
        vector<int> rem;
        rem.reserve(n-3);
        for (int i = 3; i < n; ++i) rem.push_back(a[i]);
        long long res = solve_linear(rem);
        if (res != INF) ans = min(ans, current_cost + res);
    }

    // Case 3: Tile [n-1, 0]
    if (n >= 2) {
        long long current_cost = cost2(a[n-1], a[0]);
        vector<int> rem;
        rem.reserve(n-2);
        for (int i = 1; i < n - 1; ++i) rem.push_back(a[i]);
        long long res = solve_linear(rem);
        if (res != INF) ans = min(ans, current_cost + res);
    }

    // Case 4: Tile [n-1, 0, 1]
    if (n >= 3) {
        long long current_cost = cost3(a[n-1], a[0], a[1]);
        vector<int> rem;
        rem.reserve(n-3);
        for (int i = 2; i < n - 1; ++i) rem.push_back(a[i]);
        long long res = solve_linear(rem);
        if (res != INF) ans = min(ans, current_cost + res);
    }

    // Case 5: Tile [n-2, n-1, 0]
    if (n >= 3) {
        long long current_cost = cost3(a[n-2], a[n-1], a[0]);
        vector<int> rem;
        rem.reserve(n-3);
        for (int i = 1; i < n - 2; ++i) rem.push_back(a[i]);
        long long res = solve_linear(rem);
        if (res != INF) ans = min(ans, current_cost + res);
    }

    cout << ans << endl;
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

