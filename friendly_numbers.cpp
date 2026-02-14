#include <iostream>
#include <algorithm>

using namespace std;

long long sum_digits(long long n) {
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve() {
    long long x;
    if (!(cin >> x)) return;
    if (x % 9 != 0) {
        cout << 0 << endl;
        return;
    }


    int count = 0;
    for (int k = 1; k <= 100; ++k) {
        long long y = x + k;
        if (sum_digits(y) == k) {
            count++;
        }
    }
    cout << count << endl;
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

