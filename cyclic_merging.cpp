#include <bits/stdc++.h>
using namespace std;

long long solve_linear(const vector<long long>& b) {
    int n = (int)b.size();
    vector<long long> st;
    st.reserve(n);
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        long long x = b[i];
        while (!st.empty() && st.back() <= x) {
            long long mid = st.back();
            st.pop_back();
            long long left = st.empty() ? (long long)4e18 : st.back();
            ans += min(left, x);
        }
        st.push_back(x);
    }

    while (st.size() > 1) {
        long long mid = st.back();
        st.pop_back();
        ans += st.back();
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }
        if (n == 2) {
            cout << max(a[0], a[1]) << '\n';
            continue;
        }

        int pos = int(max_element(a.begin(), a.end()) - a.begin());
        vector<long long> b(n);
        for (int i = 0; i < n; ++i) {
            b[i] = a[(pos + i) % n];
        }

        long long ans = solve_linear(b);
        cout << ans << '\n';
    }

    return 0;
}
