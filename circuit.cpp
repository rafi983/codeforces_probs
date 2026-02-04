#include <iostream>
#include <algorithm>

void solve() {
    int n;
    if (!(std::cin >> n)) return;
    int ones = 0;
    for (int i = 0; i < 2 * n; ++i) {
        int x;
        std::cin >> x;
        ones += x;
    }

    int zeros = 2 * n - ones;

    int min_on = ones % 2;

    int max_on = std::min(ones, zeros);

    std::cout << min_on << " " << max_on << "\n";
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
