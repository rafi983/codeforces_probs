#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n - 2);
    for (int i = 0; i < n - 2; ++i) {
        cin >> b[i];
    }

    bool possible = true;

    for (int i = 0; i < n - 4; ++i) {
        if (b[i] == 1 && b[i + 1] == 0 && b[i + 2] == 1) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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

