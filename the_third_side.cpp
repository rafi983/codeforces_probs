#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        sum += a;
    }
    cout << sum - (n - 1) << "\n";
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

