#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

long long nCr_2(int n) {
    if (n < 2) return 0;
    return (1LL * n * (n - 1) / 2) % MOD;
}

int pref[100005][52];
int a[100005];

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int v = 0; v <= 50; ++v) {
            pref[i][v] = pref[i-1][v];
        }
        pref[i][a[i]]++;
    }

    for (int k = 0; k < q; ++k) {
        int l, r;
        cin >> l >> r;

        int cnt[52];
        int zeros = pref[r][0] - pref[l-1][0];

        if (zeros > 0) {
            cout << (r - l + 1) - 1 << " " << zeros << "\n";
            continue;
        }

        bool has_dup = false;
        long long ways_dup = 0;
        vector<int> distinct_vals;
        distinct_vals.reserve(50);

        for (int v = 1; v <= 50; ++v) {
            int c = pref[r][v] - pref[l-1][v];
            cnt[v] = c;
            if (c >= 2) {
                has_dup = true;
                ways_dup = (ways_dup + nCr_2(c)) % MOD;
            }
            if (c > 0) {
                distinct_vals.push_back(v);
            }
        }

        if (has_dup) {
            cout << (r - l + 1) - 2 << " " << ways_dup << "\n";
            continue;
        }


        static int dp_sz[64];
        static int dp_cnt[64];
        static int next_sz[64];
        static int next_cnt[64];

        for(int i=0; i<64; ++i) {
            dp_sz[i] = 100;
            dp_cnt[i] = 0;
        }
        dp_sz[0] = 0;
        dp_cnt[0] = 1;

        int best_sz = 100;
        long long best_ways = 0;

        for (int val : distinct_vals) {
            for(int i=0; i<64; ++i) {
                next_sz[i] = dp_sz[i];
                next_cnt[i] = dp_cnt[i];
            }

            for (int x = 0; x < 64; ++x) {
                if (dp_sz[x] >= best_sz) continue;

                int n_sz = dp_sz[x] + 1;
                int n_xor = x ^ val;

                if (n_xor == 0) {
                    if (n_sz < best_sz) {
                        best_sz = n_sz;
                        best_ways = dp_cnt[x];
                    } else if (n_sz == best_sz) {
                        best_ways = (best_ways + dp_cnt[x]) % MOD;
                    }
                } else {
                    if (n_sz < next_sz[n_xor]) {
                        next_sz[n_xor] = n_sz;
                        next_cnt[n_xor] = dp_cnt[x];
                    } else if (n_sz == next_sz[n_xor]) {
                        next_cnt[n_xor] = (next_cnt[n_xor] + dp_cnt[x]) % MOD;
                    }
                }
            }

            for(int i=0; i<64; ++i) {
                dp_sz[i] = next_sz[i];
                dp_cnt[i] = next_cnt[i];
            }
        }

        if (best_sz == 100) {
            cout << "-1\n";
        } else {
            cout << (r - l + 1) - best_sz << " " << best_ways << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
