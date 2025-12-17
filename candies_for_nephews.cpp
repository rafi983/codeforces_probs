#include <iostream>

using namespace std;

void solve() {
    int n;
    if (cin >> n) {
        cout << (3 - n % 3) % 3 << endl;
    }
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

