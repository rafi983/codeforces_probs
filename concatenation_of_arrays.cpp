#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return (long long)p1.first + p1.second < (long long)p2.first + p2.second;
    });

    for (int i = 0; i < n; ++i) {
        cout << a[i].first << " " << a[i].second << (i == n - 1 ? "" : " ");
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
