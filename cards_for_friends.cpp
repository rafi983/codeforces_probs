#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int w, h, n;
        cin >> w >> h >> n;

        int pieces = 1;
        while (w % 2 == 0) {
            pieces *= 2;
            w /= 2;
        }

        while (h % 2 == 0) {
            pieces *= 2;
            h /= 2;
        }

        if (pieces >= n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

