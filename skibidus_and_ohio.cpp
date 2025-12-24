#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;
    bool possible = false;
    for (size_t i = 0; i + 1 < s.length(); ++i) {
        if (s[i] == s[i+1]) {
            possible = true;
            break;
        }
    }
    if (possible) {
        cout << 1 << endl;
    } else {
        cout << s.length() << endl;
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

