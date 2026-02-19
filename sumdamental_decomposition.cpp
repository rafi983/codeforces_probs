#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long n, x;
    cin >> n >> x;

    long long current_cnt = 0;
    long long temp_x = x;
    while (temp_x > 0) {
        if (temp_x & 1) current_cnt++;
        temp_x >>= 1;
    }

    if (current_cnt >= n) {
        cout << x << "\n";
        return;
    }

    long long diff = n - current_cnt;
    long long ans = x;

    for (int b = 0; b < 62; ++b) {
        if (diff <= 0) break;

        long long current = (x >> b) & 1;
        long long limit = n;
        long long available_space = limit - current;
        long long can_add_pairs = available_space / 2;

        long long needed_pairs = (diff + 1) / 2;
        long long add = min(can_add_pairs, needed_pairs);

        ans += add * 2 * (1LL << b);
        diff -= add * 2;
    }

    if (diff > 0) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
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

