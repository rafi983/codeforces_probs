#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    string s;
    cin >> s;

    string S = "0" + s;
    int transitions = 0;
    int c01 = 0;
    int c10 = 0;

    for (int i = 0; i < n; ++i) {
        if (S[i] != S[i+1]) {
            transitions++;
            if (S[i] == '0' && S[i+1] == '1') {
                c01++;
            } else {
                c10++;
            }
        }
    }

    int base_cost = n + transitions;
    int max_gain = 0;

    if (c01 >= 2 || c10 >= 2) {
        max_gain = 2;
    } else {
        if (S[n] == '0' && c01 > 0) {
            max_gain = 1;
        }
        if (S[n] == '1' && c10 > 0) {
            max_gain = 1;
        }
    }

    cout << base_cost - max_gain << endl;
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

