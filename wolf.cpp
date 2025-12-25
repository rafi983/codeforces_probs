#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;
    vector<int> p(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    for (int i = 0; i < q; ++i) {
        int l, r, k;
        cin >> l >> r >> k;

        int target_pos = pos[k];
        if (target_pos < l || target_pos > r) {
            cout << -1 << "\n";
            continue;
        }

        int bad_less = 0; // In S_< but value > k
        int bad_greater = 0; // In S_> but value < k
        int count_less = 0; // Size of S_<
        int count_greater = 0; // Size of S_>

        int L = l, R = r;

        while (L <= R) {
            int m = (L + R) / 2;
            if (m == target_pos) {
                break;
            }

            if (target_pos < m) {
                // Need to go left, so p[m] must be > k
                // m is in S_>
                count_greater++;
                if (p[m] < k) {
                    bad_greater++;
                }
                R = m - 1;
            } else {
                // Need to go right, so p[m] must be < k
                // m is in S_<
                count_less++;
                if (p[m] > k) {
                    bad_less++;
                }
                L = m + 1;
            }
        }

        if (count_less > k - 1 || count_greater > n - k) {
            cout << -1 << "\n";
        } else {
            cout << 2 * max(bad_less, bad_greater) << "\n";
        }
    }
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

