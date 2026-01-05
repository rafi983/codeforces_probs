#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<int> pairs;
    vector<int> singles;
    for (int i = 0; i < n; ++i) {
        if (i + 1 < n && a[i] == a[i+1]) {
            pairs.push_back(a[i]);
            i++;
        } else {
            singles.push_back(a[i]);
        }
    }

    if (pairs.size() >= 2) {
        cout << pairs[0] << " " << pairs[0] << " " << pairs[1] << " " << pairs[1] << endl;
    } else if (pairs.size() == 0) {
        cout << -1 << endl;
    } else {
        int x = pairs[0];
        bool found = false;
        for (size_t i = 0; i + 1 < singles.size(); ++i) {
            long long diff = (long long)singles[i+1] - singles[i];
            if (diff < 2LL * x) {
                cout << x << " " << x << " " << singles[i] << " " << singles[i+1] << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << -1 << endl;
        }
    }
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

