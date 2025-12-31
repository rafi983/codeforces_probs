#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long l, r;
    if (!(cin >> l >> r)) return;

    long long x = l ^ r;
    int k = 63 - __builtin_clzll(x);

    long long a = (l | (1LL << k)) & ~((1LL << k) - 1);
    long long b = a - 1;
    long long c;

    if (b > l) {
        c = l;
    } else {
        c = r;
    }

    cout << a << " " << b << " " << c << endl;
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

