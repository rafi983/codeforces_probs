#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int balance = 0;
    bool found_zero_before_end = false;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '(') balance++;
        else balance--;
        if (balance == 0) {
            found_zero_before_end = true;
            break;
        }
    }

    if (found_zero_before_end) cout << "YES" << endl;
    else cout << "NO" << endl;
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
