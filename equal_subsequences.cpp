#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cout << '1';
    }
    for (int i = 0; i < n - k; ++i) {
        cout << '0';
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

