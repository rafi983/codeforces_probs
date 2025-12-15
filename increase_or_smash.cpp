#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    set<int> distinct_elements;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        distinct_elements.insert(x);
    }
    int k = distinct_elements.size();
    cout << 2 * k - 1 << endl;
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

