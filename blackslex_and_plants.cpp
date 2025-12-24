#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;


    vector<vector<long long>> LevelD;
    vector<vector<long long>> LevelDD;
    vector<vector<int>> Offsets;
    vector<vector<int>> Counts;
    vector<int> S;

    int max_j = 0;
    while ((1 << max_j) <= n) {
        max_j++;
    }

    LevelD.resize(max_j);
    LevelDD.resize(max_j);
    Offsets.resize(max_j);
    Counts.resize(max_j);
    S.resize(max_j);

    for (int j = 0; j < max_j; ++j) {
        int s = 1 << (j + 1);
        S[j] = s;
        int current_offset = 0;

        Offsets[j].resize(s);
        Counts[j].resize(s);



        for (int rem = 0; rem < s; ++rem) {
            int cnt = 0;
            if (rem < n) {
                cnt = (n - 1 - rem) / s + 1;
            }
            Counts[j][rem] = cnt;
            Offsets[j][rem] = current_offset;
            current_offset += cnt;
        }
        LevelD[j].assign(current_offset, 0);
        LevelDD[j].assign(current_offset, 0);
    }

    for (int k = 0; k < q; ++k) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        for (int j = 0; j < max_j; ++j) {
            int s = S[j];


            long long target_rem_long = (long long)l - 1 + (1 << j);


            int rem = target_rem_long % s;
            if (rem < 0) rem += s; // Should not happen but safe.


            int num = l - rem;
            int k_min = (num + s - 1) / s;
            if (num < 0) k_min = num / s; // integer division truncates towards 0.

            if (l <= rem) k_min = 0;
            else k_min = (l - rem + s - 1) / s;

            if (r < rem) continue;
            int k_max = (r - rem) / s;

            if (k_min > k_max) continue;

            // Check bounds against cnt
            int cnt = Counts[j][rem];
            if (k_min >= cnt) continue;
            if (k_max >= cnt) k_max = cnt - 1;


            long long A = 1LL << (2 * j + 1);
            long long B = (long long)(rem - l + 1) << j;

            int offset = Offsets[j][rem];
            int idx_start = offset + k_min;
            int idx_end = offset + k_max;

            // D[k_min] += A * k_min + B
            LevelD[j][idx_start] += A * k_min + B;

            // D[k_max + 1] -= A * k_max + B
            if (k_max + 1 < cnt) {
                LevelD[j][idx_end + 1] -= A * k_max + B;
            }

            // DD[k_min + 1] += A
            if (k_min + 1 < cnt) {
                LevelDD[j][idx_start + 1] += A;
            }

            // DD[k_max + 1] -= A
            if (k_max + 1 < cnt) {
                LevelDD[j][idx_end + 1] -= A;
            }
        }
    }

    vector<long long> final_ans(n, 0);

    for (int j = 0; j < max_j; ++j) {
        int s = S[j];
        for (int rem = 0; rem < s; ++rem) {
            int cnt = Counts[j][rem];
            if (cnt == 0) continue;

            int offset = Offsets[j][rem];
            long long current_slope = 0;
            long long current_val = 0;

            for (int k = 0; k < cnt; ++k) {
                current_slope += LevelDD[j][offset + k];
                LevelD[j][offset + k] += current_slope;
                current_val += LevelD[j][offset + k];

                int p = k * s + rem;
                if (p < n) {
                    final_ans[p] += current_val;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << final_ans[i] << (i == n - 1 ? "" : " ");
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
