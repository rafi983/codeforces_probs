#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int count = 0;
    int i = 0;
    while (i <= n - k) {
        int found_bad_at = -1;
        for (int j = 0; j < k; ++j) {
            if (a[i + j] == 1) {
                found_bad_at = i + j;
                break;
            }
        }

        if (found_bad_at == -1) {
            count++;
            i += k + 1;
        } else {
            i = found_bad_at + 1;
        }
    }
    cout << count << "\n";
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

