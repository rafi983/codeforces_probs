#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n, rK, cK, rD, cD;
    if (!(cin >> n >> rK >> cK >> rD >> cD)) return;

    long long ans = 0;

    if (rK < rD) ans = max(ans, rD);
    if (rK > rD) ans = max(ans, n - rD);
    if (cK < cD) ans = max(ans, cD);
    if (cK > cD) ans = max(ans, n - cD);

    cout << ans << "\n";
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
