#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    for (int i = 0; i < n; ++i) {
        if (p[i] == i + 1) {
            continue;
        }
        if (p[i] == i + 2) {
            if (i + 1 < n && p[i+1] == i + 1) {
                i++;
                continue;
            } else {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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
