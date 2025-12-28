#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<long long> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<long long> prefA(n + 1, 0);
    for (int i = 0; i < n; ++i) prefA[i+1] = prefA[i] + a[i];

    vector<long long> prefB(m + 1, 0);
    for (int i = 0; i < m; ++i) prefB[i+1] = prefB[i] + b[i];

    auto get_score_A = [&](int count) -> long long {
        if (count == 0) return 0;
        long long sum_large = prefA[n] - prefA[n - count];
        long long sum_small = prefA[count];
        return sum_large - sum_small;
    };

    auto get_score_B = [&](int count) -> long long {
        if (count == 0) return 0;
        long long sum_large = prefB[m] - prefB[m - count];
        long long sum_small = prefB[count];
        return sum_large - sum_small;
    };

    int k_max = min({n, m, (n + m) / 3});
    cout << k_max << "\n";

    if (k_max == 0) {
        return;
    }

    vector<long long> results;
    results.reserve(k_max);
    for (int k = 1; k <= k_max; ++k) {
        int L = max(0, 2 * k - m);
        int R = min(k, n - k);

        int low = L, high = R;
        while (high - low > 2) {
            int m1 = low + (high - low) / 3;
            int m2 = high - (high - low) / 3;
            long long s1 = get_score_A(m1) + get_score_B(k - m1);
            long long s2 = get_score_A(m2) + get_score_B(k - m2);
            if (s1 < s2) {
                low = m1;
            } else {
                high = m2;
            }
        }

        long long max_score = -1;
        for (int x = low; x <= high; ++x) {
            max_score = max(max_score, get_score_A(x) + get_score_B(k - x));
        }
        results.push_back(max_score);
    }

    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << (i == results.size() - 1 ? "" : " ");
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

