#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    long long max_val = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        max_val = max(max_val, a[i]);
    }

    if (sum % 2 != 0) {
        cout << -1 << endl;
        return;
    }
    if (2 * max_val > sum) {
        cout << -1 << endl;
        return;
    }

    // Check if 1 operation is enough
    long long current_sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        current_sum += a[i];
        if (current_sum == sum / 2) {
            cout << 1 << endl;
            for (int j = 0; j < n; ++j) {
                cout << a[j] << (j == n - 1 ? "" : " ");
            }
            cout << endl;
            return;
        }
    }

    // 2 operations
    // Find partition into 3 segments
    int p = -1, q = -1;
    long long A1 = 0, A2 = 0, A3 = 0;

    if (a[n - 1] == sum / 2) {
        p = 1;
        q = n - 1;
        A1 = a[0];
        for(int i=1; i<n-1; ++i) A2 += a[i]; // Actually A2 is sum of middle


        p = 0;
        q = n - 2;
        A1 = a[0];
        A2 = 0;
        for(int i=1; i<=n-2; ++i) A2 += a[i];
        A3 = a[n-1];
    } else {
        long long pref = 0;
        int k = 0;
        for (; k < n; ++k) {
            pref += a[k];
            if (pref > sum / 2) break;
        }

        p = k - 1;
        q = k;

        A1 = 0;
        for(int i=0; i<=p; ++i) A1 += a[i];
        A2 = a[q];
        A3 = 0;
        for(int i=q+1; i<n; ++i) A3 += a[i];
    }

    long long K = (A1 + A2 - A3) / 2;

    vector<long long> b1(n, 0);

    // Fill Seg 1 with sum K
    long long rem = K;
    for (int i = 0; i <= p; ++i) {
        long long take = min(a[i], rem);
        b1[i] = take;
        rem -= take;
    }

    // Fill Seg 2 with sum K
    rem = K;
    for (int i = p + 1; i <= q; ++i) {
        long long take = min(a[i], rem);
        b1[i] = take;
        rem -= take;
    }

    // Seg 3 is 0

    cout << 2 << endl;
    for (int i = 0; i < n; ++i) {
        cout << b1[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << (a[i] - b1[i]) << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

