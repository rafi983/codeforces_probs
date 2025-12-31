#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n, m;
    if (!(cin >> n >> m)) return;
    cout << max(n, m) + 1 << endl;
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

