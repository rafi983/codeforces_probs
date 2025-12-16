#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        counts[x]++;
    }

    int max_len = 0;
    for (int k = 1; k <= n; ++k) {
        int distinct_elements_count = 0;
        for (auto const& [val, count] : counts) {
            if (count >= k) {
                distinct_elements_count++;
            }
        }
        if (distinct_elements_count * k > max_len) {
            max_len = distinct_elements_count * k;
        }
    }
    cout << max_len << endl;
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

