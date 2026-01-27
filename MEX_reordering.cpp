#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        counts[val]++;
    }

    if (counts[0] == 0) {

        cout << "NO" << endl;
    } else {
        if (counts[1] == 0) {

            if (counts[0] == 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {

            cout << "YES" << endl;
        }
    }
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
