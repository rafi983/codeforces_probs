#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> P(n);
    P[0] = a[0];
    for (int i = 1; i < n; ++i) {
        P[i] = min(P[i - 1], a[i]);
    }

    vector<long long> S(n);
    S[0] = P[0];
    for (int i = 1; i < n; ++i) {
        S[i] = S[i - 1] + P[i];
    }

    int first_non_strict = n;
    for (int i = 1; i < n; ++i) {
        if (P[i] == P[i - 1]) {
            first_non_strict = i;
            break;
        }
    }

    long long ans = S[n - 1];
    long long min_diff = INF;

    for (int j = 1; j < n; ++j) {

        if (j == 1) {
            min_diff = INF;
        } else {
            long long diff = (long long)P[j - 2] - P[j - 1];
            min_diff = min(min_diff, diff);
        }

        long long current_val;
        if (first_non_strict < j) {
            current_val = S[j - 1];
        } else {
            long long cost = min(min_diff, (long long)a[j]);
            current_val = S[j - 1] + cost;
        }
        ans = min(ans, current_val);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

