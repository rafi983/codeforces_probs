#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Precomputed prefix sums of good numbers in [1, 210]
int pref[211];

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void precompute() {
    int count = 0;
    for (int i = 1; i <= 210; ++i) {
        // A number is good if it is not divisible by 2, 3, 5, 7.
        // This is equivalent to gcd(i, 210) == 1.
        if (gcd(i, 210) == 1) {
            count++;
        }
        pref[i] = count;
    }
}

long long calc(long long n) {
    if (n == 0) return 0;
    long long q = n / 210;
    int rem = n % 210;
    // There are 48 numbers coprime to 210 in every block of 210 numbers.
    return q * 48 + pref[rem];
}

void solve() {
    long long l, r;
    if (!(cin >> l >> r)) return;
    cout << calc(r) - calc(l - 1) << "\n";
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

