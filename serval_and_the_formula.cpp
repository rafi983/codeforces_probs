#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    long long x, y;
    if (!(cin >> x >> y)) return;
    if (x > y) swap(x, y);
    long long D = y - x;

    if (D == 0) {
        cout << "-1\n";
        return;
    }

    int N = 62; // Sufficient bits
    // ReachC[i][c] = true if carry 'c' at bit 'i' is reachable from c_0=0
    vector<vector<bool>> ReachC(N + 1, vector<bool>(2, false));
    ReachC[0][0] = true;

    for (int i = 0; i < N; ++i) {
        int d = (D >> i) & 1;
        for (int c = 0; c <= 1; ++c) {
            if (!ReachC[i][c]) continue;


            int next_c_0 = d & c;
            ReachC[i+1][next_c_0] = true;


            if (c == (1 ^ d)) {
                // c_{i+1} = (1&d) | (1&c) | (d&c) = d | c
                // Since c = 1^d, one is 0, one is 1. d|c is 1.
                int next_c_1 = 1;
                ReachC[i+1][next_c_1] = true;
            }
        }
    }

    // SuffixOk[i][c] = true if suffix i..N can be formed matching x, starting with carry c
    vector<vector<bool>> SuffixOk(N + 1, vector<bool>(2, false));
    SuffixOk[N][0] = true; // Must end with carry 0
    // SuffixOk[N][1] is false

    for (int i = N - 1; i >= 0; --i) {
        int d = (D >> i) & 1;
        int xi = (x >> i) & 1;
        int ai = xi; // We must match x

        for (int c = 0; c <= 1; ++c) {
            bool possible = false;
            int next_c = -1;

            if (ai == 0) {
                // Valid always
                next_c = d & c;
                possible = true;
            } else {
                // ai == 1
                // Valid if c == 1 ^ d
                if (c == (1 ^ d)) {
                    next_c = 1;
                    possible = true;
                }
            }

            if (possible && SuffixOk[i+1][next_c]) {
                SuffixOk[i][c] = true;
            }
        }
    }



    for (int i = -1; i < N; ++i) {


        if (i == -1) {
            // No divergence. We need SuffixOk[0][0] to be true.
            if (SuffixOk[0][0]) {
                cout << "0\n"; // k = A - x = x - x = 0
                return;
            }
            continue;
        }

        // Divergence at i
        int xi = (x >> i) & 1;
        if (xi == 1) continue; // Can't go greater if x_i is already 1

        // We want a_i = 1
        int di = (D >> i) & 1;
        // For a_i=1 to be valid, we need c_i = 1 ^ di
        int needed_ci = 1 ^ di;

        // And this transitions to c_{i+1} = 1
        int resulting_next_c = 1;

        // Check if needed_ci is reachable
        if (!ReachC[i][needed_ci]) continue;

        // Check if suffix is valid from resulting_next_c
        if (!SuffixOk[i+1][resulting_next_c]) continue;

        // Found a valid i!
        // Construct A
        long long A = 0;

        // Suffix part
        for (int j = i + 1; j < N; ++j) {
            if ((x >> j) & 1) A |= (1LL << j);
        }

        // Bit i
        A |= (1LL << i);

        // Prefix part: find a path to needed_ci
        int curr_c = needed_ci;
        for (int j = i - 1; j >= 0; --j) {
            int d = (D >> j) & 1;

            bool found = false;
            // Try a_j = 0
            for (int prev_c = 0; prev_c <= 1; ++prev_c) {
                if (!ReachC[j][prev_c]) continue;
                // Check transition with a=0
                int next = d & prev_c;
                if (next == curr_c) {
                    // Found path with a_j=0
                    curr_c = prev_c;
                    found = true;
                    break;
                }
            }

            if (found) continue; // a_j = 0

            // Try a_j = 1
            for (int prev_c = 0; prev_c <= 1; ++prev_c) {
                if (!ReachC[j][prev_c]) continue;
                // Check transition with a=1
                if (prev_c == (1 ^ d)) {
                    int next = 1;
                    if (next == curr_c) {
                        A |= (1LL << j);
                        curr_c = prev_c;
                        found = true;
                        break;
                    }
                }
            }
        }

        cout << (A - x) << "\n";
        return;
    }

    cout << "-1\n";
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

