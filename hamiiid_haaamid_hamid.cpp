#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, x;
    if (!(cin >> n >> x)) return;
    string s;
    cin >> s;

    int X = x - 1; // 0-based index of Hamid

    // Left side: 0 to X-1
    int L_len = X;
    int W_L = 0;
    int w_L = -1; // Nearest wall index
    for (int i = 0; i < X; ++i) {
        if (s[i] == '#') {
            W_L++;
            w_L = i; // Keep updating, last one is nearest
        }
    }

    // Right side: X+1 to n-1
    int R_len = n - 1 - X;
    int W_R = 0;
    int w_R = -1; // Nearest wall index
    for (int i = n - 1; i > X; --i) {
        if (s[i] == '#') {
            W_R++;
            w_R = i; // Keep updating, last one (smallest index) is nearest
        }
    }

    int Skip_L;
    if (w_L == -1) Skip_L = L_len;
    else Skip_L = (X - 1) - w_L;

    int Skip_R;
    if (w_R == -1) Skip_R = R_len;
    else Skip_R = w_R - (X + 1);

    int P_L = L_len + 1;
    int P_R = R_len + 1;

    int P_prime_L = P_L - Skip_L;
    int P_prime_R = P_R - Skip_R;

    if (W_L == 0 && W_R == 0) {
        cout << 1 << endl;
    } else if (W_L == 0) {
        cout << min(P_L, P_prime_R) << endl;
    } else if (W_R == 0) {
        cout << min(P_prime_L, P_R) << endl;
    } else {
        int opt1 = min(P_L, P_prime_R);
        int opt2 = min(P_prime_L, P_R);
        cout << max(opt1, opt2) << endl;
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

