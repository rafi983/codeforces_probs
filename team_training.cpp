#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long x;
    if (!(cin >> n >> x)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    int ans = 0;
    int current_size = 0;
    for (int i = 0; i < n; ++i) {
        current_size++;
        if (current_size * a[i] >= x) {
            ans++;
            current_size = 0; // Reset for the next team
        }
    }
    cout << ans << "\n";
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

