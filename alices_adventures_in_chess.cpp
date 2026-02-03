#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int x = 0, y = 0;

    for (int i = 0; i < 1000; ++i) {
        for (char c : s) {
            if (c == 'N') y++;
            else if (c == 'E') x++;
            else if (c == 'S') y--;
            else if (c == 'W') x--;

            if (x == a && y == b) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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
