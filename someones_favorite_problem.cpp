#include <iostream>

using namespace std;

// Function to perform a query
bool query(int u, int v) {
    cout << "? " << u << " " << v << endl;
    int res;
    cin >> res;
    if (res == -1) {
        exit(0);
    }
    return res == 1;
}

void solve() {
    int n;
    cin >> n;

    int candidate = 1;
    for (int i = 2; i <= n; ++i) {
        // Ask if there is an edge from candidate to i
        if (query(candidate, i)) {

            candidate = i;
        } else {

        }
    }

    for (int i = 1; i <= n; ++i) {
        if (i == candidate) continue;

        if (query(candidate, i)) {
            cout << "! -1" << endl;
            return;
        }

        if (!query(i, candidate)) {
            cout << "! -1" << endl;
            return;
        }
    }

    cout << "! " << candidate << endl;
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
