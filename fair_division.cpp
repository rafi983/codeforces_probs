#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int ones = 0;
        int twos = 0;

        for (int i = 0; i < n; ++i) {
            int weight;
            cin >> weight;
            if (weight == 1) {
                ++ones;
            } else if (weight == 2) {
                ++twos;
            }
        }

        int total_weight = ones + 2 * twos;

        if (total_weight % 2 != 0) {
            cout << "NO\n";
            continue;
        }

        int half = total_weight / 2;
        int can_use_twos = min(twos, half / 2);
        int weight_from_twos = can_use_twos * 2;
        int remaining = half - weight_from_twos;

        if (remaining <= ones) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

