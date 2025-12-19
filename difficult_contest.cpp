#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    vector<int> count(26, 0);
    for (char c : s) {
        count[c - 'A']++;
    }

    string res = "";
    res.reserve(s.length());

    // Append all 'T's
    if (count['T' - 'A'] > 0) {
        res.append(count['T' - 'A'], 'T');
        count['T' - 'A'] = 0;
    }

    // Append all 'F's
    if (count['F' - 'A'] > 0) {
        res.append(count['F' - 'A'], 'F');
        count['F' - 'A'] = 0;
    }

    // Append all 'N's
    if (count['N' - 'A'] > 0) {
        res.append(count['N' - 'A'], 'N');
        count['N' - 'A'] = 0;
    }

    // Append remaining characters
    for (int i = 0; i < 26; ++i) {
        if (count[i] > 0) {
            res.append(count[i], (char)('A' + i));
        }
    }

    cout << res << "\n";
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

