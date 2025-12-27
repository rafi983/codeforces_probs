#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    vector<int> p;
    int first_zero_idx = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            if (first_zero_idx == -1) {
                first_zero_idx = i;
            }
        } else {
            p.push_back(a[i]);
        }
    }

    if (first_zero_idx == -1) {
        cout << p.size() << "\n";
        return;
    }

    // k is the number of positive elements before the first zero
    int k = 0;
    for (int i = 0; i < first_zero_idx; ++i) {
        if (a[i] != 0) {
            k++;
        }
    }

    int m = p.size();
    // M[i] will store mex({0, p[i], ..., p[m-1]})
    vector<int> M(m + 2);
    vector<int> cnt(n + 2, 0);

    cnt[0]++;
    int cur_mex = 1;
    while (cur_mex <= n + 1 && cnt[cur_mex]) cur_mex++;
    M[m] = cur_mex;

    for (int i = m - 1; i >= 0; --i) {
        if (p[i] <= n + 1) {
            cnt[p[i]]++;
        }
        while (cur_mex <= n + 1 && cnt[cur_mex]) cur_mex++;
        M[i] = cur_mex;
    }

    bool ok = true;
    int min_val = 2000000000;
    for (int i = 1; i <= k; ++i) {
        min_val = min(min_val, p[i-1]);
        if (min_val < M[i]) {
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << m + 1 << "\n";
    } else {
        cout << m << "\n";
    }
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

