#include <iostream>
#include <numeric>
#include <algorithm>

int gcd(int a, int b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

void solve() {
    int l, a, b;
    std::cin >> l >> a >> b;

    int g = gcd(l, b);
    int r = a % g;

    int target = l - 1;
    int rem_target = target % g;

    int diff = (rem_target - r + g) % g;
    int ans = target - diff;

    std::cout << ans << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    if (std::cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
