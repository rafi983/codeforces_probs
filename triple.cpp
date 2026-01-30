#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> count(n + 1, 0);
    int ans = -1;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (ans != -1) continue;

        count[x]++;
        if (count[x] >= 3) {
            ans = x;
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
