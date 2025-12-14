#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        counts[a]++;
    }

    int ans = 0;
    for (auto const& [val, count] : counts) {
        ans += count / 3;
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

