#include <bits/stdc++.h>
using namespace std;

static pair<long long, vector<long long>> kadane_with_inclusion(const vector<long long>& a) {
    int n = (int)a.size();
    vector<long long> leftEnd(n), rightStart(n);

    leftEnd[0] = a[0];
    for (int i = 1; i < n; ++i) {
        leftEnd[i] = max(a[i], leftEnd[i - 1] + a[i]);
    }

    rightStart[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightStart[i] = max(a[i], rightStart[i + 1] + a[i]);
    }

    long long M = leftEnd[0];
    for (int i = 1; i < n; ++i) {
        M = max(M, leftEnd[i]);
    }
    for (int i = 0; i < n; ++i) {
        M = max(M, rightStart[i]);
    }

    vector<long long> bestInc(n);
    for (int i = 0; i < n; ++i) {
        bestInc[i] = leftEnd[i] + rightStart[i] - a[i];
    }

    return {M, bestInc};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        auto [M, bestInc] = kadane_with_inclusion(a);

        if (k % 2 == 0) {
            cout << M << "\n";
        } else {
            long long ans = M;
            for (int i = 0; i < n; ++i) {
                long long cand = bestInc[i] + llabs(b[i]);
                if (cand > ans) {
                    ans = cand;
                }
            }
            cout << ans << "\n";
        }
    }

    return 0;
}

