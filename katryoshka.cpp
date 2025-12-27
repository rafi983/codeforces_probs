#include <iostream>
#include <algorithm>

using namespace std;

void solve(int t) {
    long long n, m, k;
    if (!(cin >> n >> m >> k)) return;

    long long ans = 0;


    long long count3 = min({n, m, k});
    ans += count3;
    n -= count3;
    m -= count3;
    k -= count3;

    long long count1 = min(n / 2, k);
    ans += count1;

    cout << "Case " << t << ": " << ans << endl;
}

int main() {
    int t;
    if (cin >> t) {
        for (int i = 1; i <= t; ++i) {
            solve(i);
        }
    }
    return 0;
}

