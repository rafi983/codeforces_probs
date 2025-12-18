#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int k;
    long long x;
    if (!(cin >> k >> x)) return;

    long long S = 1LL << (k + 1);
    long long target = 1LL << k;

    if (x == target) {
        cout << 0 << endl;
        cout << endl;
        return;
    }

    vector<int> ops;
    long long curr = x;

    while (curr != target) {
        if ((curr << 1) < S) {
            ops.push_back(1);
            curr <<= 1;
        } else {
            ops.push_back(2);
            curr = (curr << 1) - S;
        }
    }

    cout << ops.size() << endl;
    reverse(ops.begin(), ops.end());
    for (int i = 0; i < ops.size(); ++i) {
        cout << ops[i] << (i == ops.size() - 1 ? "" : " ");
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
