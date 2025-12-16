#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXV = 100001;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> cnt(MAXV, 0);
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        cnt[s]++;
    }

    int ans = 1;
    for (int d = 2; d < MAXV; ++d) {
        int current = 0;
        for (int j = d; j < MAXV; j += d) {
            current += cnt[j];
        }
        ans = max(ans, current);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

