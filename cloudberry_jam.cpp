#include <iostream>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    cout << n * 2 << "\n";
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

