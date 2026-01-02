#include <iostream>

using namespace std;

void solve() {
    long long n, a, b, c;
    cin >> n >> a >> b >> c;

    long long sum = a + b + c;
    long long full_cycles = n / sum;
    long long current_dist = full_cycles * sum;
    long long days = full_cycles * 3;


    long long rem = n - current_dist;

    if (rem > 0) {
        rem -= a;
        days++;
    }
    if (rem > 0) {
        rem -= b;
        days++;
    }
    if (rem > 0) {
        rem -= c;
        days++;
    }

    cout << days << endl;
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

