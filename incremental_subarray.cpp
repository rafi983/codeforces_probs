#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    bool increasing = true;
    for (int i = 0; i < m - 1; ++i) {
        if (a[i+1] != a[i] + 1) {
            increasing = false;
            break;
        }
    }

    if (increasing) {

        cout << (long long)n - a[m-1] + 1 << endl;
    } else {
        cout << 1 << endl;
    }
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

