#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;


const int MAXV = 100005;
vector<int> divs[MAXV];
vector<int> indices[MAXV];

void precompute() {
    for (int i = 1; i < MAXV; ++i) {
        for (int j = i; j < MAXV; j += i) {
            divs[j].push_back(i);
        }
    }
}

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;


    vector<int> a(n + 1);
    vector<int> present_values;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (indices[a[i]].empty()) {
            present_values.push_back(a[i]);
        }
        indices[a[i]].push_back(i);
    }

    for (int j = 0; j < q; ++j) {
        int k, l, r;
        cin >> k >> l >> r;

        long long ans = 0;
        int curr = l;

        while (curr <= r) {
            if (k == 0) break;
            if (k == 1) {
                ans += (long long)(r - curr + 1);
                break;
            }

            int next_pos = r + 1;

            for (int d : divs[k]) {
                if (d == 1) continue;
                if (indices[d].empty()) continue;

                auto it = lower_bound(indices[d].begin(), indices[d].end(), curr);
                if (it != indices[d].end()) {
                    if (*it < next_pos) {
                        next_pos = *it;
                    }
                }
            }

            ans += (long long)k * (next_pos - curr);

            if (next_pos > r) {
                break;
            }

            int val = a[next_pos];
            while (k % val == 0) {
                k /= val;
            }
            ans += k;
            curr = next_pos + 1;
        }
        cout << ans << "\n";
    }

    for (int v : present_values) {
        indices[v].clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

