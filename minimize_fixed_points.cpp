#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
int spf[MAXN];

void sieve() {
    iota(spf, spf + MAXN, 0);
    for (int i = 2; i * i < MAXN; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> p(n + 1);
    vector<vector<int>> buckets(n + 1);
    vector<bool> stolen(n + 1, false);

    p[1] = 1;

    for (int i = 2; i <= n; ++i) {
        if (spf[i] == i && i > n / 2) {
            p[i] = i;
        } else {
            buckets[spf[i]].push_back(i);
        }
    }

    for (int i = 3; i <= n / 2; ++i) {
        if (spf[i] == i) {
            if (buckets[i].empty()) continue;

            if (buckets[i].size() == 1) {
                int val = 2 * i;
                stolen[val] = true;
                buckets[i].push_back(val);
            }

            int k = buckets[i].size();
            for (int j = 0; j < k; ++j) {
                p[buckets[i][j]] = buckets[i][(j + 1) % k];
            }
        }
    }

    vector<int> b2;
    for (int x : buckets[2]) {
        if (!stolen[x]) {
            b2.push_back(x);
        }
    }

    if (!b2.empty()) {
        int k = b2.size();
        for (int j = 0; j < k; ++j) {
            p[b2[j]] = b2[(j + 1) % k];
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
    sieve();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

