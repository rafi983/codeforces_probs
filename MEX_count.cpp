#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 2, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int M = 0;
    while (cnt[M] > 0) {
        M++;
    }
    // M is the MEX of the original array

    vector<int> diff(n + 2, 0);
    for (int x = 0; x <= M; ++x) {
        int L = cnt[x];
        int R = n - x;
        if (L <= R) {
            diff[L]++;
            diff[R + 1]--;
        }
    }

    int current = 0;
    for (int k = 0; k <= n; ++k) {
        current += diff[k];
        cout << current << (k == n ? "" : " ");
    }
    cout << "\n";
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

