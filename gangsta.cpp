#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    long long s1 = (long long)n * (n + 1) * (n + 2) / 6;

    vector<int> p(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int val = (s[i] == '1' ? 1 : -1);
        p[i + 1] = p[i] + val;
    }

    sort(p.begin(), p.end());

    long long s2 = 0;
    for (int k = 0; k <= n; ++k) {
        long long coef = 2LL * k - n;
        s2 += coef * p[k];
    }

    // Result is (S1 + S2) / 2
    cout << (s1 + s2) / 2 << "\n";
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
