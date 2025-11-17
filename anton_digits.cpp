#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;

    long long count256 = min({k2, k5, k6});

    k2 -= count256;
    k5 -= count256;
    k6 -= count256;

    long long count32 = min(k2, k3);

    long long sum = count256 * 256 + count32 * 32;
    cout << sum << '\n';

    return 0;
}

