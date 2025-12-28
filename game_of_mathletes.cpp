#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x <= n) {
            cnt[x]++;
        }
    }

    int score = 0;
    for (int i = 1; i <= n; ++i) {
        int target = k - i;
        if (target >= i && target <= n) {
            if (i == target) {
                score += cnt[i] / 2;
            } else {
                score += min(cnt[i], cnt[target]);
            }
        }
    }
    cout << score << endl;
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

