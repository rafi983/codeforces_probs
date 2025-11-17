#include <iostream>
#include <string>
using namespace std;

void solve() {
    char c;
    cin >> c;

    string s = "codeforces";
    if (s.find(c) != string::npos) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

