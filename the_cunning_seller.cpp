#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;

        long long k = 0;
        long long pow3_k = 1;
        long long pow3_k_minus_1 = 0;

        unsigned long long total_cost = 0ULL;
        while (n > 0) {
            int digit = static_cast<int>(n % 3);
            if (digit != 0) {
                unsigned long long cost_k = 3ULL * (unsigned long long)pow3_k;
                if (k > 0) {
                    cost_k += (unsigned long long)k * (unsigned long long)pow3_k_minus_1;
                }
                total_cost += (unsigned long long)digit * cost_k;
            }
            n /= 3;
            pow3_k_minus_1 = pow3_k;
            pow3_k = pow3_k * 3LL;
            ++k;
        }

        cout << total_cost << '\n';
    }
    return 0;
}

