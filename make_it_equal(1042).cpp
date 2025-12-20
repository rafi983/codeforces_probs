#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> s(n);
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        long long rem = val % k;
        s[i] = min(rem, k - rem);
    }
    vector<long long> t(n);
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        long long rem = val % k;
        t[i] = min(rem, k - rem);
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if (s == t) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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

