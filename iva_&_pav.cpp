#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
const int LOGN = 19;

int st[MAXN][LOGN];
int logs[MAXN];

void precomputeLogs() {
    logs[1] = 0;
    for (int i = 2; i < MAXN; i++)
        logs[i] = logs[i/2] + 1;
}

void build(const vector<int>& a, int n) {
    for (int i = 0; i < n; i++)
        st[i][0] = a[i];

    for (int j = 1; j < LOGN; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = st[i][j-1] & st[i + (1 << (j-1))][j-1];
        }
    }
}

int query(int L, int R) {
    int j = logs[R - L + 1];
    return st[L][j] & st[R - (1 << j) + 1][j];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    build(a, n);

    int q;
    cin >> q;
    while (q--) {
        int l, k;
        cin >> l >> k;
        l--;

        if (a[l] < k) {
            cout << -1 << " ";
            continue;
        }

        int low = l, high = n - 1;
        int ans = l;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (query(l, mid) >= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans + 1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomputeLogs();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

