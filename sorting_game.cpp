#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (is_sorted(s.begin(), s.end())) {
        cout << "Bob" << endl;
        return;
    }

    int zeros = 0;
    for (char c : s) {
        if (c == '0') zeros++;
    }

    vector<int> moves;
    for (int i = 0; i < n; ++i) {
        if (i < zeros) {
            if (s[i] == '1') moves.push_back(i + 1);
        } else {
            if (s[i] == '0') moves.push_back(i + 1);
        }
    }

    cout << "Alice" << endl;
    cout << moves.size() << endl;
    for (int i = 0; i < moves.size(); ++i) {
        cout << moves[i] << (i == moves.size() - 1 ? "" : " ");
    }
    cout << endl;
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
