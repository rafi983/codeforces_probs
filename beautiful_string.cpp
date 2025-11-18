#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;


    bool isPalin = true;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            isPalin = false;
            break;
        }
    }
    if (isPalin) {
        cout << "0\n";
        return;
    }

    vector<int> zeros, ones;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') zeros.push_back(i);
        else ones.push_back(i);
    }

    string remaining = "";
    for (int i : ones) remaining += s[i];
    isPalin = true;
    int len = remaining.length();
    for (int i = 0; i < len / 2; i++) {
        if (remaining[i] != remaining[len - 1 - i]) {
            isPalin = false;
            break;
        }
    }
    if (isPalin) {
        cout << zeros.size() << "\n";
        for (int i = 0; i < zeros.size(); i++) {
            if (i > 0) cout << " ";
            cout << (zeros[i] + 1);
        }
        cout << "\n";
        return;
    }

    // Strategy 3: Remove all 1s
    remaining = "";
    for (int i : zeros) remaining += s[i];
    isPalin = true;
    len = remaining.length();
    for (int i = 0; i < len / 2; i++) {
        if (remaining[i] != remaining[len - 1 - i]) {
            isPalin = false;
            break;
        }
    }
    if (isPalin) {
        cout << ones.size() << "\n";
        for (int i = 0; i < ones.size(); i++) {
            if (i > 0) cout << " ";
            cout << (ones[i] + 1);
        }
        cout << "\n";
        return;
    }

    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << (i + 1);
    }
    cout << "\n";
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

