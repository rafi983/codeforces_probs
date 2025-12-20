#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (k % 2 != 0) {

        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 != 0) {
                a[i] += k;
            }
        }
    } else {

        for (int i = 0; i < n; ++i) {
            long long m = a[i] % (k + 1);
            a[i] += m * k;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
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

