#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    long long perimeter = 0;

    int x, y;
    cin >> x >> y;
    perimeter = 4LL * m;

    for (int i = 1; i < n; ++i) {
        cin >> x >> y;

        perimeter += 2LL * x + 2LL * y;
    }

    cout << perimeter << endl;
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

