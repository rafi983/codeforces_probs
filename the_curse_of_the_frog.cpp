#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long x;
    cin >> n >> x;

    long long sum_C = 0;
    long long max_S = -4000000000000000000LL;

    for (int i = 0; i < n; ++i) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long C = (b - 1) * a;
        long long S = b * a - c;
        sum_C += C;
        if (S > max_S) {
            max_S = S;
        }
    }

    if (sum_C >= x) {
        cout << 0 << "\n";
        return;
    }

    if (max_S <= 0) {
        cout << -1 << "\n";
        return;
    }

    long long needed = x - sum_C;
    long long ans = (needed + max_S - 1) / max_S;
    cout << ans << "\n";
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
