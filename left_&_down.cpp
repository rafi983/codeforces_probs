#include <iostream>
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
    long long a, b, k;
    if (!(cin >> a >> b >> k)) return;

    long long g = gcd(a, b);
    long long max_val = max(a, b);
    // Calculate ceil(max_val / k)
    long long req = (max_val + k - 1) / k;

    if (g >= req) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
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
