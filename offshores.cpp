#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long x, y;
    if (!(cin >> n >> x >> y)) return;

    vector<long long> a(n);
    long long total_contribution = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_contribution += (a[i] / x) * y;
    }

    long long max_money = 0;

    for (int i = 0; i < n; ++i) {
        long long current_contribution = (a[i] / x) * y;
        long long final_amount = a[i] + (total_contribution - current_contribution);

        if (final_amount > max_money) {
            max_money = final_amount;
        }
    }
    cout << max_money << "\n";
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

