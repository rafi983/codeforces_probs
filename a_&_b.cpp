#include <bits/stdc++.h>
using namespace std;

static long long min_group_swaps(const string &s, char ch) {
    vector<int> pos;
    pos.reserve(s.size());
    for (int i = 0; i < (int)s.size(); ++i) if (s[i] == ch) pos.push_back(i);
    int m = (int)pos.size();
    if (m <= 1) return 0LL;
    long long c = (long long)pos[m / 2] - (m / 2);
    long long ans = 0;
    for (int i = 0; i < m; ++i) ans += llabs((long long)pos[i] - i - c);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        s.resize(n);
        long long ans = min(min_group_swaps(s, 'a'), min_group_swaps(s, 'b'));
        cout << ans << '\n';
    }
    return 0;
}

