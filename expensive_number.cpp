#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    string n;
    cin >> n;


    int cnt_zeros = 0;
    int max_len = 0;

    for (char c : n) {
        if (c == '0') {
            cnt_zeros++;
        } else {
            int current_len = cnt_zeros + 1;
            if (current_len > max_len) {
                max_len = current_len;
            }
        }
    }

    cout << n.length() - max_len << "\n";
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

