#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int zeros_c0 = 0;
    int zeros_c1 = 0;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            if (a[i] == '0') zeros_c0++;
        } else {
            if (b[i] == '0') zeros_c0++;
        }
        if (i % 2 != 0) {
            if (a[i] == '0') zeros_c1++;
        } else {
            if (b[i] == '0') zeros_c1++;
        }
    }

    int req_c0 = (n + 1) / 2;
    int req_c1 = n / 2;

    if (zeros_c0 >= req_c0 && zeros_c1 >= req_c1) {
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
