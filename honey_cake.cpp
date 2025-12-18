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

int main() {
    long long w, h, d, n;
    if (cin >> w >> h >> d >> n) {
        long long a = gcd(n, w);
        n /= a;
        long long b = gcd(n, h);
        n /= b;
        long long c = n;

        if (d % c == 0) {
            cout << a - 1 << " " << b - 1 << " " << c - 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}

