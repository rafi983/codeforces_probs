#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;

    if (n - 1 < 62) {
        long long max_k = 1LL << (n - 1);
        if (k > max_k) {
            cout << -1 << endl;
            return;
        }
    }

    vector<int> p(n);
    int l = 0, r = n - 1;
    for (int i = 1; i < n; ++i) {
        int rem = n - 1 - i;
        if (rem >= 60) {
            p[l++] = i;
        } else {
            long long count = 1LL << rem;
            if (k <= count) {
                p[l++] = i;
            } else {
                p[r--] = i;
                k -= count;
            }
        }
    }
    p[l] = n;

    for (int i = 0; i < n; ++i) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
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

