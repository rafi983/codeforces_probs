#include <iostream>
using namespace std;

void solve() {
    long long n, w;
    if (!(cin >> n >> w)) return;
    cout << n - (n / w) << endl;
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
