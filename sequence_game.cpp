#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        long long mn = 0, mx = 0, val;
        for (int i = 0; i < n; ++i) {
            cin >> val;
            if (i == 0) {
                mn = mx = val;
            } else {
                if (val < mn) mn = val;
                if (val > mx) mx = val;
            }
        }

        long long x;
        cin >> x;

        if (mn <= x && x <= mx) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

