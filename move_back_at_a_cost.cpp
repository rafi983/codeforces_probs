#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    vector<pair<int, int>> sorted_a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sorted_a[i] = {a[i], i};
    }
    sort(sorted_a.begin(), sorted_a.end());

    vector<int> kept;
    vector<int> moved;
    int cur = 0;
    int limit = INT_MAX;

    for (int i = 0; i < n; ++i) {
        int val = sorted_a[i].first;
        int idx = sorted_a[i].second;

        if (idx < cur) continue;

        if (val > limit) {
            break;
        }

        for (int j = cur; j < idx; ++j) {
            moved.push_back(a[j] + 1);
            limit = min(limit, a[j] + 1);
        }

        kept.push_back(val);
        cur = idx + 1;
    }

    for (int i = cur; i < n; ++i) {
        moved.push_back(a[i] + 1);
    }

    sort(moved.begin(), moved.end());

    for (int i = 0; i < kept.size(); ++i) {
        cout << kept[i] << " ";
    }
    for (int i = 0; i < moved.size(); ++i) {
        cout << moved[i] << (i == moved.size() - 1 ? "" : " ");
    }
    cout << "\n";
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

