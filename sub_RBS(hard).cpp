#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long MOD = 998244353;

long long C[205][205];

void init_comb() {
    for (int i = 0; i <= 200; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

long long dp_pre[105][105];
long long dp_suf[105][105];

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp_pre[i][j] = 0;
            dp_suf[i][j] = 0;
        }
    }

    dp_pre[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int b = 0; b <= i; ++b) {
            if (dp_pre[i][b] == 0) continue;
            dp_pre[i + 1][b] = (dp_pre[i + 1][b] + dp_pre[i][b]) % MOD;
            if (s[i] == '(') {
                if (b + 1 <= n)
                    dp_pre[i + 1][b + 1] = (dp_pre[i + 1][b + 1] + dp_pre[i][b]) % MOD;
            } else {
                if (b > 0)
                    dp_pre[i + 1][b - 1] = (dp_pre[i + 1][b - 1] + dp_pre[i][b]) % MOD;
            }
        }
    }

    dp_suf[n][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int b = 0; b <= n; ++b) {
            dp_suf[i][b] = (dp_suf[i][b] + dp_suf[i + 1][b]) % MOD;
            if (s[i] == '(') {
                if (b + 1 <= n)
                    dp_suf[i][b] = (dp_suf[i][b] + dp_suf[i + 1][b + 1]) % MOD;
            } else {
                if (b > 0)
                    dp_suf[i][b] = (dp_suf[i][b] + dp_suf[i + 1][b - 1]) % MOD;
            }
        }
    }

    long long total_len_sum = 0;

    for (int i = 0; i < n; ++i) {
        long long ways = 0;
        if (s[i] == '(') {
            for (int b = 0; b <= n; ++b) {
                if (b + 1 <= n) {
                    ways = (ways + dp_pre[i][b] * dp_suf[i + 1][b + 1]) % MOD;
                }
            }
        } else {
            for (int b = 1; b <= n; ++b) {
                ways = (ways + dp_pre[i][b] * dp_suf[i + 1][b - 1]) % MOD;
            }
        }
        total_len_sum = (total_len_sum + ways) % MOD;
    }

    long long num_rbs = (dp_suf[0][0] - 1 + MOD) % MOD;
    long long s1 = (total_len_sum - 2 * num_rbs) % MOD;
    if (s1 < 0) s1 += MOD;

    long long s2 = 0;

    vector<int> pre_open(n + 1, 0);
    for(int i=0; i<n; ++i) pre_open[i+1] = pre_open[i] + (s[i] == '(');

    for (int i = 0; i < n; ++i) {
        if (s[i] != '(') continue;
        int opens_before = pre_open[i];

        for (int num_pairs = 2; num_pairs <= n / 2 + 1; ++num_pairs) {
            if (opens_before < num_pairs - 2) continue;

            long long ways_pre = C[opens_before][num_pairs - 2];

            int rem_open = 0;
            int rem_close = 0;
            for(int k=i+1; k<n; ++k) {
                if(s[k] == '(') rem_open++;
                else rem_close++;
            }

            if (rem_open < 1 || rem_close < num_pairs) continue;

            long long total_suffix = (rem_open * C[rem_close][num_pairs]) % MOD;

            long long invalid_suffix = 0;
            int running_close = 0;
            for(int j=i+1; j<n; ++j) {
                if(s[j] == ')') {
                    running_close++;
                } else {
                    if (running_close >= num_pairs) {
                         invalid_suffix = (invalid_suffix + C[running_close][num_pairs]) % MOD;
                    }
                }
            }

            long long cur_ways = (total_suffix - invalid_suffix + MOD) % MOD;
            long long term = (ways_pre * cur_ways) % MOD;
            long long score = (2 * num_pairs - 2);
            s2 = (s2 + term * score) % MOD;
        }
    }

    long long ans = (s1 - s2 + MOD) % MOD;
    cout << ans << "\n";
}

int main() {
    init_comb();
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
