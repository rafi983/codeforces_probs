#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        if (!(cin >> n)) n = 0;

        int a[55];
        for (int i = 0; i < n; ++i) {
            if (!(cin >> a[i])) a[i] = 0;
        }

        sort(a, a + n);

        bool ok = true;
        for (int i = 1; i < n; ++i) {
            if (a[i] - a[i-1] > 1) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}

