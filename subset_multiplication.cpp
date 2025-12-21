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
    cin >> n;
    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    long long L = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (b[i+1] % b[i] != 0) {
            long long g = gcd(b[i], b[i+1]);
            long long req = b[i] / g;
            L = lcm(L, req);
        }
    }
    cout << L << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
