#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    string n_str;
    if (!(cin >> n_str)) return;

    long long sum_digits = 0;
    int cnt2 = 0;
    int cnt3 = 0;

    for (char c : n_str) {
        int digit = c - '0';
        sum_digits += digit;
        if (digit == 2) cnt2++;
        if (digit == 3) cnt3++;
    }

    bool possible = false;
    for (int i = 0; i <= min(cnt2, 8); ++i) {
        for (int j = 0; j <= min(cnt3, 2); ++j) {
            if ((sum_digits + 2 * i + 6 * j) % 9 == 0) {
                possible = true;
                break;
            }
        }
        if (possible) break;
    }

    if (possible) cout << "YES" << endl;
    else cout << "NO" << endl;
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

