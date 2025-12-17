#include <iostream>

using namespace std;

void solve() {
    int x;
    if (!(cin >> x)) return;
    long long y = 1000000000LL - 1 - x;
    cout << y << endl;
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

