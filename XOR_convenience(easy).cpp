#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;


    vector<int> p(n + 1);
    vector<bool> used(n + 1, false);

    p[n] = 1;
    used[1] = true;

    for (int i = 2; i < n; ++i) {
        int val = i ^ 1;
        p[i] = val;
        used[val] = true;
    }

    for (int v = 1; v <= n; ++v) {
        if (!used[v]) {
            p[1] = v;
            break;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << p[i] << (i == n ? "" : " ");
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
