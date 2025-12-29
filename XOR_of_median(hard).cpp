#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int K_val;
int Limit_val; // This will be m - 1

pair<int, int> memo[32][2];
bool visited[32][2];


pair<int, int> solve(int bit, bool tight) {
    if (bit < 0) return {1, 0};
    if (visited[bit][tight]) return memo[bit][tight];

    int limit_bit = tight ? (Limit_val >> bit) & 1 : 1;
    int req_bit = (K_val >> bit) & 1;

    int count_parity = 0;
    int xor_sum = 0;

    if (req_bit == 1) {
        if (limit_bit >= 1) {
            // We can put 1
            pair<int, int> res = solve(bit - 1, tight && (limit_bit == 1));
            if (res.first) { // if count is odd
                count_parity ^= 1;
                xor_sum ^= res.second;
                xor_sum ^= (1 << bit);
            } else {
                xor_sum ^= res.second;
            }
        }
    } else {
        // req_bit is 0, we can put 0 or 1

        {
            pair<int, int> res0 = solve(bit - 1, tight && (limit_bit == 0));
            if (res0.first) {
                count_parity ^= 1;
                xor_sum ^= res0.second;
            } else {
                xor_sum ^= res0.second;
            }
        }

        // Option 1:
        if (limit_bit >= 1) {
            pair<int, int> res1 = solve(bit - 1, tight && (limit_bit == 1));
            if (res1.first) {
                count_parity ^= 1;
                xor_sum ^= res1.second;
                xor_sum ^= (1 << bit);
            } else {
                xor_sum ^= res1.second;
            }
        }
    }

    visited[bit][tight] = true;
    memo[bit][tight] = {count_parity, xor_sum};
    return {count_parity, xor_sum};
}

void solve_test_case() {
    int k_bits;
    int m;
    if (!(cin >> k_bits >> m)) return;
    string s;
    cin >> s;

    int W = 0;
    for (char c : s) {
        if (c == '1') W++;
    }

    int ans = 0;
    int limit_k = min(W, m);
    Limit_val = m - 1;

    for (int k = 1; k <= limit_k; ++k) {
        if (((W - k) & ((k - 1) / 2)) == 0) {
            K_val = k - 1;
            // Clear memo
            for(int i=0; i<32; ++i) {
                visited[i][0] = false;
                visited[i][1] = false;
            }
            pair<int, int> res = solve(30, true);
            ans ^= res.second;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve_test_case();
        }
    }
    return 0;
}
