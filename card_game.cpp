#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool aliceWins = false;
    vector<bool> bobHas(n + 1, false);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            bobHas[i + 1] = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            int card = i + 1;
            bool beaten = false;

            if (card == n) {
                if (bobHas[1]) beaten = true;
            } else if (card == 1) {

                for (int check = 2; check < n; ++check) {
                    if (bobHas[check]) {
                        beaten = true;
                        break;
                    }
                }
            } else {
                for (int check = card + 1; check <= n; ++check) {
                    if (bobHas[check]) {
                        beaten = true;
                        break;
                    }
                }
            }

            if (!beaten) {
                aliceWins = true;
                break;
            }
        }
    }

    cout << (aliceWins ? "Alice" : "Bob") << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
