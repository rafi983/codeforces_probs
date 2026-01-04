#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long m, a, b, c;
    cin >> m >> a >> b >> c;

    long long seated_a = min(a, m);
    long long seated_b = min(b, m);

    long long remaining_seats = (2 * m) - seated_a - seated_b;
    long long seated_c = min(c, remaining_seats);

    cout << seated_a + seated_b + seated_c << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
