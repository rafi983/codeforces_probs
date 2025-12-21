#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    cin >> s;
    char min_d = '9';
    for (char c : s) {
        if (c < min_d) {
            min_d = c;
        }
    }
    cout << min_d << "\n";
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

