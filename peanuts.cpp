#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<long long> P(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        P[i + 1] = P[i] ^ a[i];
    }

    // Coordinate Compression for P
    vector<long long> coords = P;
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    auto get_coord = [&](long long val) {
        return lower_bound(coords.begin(), coords.end(), val) - coords.begin();
    };

    vector<int> compressed_P(n + 1);
    for (int i = 0; i <= n; ++i) {
        compressed_P[i] = get_coord(P[i]);
    }
    int m = coords.size();
    vector<long long> cnt(m, 0);
    long long sum_all = 0;



    struct Pending {
        int p_idx;
        long long total_val;
    };
    vector<Pending> pending;

    long long dp_win = 0;
    long long dp_loss = 1;

    // 4 variables for Small Box logic
    long long odd_win = 0, odd_loss = 1;
    long long even_win = 0, even_loss = 0;

    for (int i = n - 1; i >= 0; --i) {
        long long current_total_next = (dp_loss + dp_win) % MOD;

        if (a[i] > 1) {
             // Flush pending
             for (const auto& item : pending) {
                 cnt[item.p_idx] = (cnt[item.p_idx] + item.total_val) % MOD;
                 sum_all = (sum_all + item.total_val) % MOD;
             }
             pending.clear();

             int p_idx = compressed_P[i + 1];
             cnt[p_idx] = (cnt[p_idx] + current_total_next) % MOD;
             sum_all = (sum_all + current_total_next) % MOD;

             // Reset Small sums
             odd_win = 0; odd_loss = 0;
             even_win = 0; even_loss = 0;
        } else {
            // Add current split point i to pending
            pending.push_back({compressed_P[i + 1], current_total_next});
        }

        // Calculate DP[i]
        long long curr_loss = 0;
        long long curr_win = 0;

        // Big Part Contribution
        if (sum_all > 0) { // optimization
             int p_prev = compressed_P[i]; // P[i] (start of box)
             long long match = cnt[p_prev];
             long long no_match = (sum_all - match + MOD) % MOD;

             // Target Win (1) -> need mismatch
             curr_win = (curr_win + no_match) % MOD;
             // Target Loss (0) -> need match
             curr_loss = (curr_loss + match) % MOD;
        }

        // Small Part Contribution
        // Target 1 (Win): Even Len -> Next Win (even_win); Odd Len -> Next Loss (odd_loss)
        curr_win = (curr_win + even_win + odd_loss) % MOD;
        // Target 0 (Loss): Even Len -> Next Loss (even_loss); Odd Len -> Next Win (odd_win)
        curr_loss = (curr_loss + even_loss + odd_win) % MOD;

        dp_loss = curr_loss;
        dp_win = curr_win;


        long long next_odd_win = (even_win + dp_win) % MOD;
        long long next_odd_loss = (even_loss + dp_loss) % MOD;
        long long next_even_win = odd_win;
        long long next_even_loss = odd_loss;

        odd_win = next_odd_win;
        odd_loss = next_odd_loss;
        even_win = next_even_win;
        even_loss = next_even_loss;
    }

    cout << dp_win << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
