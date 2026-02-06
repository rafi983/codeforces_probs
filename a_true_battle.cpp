#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (s[0] == '1' || s[n - 1] == '1') {
        cout << "YES" << endl;
        return;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '1' && s[i + 1] == '1') {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
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
