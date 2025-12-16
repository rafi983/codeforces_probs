#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> a;

void solve_recursive(int r) {
    if (r < 0) return;
    if (r == 0) {
        a[0] = 0;
        return;
    }

    int k = 0;
    while ((1 << (k + 1)) <= r) {
        k++;
    }
    // Now 2^k <= r < 2^{k+1}

    // If r is exactly 2^{k+1} - 1
    if (r == (1 << (k + 1)) - 1) {
        for (int i = 0; i <= r; ++i) {
            a[i] = r ^ i;
        }
        return;
    }

    int high_start = (1 << k);
    int match_target = (1 << (k + 1)) - 1;
    int low_end = match_target - r;

    for (int x = high_start; x <= r; ++x) {
        int y = match_target ^ x;
        a[x] = y;
        a[y] = x;
    }

    solve_recursive(low_end - 1);
}

void solve() {
    int l, r;
    cin >> l >> r;

    a.assign(r + 1, 0);
    solve_recursive(r);

    long long sum_val = 0;
    for (int i = 0; i <= r; ++i) {
        sum_val += (i | a[i]);
    }
    cout << sum_val << "\n";
    for (int i = 0; i <= r; ++i) {
        cout << a[i] << (i == r ? "" : " ");
    }
    cout << "\n";
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

