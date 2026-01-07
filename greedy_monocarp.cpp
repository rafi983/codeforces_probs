#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;
    vector<long long> a(n);
    long long sum_all = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum_all += a[i];
    }

    long long min_added = -1;


    if (sum_all <= k) {
        min_added = k - sum_all;
    }

    for (int u = 0; u < n; ++u) {
        long long val_u = a[u];

        vector<long long> M; // Must take (a[i] > a[u])
        vector<long long> C; // Candidates (a[i] <= a[u], i != u)

        long long sum_M_initial = 0;

        for (int i = 0; i < n; ++i) {
            if (i == u) continue;
            if (a[i] > val_u) {
                M.push_back(a[i]);
                sum_M_initial += a[i];
            } else {
                C.push_back(a[i]);
            }
        }

        sort(C.begin(), C.end(), greater<long long>());


        long long current_C_sum = 0;

        for (int cnt = 0; cnt <= C.size(); ++cnt) {


            long long base_sum_needed = sum_M_initial + (long long)cnt * val_u;

            if (base_sum_needed <= k) {
                long long current_sum_initial = sum_M_initial + current_C_sum;
                long long cost = k - current_sum_initial;

                if (min_added == -1 || cost < min_added) {
                    min_added = cost;
                }
            } else {
                break;
            }

            if (cnt < C.size()) {
                current_C_sum += C[cnt];
            }
        }
    }

    cout << min_added << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}

