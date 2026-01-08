#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void zaman() {
    int n;
    cin >> n;
    vector<int> a(n);
    int zero_count = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) zero_count++;
    }

    if (zero_count == 0) {
        cout << "Alice" << endl;
    } else {
        if (a[0] == 1 || a.back() == 1) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            zaman();
        }
    }
    return 0;
}
