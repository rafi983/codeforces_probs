#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    long long s;
    if (!(cin >> n >> s)) return;

    int potted_count = 0;
    for (int i = 0; i < n; ++i) {
        int dx, dy;
        long long x, y;
        cin >> dx >> dy >> x >> y;

        if (dx == dy) {
            if (x == y) {
                potted_count++;
            }
        }
        else {
            if (x + y == s) {
                potted_count++;
            }
        }
    }
    cout << potted_count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

