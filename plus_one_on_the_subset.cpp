#include <iostream>
#include <climits>
using namespace std;

int main() {
    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        if (!(cin >> n)) return 0;

        long long mn = LLONG_MAX, mx = LLONG_MIN;
        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            if (x < mn) mn = x;
            if (x > mx) mx = x;
        }

        cout << mx - mn << endl;
    }

    return 0;
}

