#include <iostream>
#include <vector>
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

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int limit = min(n, 60);
        bool found = false;
        int x = -1;
        int y = -1;

        for (int i = 0; i < limit && !found; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((a[j] % a[i]) % 2 == 0) {
                    x = a[i];
                    y = a[j];
                    found = true;
                    break;
                }
            }
        }

        if (found) {
            cout << x << ' ' << y << '\n';
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}

