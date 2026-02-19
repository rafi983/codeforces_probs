#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(30, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int b = 0; b < 30; ++b) {
            if ((a[i] >> b) & 1) {
                cnt[b]++;
            }
        }
    }

    long long max_sum = 0;

    for (int i = 0; i < n; ++i) {
        long long current_sum = 0;
        for (int b = 0; b < 30; ++b) {
            long long contribution = 0;
            if ((a[i] >> b) & 1) {
                contribution = (long long)(n - cnt[b]) * (1LL << b);
            } else {
                contribution = (long long)cnt[b] * (1LL << b);
            }
            current_sum += contribution;
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    cout << max_sum << "\n";
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

