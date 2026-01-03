#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool has_p = false;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == 'p') {
            has_p = true;
            break;
        }
    }

    bool has_s = false;
    for (int i = 1; i < n; ++i) {
        if (s[i] == 's') {
            has_s = true;
            break;
        }
    }

    if (has_p && has_s) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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

