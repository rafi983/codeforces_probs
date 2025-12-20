#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    int zeros_count = 0;
    long long current_sum = 0;
    int zero_idx = -1;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] == 0) {
            zeros_count++;
            zero_idx = i;
        }
        current_sum += p[i];
    }

    if (zeros_count == 1) {
        long long total_sum = (long long)n * (n + 1) / 2;
        int missing = total_sum - current_sum;
        p[zero_idx] = missing;
    }

    int L = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] != 0) {
            if (p[i] == i + 1) {
                L++;
            } else {
                break;
            }
        } else {
            break;
        }
    }

    int K = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (p[i] != 0) {
            if (p[i] == i + 1) {
                K++;
            } else {
                break;
            }
        } else {
            break;
        }
    }

    if (L + K >= n) {
        cout << 0 << endl;
    } else {
        cout << n - L - K << endl;
    }
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

