#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;
    string s;
    cin >> s;

    if (k == 0) {
        cout << s << "\n";
        return;
    }

    if (n < 3) {
        cout << s << "\n";
        return;
    }

    string s_prev = s;
    string s_prev2 = "";

    for (long long t = 1; t <= k; ++t) {
        string s_next = s_prev;
        for (int i = 1; i < n - 1; ++i) {
            if (s_prev[i-1] == '1' && s_prev[i+1] == '1') {
                s_next[i] ^= 1;
            }
        }

        if (s_next == s_prev) {
            cout << s_next << "\n";
            return;
        }

        if (t >= 2 && s_next == s_prev2) {
            long long rem = k - t;
            if (rem % 2 == 0) cout << s_next << "\n";
            else cout << s_prev << "\n";
            return;
        }

        s_prev2 = s_prev;
        s_prev = s_next;
    }
    cout << s_prev << "\n";
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

