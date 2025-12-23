#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> b(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    vector<long long> O;
    vector<long long> E_prime;

    // E' gets first n-1 elements
    for (int i = 0; i < n - 1; ++i) {
        E_prime.push_back(b[i]);
    }
    // O gets remaining n+1 elements
    for (int i = n - 1; i < 2 * n; ++i) {
        O.push_back(b[i]);
    }

    long long sum_O = 0;
    for (long long val : O) sum_O += val;

    long long sum_E_prime = 0;
    for (long long val : E_prime) sum_E_prime += val;

    long long x = sum_O - sum_E_prime;

    cout << O[0];
    for (int i = 0; i < n - 1; ++i) {
        cout << " " << E_prime[i] << " " << O[i + 1];
    }
    cout << " " << x << " " << O[n] << "\n";
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
