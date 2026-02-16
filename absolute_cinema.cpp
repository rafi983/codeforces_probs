#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }

    if (n == 2) {

        cout << f[1] << " " << f[0] << endl;

        return;
    }

    long long sum_a = (f[0] + f[n - 1]) / (n - 1);
    vector<long long> a(n);

    a[0] = (sum_a + f[1] - f[0]) / 2;

    a[n - 1] = (sum_a - f[n - 1] + f[n - 2]) / 2;

    for (int i = 1; i < n - 1; ++i) {
        a[i] = (f[i - 1] - 2 * f[i] + f[i + 1]) / 2;
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
