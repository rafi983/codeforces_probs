#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int min_val = 10;
    int min_idx = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < min_val) {
            min_val = a[i];
            min_idx = i;
        }
    }

    a[min_idx]++;

    long long product = 1;
    for (int x : a) {
        product *= x;
    }
    cout << product << endl;
}

int main() {
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}
