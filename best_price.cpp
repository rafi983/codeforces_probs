#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> candidates;
    candidates.reserve(2 * n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        candidates.push_back(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        candidates.push_back(b[i]);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    long long max_earnings = 0;

    for (int p : candidates) {

        auto it_b = lower_bound(b.begin(), b.end(), p);
        int buyers = distance(it_b, b.end());

        auto it_a = lower_bound(a.begin(), a.end(), p);
        int positive = distance(it_a, a.end());

        int negative = buyers - positive;

        if (negative <= k) {
            max_earnings = max(max_earnings, (long long)p * buyers);
        }
    }

    cout << max_earnings << endl;
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

