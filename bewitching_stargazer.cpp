#include <iostream>

using namespace std;

struct Result {
    long long sum;
    long long count;
};

Result solve_recursive(long long n, long long k) {
    if (n < k) {
        return {0, 0};
    }

    long long half_n = n / 2;
    Result res = solve_recursive(half_n, k);

    if (n % 2 == 0) {
        long long total_sum = 2 * res.sum + res.count * half_n;
        long long total_count = 2 * res.count;
        return {total_sum, total_count};
    } else {

        long long m = (n + 1) / 2;

        long long total_sum = m + 2 * res.sum + res.count * m;
        long long total_count = 1 + 2 * res.count;
        return {total_sum, total_count};
    }
}

void solve() {
    long long n, k;
    cin >> n >> k;
    Result ans = solve_recursive(n, k);
    cout << ans.sum << "\n";
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

