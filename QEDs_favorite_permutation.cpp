#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    vector<int> p(n);
    vector<bool> v(n + 1, false);

    int current_max = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] > current_max) current_max = p[i];
        if (current_max != (i + 1)) {
            v[i + 1] = true;
        }
    }

    string s;
    cin >> s;


    int invalid_count = 0;

    auto check = [&](int i) -> int {
        if (i < 1 || i >= n) return 0;
        if (s[i - 1] == 'L' && s[i] == 'R') {
            if (v[i]) return 1;
        }
        return 0;
    };

    // Initial count
    for (int i = 1; i < n; ++i) {
        invalid_count += check(i);
    }

    for (int k = 0; k < q; ++k) {
        int idx;
        cin >> idx; // 1-based index of character to change

        invalid_count -= check(idx - 1);
        invalid_count -= check(idx);

        if (s[idx - 1] == 'L') s[idx - 1] = 'R';
        else s[idx - 1] = 'L';

        invalid_count += check(idx - 1);
        invalid_count += check(idx);

        if (invalid_count == 0) cout << "YES\n";
        else cout << "NO\n";
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
