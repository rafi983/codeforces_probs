#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<long long> a(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
    }
    vector<int> b(k);
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
    }

    sort(a.begin(), a.end(), greater<long long>());
    sort(b.begin(), b.end());

    long long savings = 0;
    int current_idx = 0;
    for (int i = 0; i < k; ++i) {
        int size = b[i];
        if (current_idx + size <= n) {
            savings += a[current_idx + size - 1];
            current_idx += size;
        } else {
            break;
        }
    }

    cout << total_sum - savings << endl;
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

