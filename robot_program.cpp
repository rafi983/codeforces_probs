#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    long long x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;

    auto get_time = [&](long long start_pos) -> long long {
        long long current_pos = start_pos;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                current_pos--;
            } else {
                current_pos++;
            }
            if (current_pos == 0) {
                return i + 1;
            }
        }
        return -1;
    };

    long long t1 = get_time(x);
    if (t1 == -1 || t1 > k) {
        cout << 0 << endl;
        return;
    }

    long long ans = 1;
    k -= t1;

    long long t2 = get_time(0);
    if (t2 != -1) {
        ans += k / t2;
    }

    cout << ans << endl;
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

