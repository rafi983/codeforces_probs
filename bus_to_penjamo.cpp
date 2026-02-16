#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n, r;
    cin >> n >> r;
    vector<int> a(n);
    int total_people = 0;
    int pairs = 0;
    int singles = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_people += a[i];
        pairs += a[i] / 2;
        singles += a[i] % 2;
    }

    int happy_count = pairs * 2;
    int rows_used = pairs;
    int rows_left = r - rows_used;

    int m_min = 0;
    if (singles > rows_left) {
        m_min = singles - rows_left;
    }
    int extra_happy = singles - 2 * m_min;

    cout << happy_count + extra_happy << endl;
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

