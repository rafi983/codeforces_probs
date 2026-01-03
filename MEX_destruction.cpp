#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int first = -1;
    int last = -1;

    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) {
            if (first == -1) first = i;
            last = i;
        }
    }

    if (first == -1) {
        cout << 0 << endl;
        return;
    }

    bool zero_in_between = false;
    for (int i = first; i <= last; ++i) {
        if (a[i] == 0) {
            zero_in_between = true;
            break;
        }
    }

    if (zero_in_between) {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
    }
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

