#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<int> get_forbidden(const vector<int>& a, int n) {

    vector<int> s;
    s.reserve(2 * n + 1);
    for (int x : a) {
        s.push_back(0);
        s.push_back(x);
    }
    s.push_back(0);

    int m = s.size();
    vector<int> d(m);
    int l = 0, r = -1;
    for (int i = 0; i < m; ++i) {
        int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < m && s[i - k] == s[i + k]) {
            k++;
        }
        d[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }

    set<int> forbidden;


    for (int i = 0; i < m; ++i) {
        int rad = d[i] - 1;
        if (i + rad == m - 1) {

            int len = rad;

            if (n - len - 1 >= 0) {
                forbidden.insert(a[n - len - 1]);
            }
        }
    }
    return forbidden;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set<int> forbidden = get_forbidden(a, n);

    // Choose x1
    int x1 = 1;
    while (forbidden.count(x1)) {
        x1++;
    }

    cout << x1;

    int prev = x1;
    int prev2 = a[n-1]; // Last element of original array

    for (int i = 1; i < k; ++i) {
        int xi = 1;
        while (xi == prev || xi == prev2) {
            xi++;
        }
        cout << " " << xi;
        prev2 = prev;
        prev = xi;
    }
    cout << endl;
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

