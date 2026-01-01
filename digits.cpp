#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long n;
    int d;
    if (!(cin >> n >> d)) return;

    vector<int> res;
    res.push_back(1);

    // Check 3
    if (n >= 3 || d % 3 == 0) {
        res.push_back(3);
    }

    // Check 5
    if (d == 5) {
        res.push_back(5);
    }

    // Check 7
    if (n >= 3 || d == 7) {
        res.push_back(7);
    }

    // Check 9
    if (n >= 6 || (n >= 3 && d % 3 == 0) || (d == 9)) {
        res.push_back(9);
    }

    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << (i == res.size() - 1 ? "" : " ");
    }
    cout << "\n";
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

