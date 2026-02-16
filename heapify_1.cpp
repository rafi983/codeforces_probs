#include <iostream>
#include <vector>

using namespace std;

int get_odd_part(int x) {
    if (x == 0) return 0;
    return x >> __builtin_ctz(x);
}

void solve() {
    int n;
    cin >> n;


    bool possible = true;
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;

        if (possible) {
            if (get_odd_part(i) != get_odd_part(val)) {
                possible = false;
            }
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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
