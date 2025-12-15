#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> l(k), r(k);
    for (int i = 0; i < k; ++i) cin >> l[i];
    for (int i = 0; i < k; ++i) cin >> r[i];
    int q;
    cin >> q;
    vector<int> x(q);
    for (int i = 0; i < q; ++i) cin >> x[i];

    vector<int> diff(n + 2, 0);

    for (int val : x) {
        int idx = lower_bound(r.begin(), r.end(), val) - r.begin();
        int L = l[idx];
        int R = r[idx];

        int a = min(val, L + R - val);
        int mid = (L + R) / 2;

        diff[a]++;
        diff[mid + 1]--;
    }

    vector<int> cnt(n + 1, 0);
    int running = 0;
    for(int i = 1; i <= n; ++i) {
        running += diff[i];
        cnt[i] = running;
    }

    for (int i = 0; i < k; ++i) {
        int L = l[i];
        int R = r[i];
        for (int j = L; j <= (L + R) / 2; ++j) {
            if (cnt[j] % 2 != 0) {
                int sym = L + R - j;
                swap(s[j - 1], s[sym - 1]);
            }
        }
    }

    cout << s << endl;
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

