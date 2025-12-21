#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<pair<long long, long long>> anchors(n);
    long long min_neg_sum = 4000000000000000000LL; // min(-xi - yi)
    long long min_neg_diff = 4000000000000000000LL; // min(-xi + yi)

    for (int i = 0; i < n; ++i) {
        cin >> anchors[i].first >> anchors[i].second;
        long long xi = anchors[i].first;
        long long yi = anchors[i].second;
        if (-xi - yi < min_neg_sum) min_neg_sum = -xi - yi;
        if (-xi + yi < min_neg_diff) min_neg_diff = -xi + yi;
    }

    long long d;

    // Move U 2e9
    cout << "? U 1000000000" << endl;
    cin >> d; if (d == -1) exit(0);
    cout << "? U 1000000000" << endl;
    cin >> d; if (d == -1) exit(0);

    // Move R 2e9
    cout << "? R 1000000000" << endl;
    cin >> d; if (d == -1) exit(0);
    cout << "? R 1000000000" << endl;
    cin >> d; if (d == -1) exit(0);

    // Now at (X + 2e9, Y + 2e9)
    // d = X + Y + 4e9 + min(-xi - yi)
    long long sum_XY = d - 4000000000LL - min_neg_sum;

    // Move D 4e9
    cout << "? D 1000000000" << endl;
    cin >> d; if (d == -1) exit(0);
    cout << "? D 1000000000" << endl;
    cin >> d; if (d == -1) exit(0);
    cout << "? D 1000000000" << endl;
    cin >> d; if (d == -1) exit(0);
    cout << "? D 1000000000" << endl;
    cin >> d; if (d == -1) exit(0);

    // Now at (X + 2e9, Y - 2e9)
    // d = X - Y + 4e9 + min(-xi + yi)
    long long diff_XY = d - 4000000000LL - min_neg_diff;

    long long X = (sum_XY + diff_XY) / 2;
    long long Y = (sum_XY - diff_XY) / 2;

    cout << "! " << X << " " << Y << endl;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

