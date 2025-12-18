#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Solver {
    vector<long long> SumH, SumD;
    vector<long long> PrefH, SuffD;

    void init(int max_val) {
        SumH.assign(max_val + 2, 0);
        SumD.assign(max_val + 2, 0);
    }

    void add(int h, long long d) {
        SumH[h] += h * d;
        SumD[h] += d;
    }

    void build(int max_val) {
        PrefH.assign(max_val + 2, 0);
        SuffD.assign(max_val + 2, 0);

        for (int i = 1; i <= max_val; ++i) {
            PrefH[i] = PrefH[i-1] + SumH[i];
        }

        for (int i = max_val; i >= 1; --i) {
            SuffD[i] = SuffD[i+1] + SumD[i];
        }
    }

    long long query(int k) {
        if (k < 0) return 0;
        if (k >= (int)PrefH.size() - 1) {
             return PrefH.back();
        }
        return PrefH[k] + (long long)k * SuffD[k+1];
    }
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }

    Solver solverE, solverO;
    solverE.init(n);
    solverO.init(n);

    for (int i = 1; i < 2 * n; ++i) {
        long long d = a[i] - a[i-1];
        int h = min(i, 2 * n - i);

        if (i % 2 == 0) {
            solverE.add(h, d);
        } else {
            solverO.add(h, d);
        }
    }

    solverE.build(n);
    solverO.build(n);

    for (int k = 1; k <= n; ++k) {
        long long ans = 0;
        if (k % 2 != 0) { // Odd
            ans = solverE.query(k - 1) + solverO.query(k);
        } else { // Even
            ans = solverE.query(k) + solverO.query(k - 1);
        }
        cout << ans << (k == n ? "" : " ");
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

