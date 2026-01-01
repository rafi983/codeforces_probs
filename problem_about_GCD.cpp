#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    long long l, r, G;
    if (!(cin >> l >> r >> G)) return;

    long long L_prime = (l + G - 1) / G;
    long long R_prime = r / G;

    if (L_prime > R_prime) {
        cout << "-1 -1\n";
        return;
    }

    for (long long gap = 0; gap <= R_prime - L_prime; ++gap) {
        long long len = (R_prime - L_prime) - gap;

        for (long long k = 0; k <= gap; ++k) {
            long long x = L_prime + k;
            long long y = x + len;

            if (gcd(x, y) == 1) {
                cout << x * G << " " << y * G << "\n";
                return;
            }
        }
    }

    cout << "-1 -1\n";
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

