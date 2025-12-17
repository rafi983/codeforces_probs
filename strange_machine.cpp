#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    bool hasB = false;
    for (char c : s) {
        if (c == 'B') {
            hasB = true;
            break;
        }
    }

    while (q--) {
        long long a;
        cin >> a;
        if (!hasB) {
            cout << a << "\n";
        } else {
            long long steps = 0;
            int idx = 0;
            long long curr = a;
            while (curr > 0) {
                if (s[idx] == 'A') {
                    curr--;
                } else {
                    curr /= 2;
                }
                idx++;
                if (idx == n) idx = 0;
                steps++;
            }
            cout << steps << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
