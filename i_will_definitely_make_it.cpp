#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<int> h(n);
    int max_h = -1;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        if (h[i] > max_h) max_h = h[i];
    }

    int start_h = h[k - 1];
    if (start_h == max_h) {
        cout << "YES\n";
        return;
    }

    vector<int> relevant;
    relevant.reserve(n);
    for (int x : h) {
        if (x >= start_h) {
            relevant.push_back(x);
        }
    }

    sort(relevant.begin(), relevant.end());
    auto last = unique(relevant.begin(), relevant.end());
    relevant.erase(last, relevant.end());

    for (size_t i = 0; i < relevant.size() - 1; ++i) {
        if (relevant[i + 1] - relevant[i] > start_h) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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

