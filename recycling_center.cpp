#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long c;
    if (!(cin >> n >> c)) return;
    vector<long long> a(n);
    vector<int> valid_k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > c) continue;
        long long ratio = c / a[i];
        int k = 0;
        while ((1LL << (k + 1)) <= ratio) {
            k++;
        }
        valid_k.push_back(k);
    }
    sort(valid_k.begin(), valid_k.end());

    int m = valid_k.size();
    int max_p = 0;

    for (int p = 1; p <= m; ++p) {
        bool ok = true;

        for (int i = 0; i < p; ++i) {
            if (valid_k[m - p + i] < i) {
                ok = false;
                break;
            }
        }
        if (ok) {
            max_p = p;
        }
    }

    cout << n - max_p << "\n";
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
