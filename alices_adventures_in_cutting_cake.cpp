#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    long long v;
    if (!(cin >> n >> m >> v)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<int> P(m + 1, -2);
    P[0] = 0;
    long long current_sum = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        current_sum += a[i];
        if (current_sum >= v) {
            count++;
            if (count <= m) {
                P[count] = i + 1;
            }
            current_sum = 0;
        }
    }

    vector<int> S(m + 1, -2);
    S[0] = n + 1;
    current_sum = 0;
    count = 0;
    for (int i = n - 1; i >= 0; --i) {
        current_sum += a[i];
        if (current_sum >= v) {
            count++;
            if (count <= m) {
                S[count] = i + 1;
            }
            current_sum = 0;
        }
    }

    long long max_tastiness = -1;

    for (int k = 0; k <= m; ++k) {
        if (P[k] == -2 || S[m - k] == -2) continue;

        if (P[k] < S[m - k]) {
            long long alice_sum = pref[S[m - k] - 1] - pref[P[k]];
            if (alice_sum > max_tastiness) {
                max_tastiness = alice_sum;
            }
        }
    }

    cout << max_tastiness << "\n";
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
