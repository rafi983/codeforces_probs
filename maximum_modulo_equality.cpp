#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
const int K = 19; // 2^18 > 200000

long long st[K][MAXN];
int lg[MAXN];

long long gcd_val(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void precompute() {
    lg[1] = 0;
    for (int i = 2; i < MAXN; i++)
        lg[i] = lg[i / 2] + 1;
}

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m = n - 1;
    if (m > 0) {
        for (int i = 0; i < m; ++i) {
            st[0][i] = abs(a[i + 1] - a[i]);
        }

        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= m; i++) {
                st[j][i] = gcd_val(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << 0 << " ";
        } else {
            int L = l - 1;
            int R = r - 2;

            int j = lg[R - L + 1];
            long long g = gcd_val(st[j][L], st[j][R - (1 << j) + 1]);
            cout << g << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

