#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int odds = 0;
    int evens = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a % 2 != 0) {
            odds++;
        } else {
            evens++;
        }
    }

    if (evens > 0) {
        cout << odds + 1 << endl;
    } else {
        cout << odds - 1 << endl;
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

