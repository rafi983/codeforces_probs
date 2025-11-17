#include <iostream>
#include <vector>
using namespace std;

constexpr long long MOD = (1LL << 30);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    int max_val = a * b * c;
    vector<int> divisors(max_val + 1, 0);

    // Compute number of divisors for each number using sieve-like approach
    for (int i = 1; i <= max_val; ++i) {
        for (int j = i; j <= max_val; j += i) {
            ++divisors[j];
        }
    }

    long long sum = 0;
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            for (int k = 1; k <= c; ++k) {
                sum += divisors[i * j * k];
            }
        }
    }

    cout << sum % MOD << '\n';

    return 0;
}

