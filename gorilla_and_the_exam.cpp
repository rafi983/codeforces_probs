#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    vector<int> freqs;
    if (n > 0) {
        int current_count = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] == a[i-1]) {
                current_count++;
            } else {
                freqs.push_back(current_count);
                current_count = 1;
            }
        }
        freqs.push_back(current_count);
    }

    sort(freqs.begin(), freqs.end());

    int ans = freqs.size();
    for (int f : freqs) {
        if (ans == 1) break;
        if (k >= f) {
            k -= f;
            ans--;
        } else {
            break;
        }
    }

    cout << ans << endl;
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

