#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        counts[c]++;
    }

    int cntS = 0;
    int cntM = 0;
    for (auto const& [color, count] : counts) {
        if (count == 1) {
            cntS++;
        } else {
            cntM++;
        }
    }

    int score = ((cntS + 1) / 2) * 2 + cntM;
    cout << score << endl;
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
