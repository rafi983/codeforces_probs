#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll k;
        cin >> n >> k;

        vector<ll> q(n), r(n);
        for (int i = 0; i < n; i++) cin >> q[i];
        for (int i = 0; i < n; i++) cin >> r[i];

        sort(q.begin(), q.end(), greater<ll>());
        sort(r.begin(), r.end()); // Sort r in increasing order

        multiset<ll> rSet(r.begin(), r.end());

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ll qVal = q[i];


            ll maxR = (k - qVal) / (qVal + 1);
            if (maxR < 0) continue;

            auto it = rSet.upper_bound(maxR);
            if (it != rSet.begin()) {
                --it;
                ans++;
                rSet.erase(it);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}

