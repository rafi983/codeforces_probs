#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;


 long long max_val = (long long)n * n / 2;
    cout << (max_val / 2) + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

