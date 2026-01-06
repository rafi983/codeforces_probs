#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    int count = 0;
    int current_len = 0;
    for (int i = 0; i < n; ++i) {
        if (current_len + s[i].length() <= m) {
            current_len += s[i].length();
            count++;
        } else {
            break;
        }
    }
    cout << count << endl;
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

