#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long k;
    if (!(cin >> n >> k)) {
        return 0;
    }

    vector<long long> h(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> h[i])) {
            return 0;
        }
    }

    sort(h.begin(), h.end());

    long long slices = 0;
    long long cur_cost = 0; /* cubes used in current slice */
    long long cumulative = 0; /* towers affected in current band */

    int i = n - 1;
    while (i >= 0) {
        long long height = h[i];
        int j = i;
        while (j >= 0 && h[j] == height) {
            --j;
        }
        cumulative += (long long)(i - j);
        if (j < 0) {
            break;
        }
        long long next_height = h[j];
        long long delta = height - next_height;
        while (delta > 0) {
            if (cur_cost == k) {
                ++slices;
                cur_cost = 0;
            }
            long long remaining = k - cur_cost;
            long long max_layers = remaining / cumulative;
            if (max_layers == 0) {
                ++slices;
                cur_cost = 0;
                continue;
            }
            long long take = delta < max_layers ? delta : max_layers;
            cur_cost += take * cumulative;
            delta -= take;
        }
        i = j;
    }

    if (cur_cost > 0) {
        ++slices;
    }

    cout << slices << endl;

    return 0;
}

