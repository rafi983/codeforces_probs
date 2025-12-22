#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1 1\n";
        return;
    }
    vector<int> ans(2 * n, 0);
    int m = n / 2;


    for (int i = 0; i < m; ++i) {
        int val = 2 * (m - i);
        ans[i] = val;
        ans[i + val] = val;
    }

    // Place odds > 1
    vector<int> odds;
    for (int x = n; x > 1; --x) {
        if (x % 2 != 0) {
            odds.push_back(x);
        }
    }

    if (!odds.empty()) {
        // Place largest odd at the gap m left by evens
        int largest = odds[0];
        ans[m] = largest;
        ans[m + largest] = largest;

        // Place remaining odds starting from 2m + 1
        int pos = 2 * m + 1;
        for (size_t k = 1; k < odds.size(); ++k) {
            while (ans[pos] != 0) pos++;
            ans[pos] = odds[k];
            ans[pos + odds[k]] = odds[k];
        }
    }

    // Place 1s in the remaining spots
    for (int i = 0; i < 2 * n; ++i) {
        if (ans[i] == 0) {
            ans[i] = 1;
        }
    }

    for (int i = 0; i < 2 * n; ++i) {
        cout << ans[i] << (i == 2 * n - 1 ? "" : " ");
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
