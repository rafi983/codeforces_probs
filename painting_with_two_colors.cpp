#include <iostream>

using namespace std;

void solve() {
    int n, a, b;
    if (!(cin >> n >> a >> b)) return;


    if ((n - b) % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

    if (a <= b) {
        cout << "YES" << endl;
        return;
    }

    if ((n - a) % 2 == 0) {
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

