#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> present(n + 1, false);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        present[a[i]] = true;
    }

    vector<int> fillers;
    for (int i = 1; i <= n; ++i) {
        if (!present[i]) {
            fillers.push_back(i);
        }
    }

    vector<int> b(n);
    vector<bool> placed(n + 1, false);
    int filler_idx = 0;

    for (int i = 0; i < n; ++i) {
        if (!placed[a[i]]) {
            b[i] = a[i];
            placed[a[i]] = true;
        } else {
            b[i] = fillers[filler_idx++];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << b[i] << (i == n - 1 ? "" : " ");
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
