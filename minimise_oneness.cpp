#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;

    cout << "1";
    for(int i = 0; i < n - 1; ++i) {
        cout << "0";
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
