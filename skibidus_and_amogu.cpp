#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string w;
    cin >> w;
    if (w.length() >= 2) {
        w.pop_back(); // remove 's'
        w.pop_back(); // remove 'u'
        w += 'i';
    }
    cout << w << endl;
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

