#include <iostream>
#include <vector>
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

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> p(n), s(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    for (int i = 0; i < n; ++i) cin >> s[i];

    if (p[n-1] != s[0]) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (p[i] % p[i+1] != 0) {
            cout << "NO\n";
            return;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        if (s[i+1] % s[i] != 0) {
            cout << "NO\n";
            return;
        }
    }

    if (n > 1) {
        if (gcd(p[0], s[1]) != s[0]) {
            cout << "NO\n";
            return;
        }
        if (gcd(p[n-2], s[n-1]) != p[n-1]) {
            cout << "NO\n";
            return;
        }
    }

    for (int i = 1; i < n - 1; ++i) {
        long long l = lcm(p[i], s[i]);
        if (gcd(p[i-1], l) != p[i]) {
            cout << "NO\n";
            return;
        }
        if (gcd(l, s[i+1]) != s[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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

