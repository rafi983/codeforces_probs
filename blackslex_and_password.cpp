
#include <iostream>

using namespace std;

void solve() {
    int k, x;
    cin >> k >> x;
    cout << k * x + 1 << endl;
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
