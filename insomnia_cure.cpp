#include <iostream>
using namespace std;

int main() {
    int k, l, m, n, d;
    if (!(cin >> k >> l >> m >> n >> d)) {
        return 0;
    }

    int damaged = 0;
    for (int dragon = 1; dragon <= d; dragon++) {
        if (dragon % k == 0 || dragon % l == 0 || dragon % m == 0 || dragon % n == 0) {
            damaged++;
        }
    }

    cout << damaged << endl;
    return 0;
}

